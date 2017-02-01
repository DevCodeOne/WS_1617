// Für smartpointer
#include <memory>
#include <array>
#include <vector>

#include "Bruch.h"

using namespace bruchrechnung;

// Globale Variable wird zuerst initialisiert
bruch global(2);
// Dann werden die Übersetzungseinheitglobalen Variablen initialisiert
static bruch static_global(3);
// Sie werden auch in umgekehrter Reihenfolge wieder über den Destruktor
// zerstört

int main() {

    bruch b(5, 2);
    bruch b2(3, 5);
    bruch b3(10, 4);

    std::cout << "b : " << b << std::endl;
    std::cout << "b2 : " << b2 << std::endl;
    std::cout << "b3 : " << b3 << std::endl;
    std::cout << "b + b2 : " << b + b2 << std::endl;
    std::cout << "b - b2 : " << b - b2 << std::endl;
    std::cout << "b * b2 : " << b * b2 << std::endl;
    std::cout << "b / b2 : " << b / b2 << std::endl;
    std::cout << "-b : " << -b << std::endl;
    std::cout << "+b : " << +b << std::endl;
    std::cout << "b == b2 : " << (b == b2) << std::endl;
    std::cout << "b < b2 : " << (b < b2) << std::endl;
    std::cout << "b > b2 : " << (b > b2) << std::endl;
    std::cout << "b > b3 : " << (b > b3) << std::endl;
    std::cout << "b < b3 : " << (b < b3) << std::endl;
    std::cout << "b == b3 : " << (b == b3) << std::endl;

    // Zugriff auf statische Klassenvariable
    std::cout << "Bruch class_id : " << bruch::class_id << std::endl;

    // Automatische Typinferenz
    auto b4 = b3;
    decltype(b3) b5 = b3;

    // Rohes Array vom Typ Bruch auf Stack erzeugt kein manuelles löschen
    // nötig, Destruktor wird am Ende der Methode automatisch aufgerufen
    bruch arr[10];
    // Hier allerdings muss der Speicher manuell wieder freigegeben werden
    bruch *arr2 = new bruch[10];
    delete [] arr2;

    // Hier noch einmal nur mit Pointer, um den Unterschied bei der delete-
    // Anweisung zu sehen
    bruch *ptr = new bruch(5);
    delete ptr;

    // Anders als bei Rohen Zeigern muss bei Smartpointern nicht explizit
    // der Speicher wieder freigegeben werden
    std::unique_ptr<bruch> ptr1 = std::make_unique<bruch>(5);
    // Ist äquivalent zu
    std::unique_ptr<bruch> ptr2(new bruch(5));

    // Zugriff auf eine Elementfunktion über einen Pointer
    std::cout << ptr2->nenner() << std::endl;
    // Ist äquivalent zu
    std::cout << (*ptr2).nenner() << std::endl;

    // Auch Arrays können über Smartpointer verwaltet werden :
    // Hier ein Array mit 5 Elementen vom Typ bruch
    std::unique_ptr<bruch[]> arr3 = std::make_unique<bruch[]>(5);

    // Es gibt noch einen weiteren Typ von Smartpointer und zwar den
    // shared_ptr (Es gibt noch einen, dieser betrachte ich jetz hier aber
    // nicht mehr
    std::shared_ptr<bruch> ptr3 = std::make_shared<bruch>(5);
    // Anders als bei den unique_ptr können mehrere shared_ptr auf ein
    // Objekt zeigen, denn unique_ptr sagen aus, dass sie die alleinigen
    // Besitzer dieses Objektes sind
    std::shared_ptr<bruch> ptr4 = ptr3;
    // Nicht erlaubt :
    // ptr1 = ptr2;
    // Allerdings kann die Ownership verschoben werden
    ptr1 = std::move(ptr2);
    // Achtung : Man kann über ptr.get() den zugehörigen Rohen Pointer wieder
    // erhalten, darüber sollte man keinesfalls einen weiteren Smartpointer
    // initialisieren, das gibt Probleme !

    // Statt den Rohen Arrays die ebenfalls viele Nachteile haben, sollte man
    // stattdessen bei Arrays bei denen die Größe feststeht std::array
    // bentutzen und bei wachsenden std::vector jeweils
    std::array<int, 5> arr4 = {1, 2, 2, 4, 5};
    std::array<int, 5> arr5 = {1, 3, 3, 4, 5};

    // Nun enthält arr4 dieselben Werte wie arr5, trotzdem sind sie weiterhin
    // zwei verschiedene Objekte
    arr4 = arr5;

    // Bei Rohen Arrays kommt es dabei aber zu Problemen
    int arr6[5] = {1, 2, 2, 4, 5};
    int arr7[5] = {1, 3, 3, 4, 5};

    // Das funktioniert nicht
    // arr6 = arr7;

    // Kleine Übersicht über std::vector
    std::vector<bruch> vec = {b, b2, b3};

    // push_back fügt hinten Objekte an
    // Sind nur Beispiele sieht in echt vielleicht anders aus
    // [b][b2][b3][] Size : 3, Capacity : 4
    vec.push_back(b);
    // [b][b2][b3][b] Size : 4, Capacity : 4
    vec.push_back(b2);
    // Kapazität ist erreicht Speicher muss neu allokiert werden und Werte
    // müssen kopiert werden
    // [b][b2][b3][b][b2][][][] Size 5, Capacity : 8
    std::cout << vec.size() << std::endl;
    std::cout << vec.capacity() << std::endl;
    // Auf Element i zugreifen
    std::cout << vec[1] << std::endl;
    // Letztes Element runterholen std::vector funktioniert im Prinzip
    // wie ein Stack
    vec.pop_back();

    // Verwendung der Schnittstelle decimal_number
    for (decimal_number &b : vec) {
        std::cout << (double) b << std::endl;
    }

    if (b) {
        std::cout << "Bruch b ist gültig" << std::endl;
    }

    // C-Strings werden nur bis \0 ausgewertet, deswegen wird Hello ausgegeben
    // wenn man str ausgibt
    const char *str = "Hello\0Welt";
    std::cout << str << std::endl;
    // Bei C-Strings wird auch immer angenommen, dass der String mit \0 beendet
    // wird, ist dies nicht der Fall kann es zu einem Speicherleck o.ä. kommen.
    // Deswegen std::string benutzen, die diese Schwäche nicht haben, diese
    // werden aber mit C-Strings initialisiert.
    std::string str2(str);

    // Das Konkatenieren von Strings funktioniert auch nur mit dem std::string
    // mit normalen C-Strings wird das nicht funktionieren.
    str2 += "Test";

    return 0;
}
