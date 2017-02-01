#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <memory>

#include "Bruch.h"

// globale variablen das ist das bru von bruch.h
bruch bru(2);

// Übersetzungseinheit global nur in dieser source datei sichtbar
static int i = 5;

bruch operator+(const bruch &b1, const bruch &b2) {
	bruch result(0); // 0 / 1
	result.nenner(b1.nenner() * b2.nenner());
	result.zaehler(b2.nenner() * b1.zaehler() + b1.nenner() * b2.zaehler());
	return result;
}

bruch bruch::operator-(const bruch &b1) {
	bruch result(0);
	result.nenner(b1.nenner());
	result.zaehler(-b1.zaehler());
	return result;
}

// Kopierzuweisungsoperator
bruch &bruch::operator=(const bruch &b1) {
	m_zaehler = b1.zaehler();
	m_nenner = b1.nenner();
	return *this;
}

int bruch::zaehler() const {
	// this zeiger
	return this->m_zaehler;
}

int bruch::nenner() const {
	return m_nenner;
}

void bruch::zaehler(int zaehler) {
	m_zaehler = zaehler;
}

void bruch::nenner(int nenner) {
	m_nenner = nenner;
}

bruch::operator bool() const {
	return m_nenner != 0;
}

// Cast Operator
bruch::operator double() const {
	return m_zaehler / (double) m_nenner;
}

std::ostream &operator<<(std::ostream &os, const bruch &b) {
	os << b.m_zaehler << " / " << b.m_nenner;
	return os;
}

// Typumwandlungskonstruktor
bruch::bruch(int zaehler, int nenner) : m_zaehler(zaehler),
	m_nenner(nenner), serial_nr(1) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

bruch::bruch(const bruch &b1) : bruch(b1.zaehler(), b1.zaehler()) {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

// Konstruktor delegation - aufrufen eines anderen konstruktors, um objekt
// zu initialisieren (das hinter dem bruch)
bruch::bruch(int zaehler, int nenner, int color) : bruch(zaehler, nenner) {
	color = color;
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

bruch::~bruch() {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
}

void bruch2::test() {
	std::cout << "Abgeleitet Bruch2" << std::endl;
}

void bruch::test() {
	std::cout << "Basis Bruch" << std::endl;
}

// b wird am ende zerstört b2 nicht, b2 muss manuell mit delete freigegeben werden
bruch *foo() {
	bruch b(5);
	bruch *b2 = new bruch(5);

	return b2;
}

void swap();
void move(); // move baut auf swap auf
void copy();

int main(int argc, char **argv) {

	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << std::endl;
	}

	for (int i = 0; i < argc; i++) {
		std::cout << (const char *) *(argv+i) << std::endl;
	}

	// [][][] -----> [][][] -------> [][][]
	// alle objekte implementieren die schnittstelle drawable und haben 
	// damit die methode draw()
	rechteck d;
	dreieck r;
	rechteck d2;

	std::vector<drawable *> drawcalls;

	drawcalls.push_back(&d);
	drawcalls.push_back(&r);
	drawcalls.push_back(&d2);

	for (drawable *d : drawcalls) {
		d->draw();
	}


	// virtuelle funtkionen
	bruch2 bru3;
	bruch &br = bru3;

	// obwohl typ bruch wird funktion von bruch2 aufgerufen
	br.test();

	// Automatische Typinferenz
	
	auto autoi = 5;
	int test = 10;
	decltype(test) t = 5;

	int i = 42;
	int k = 1337;
	int *l = &i;

	// nur pointer man kennt die größe
	int *arr = new int[10];
	int *arr3 = new int[20];

	//arr3 zeig arr
	arr3 = arr;
	// bei array muss man delete []
	delete [] arr;

	std::array<int, 5> arr2;
	std::array<int, 5> arr4;

	arr2 = arr4;

	{
		std::cout << i << std::endl;
		int i = 20;
		// i wird überdeckt
		std::cout << i << std::endl;
		std::unique_ptr<bruch> b = std::make_unique<bruch>(5);
		std::shared_ptr<bruch> b3 = std::make_shared<bruch>(10);
		// wird zu shared_ptr weil das aus b3 ersichtlich ist um welchen typ es sich handelt
		auto b4 = b3;
		// nicht machen denn wenn b3 und b4 gelöscht werden
		// wird das objekt auch gelöscht obwohl b6 noch darauf zeigt
		// da der zugriffscounter nicht erhört worden ist
		//std::shared_ptr<bruch> b6 = std::shared_ptr<bruch>(b4.get());
		bruch *b5 = new bruch(5);
	}

	// das Objekt auf das b2 zeigt ist immer noch verhanden aber nicht erreichbar
	// das Object auf das b zeigt ist zerstört

	std::cout << *l << std::endl;

	// Intern Hello\ World\0 müssen mit \0 beendet
	const char *c_str = "Hello\0World\0Test";
	std::string str = "Hello ";
	str += "Test";

	std::cout << c_str << ", " << c_str + 6  << ", " << c_str + 12 << std::endl;
	std::cout << str << std::endl;

	{
		{
			bruch *b2 = foo();
			std::cout << b2 << std::endl;
			delete b2;
		}

		bruch b(5, 2, 5);
		bruch b2(2, 5, 0);

		bruch b3 = b + b2;
		bruch b4(5);

		// in vector vec sind b3 und b4 aber nur kopien
		std::vector<bruch> vec = {b3, b4};
		// nur b3, b4, b
		vec.push_back(b);
		// nur b3, b4, b, b2 (wird am ende angefügt, wie ein stack)
		vec.push_back(b2);
		// nach dem pop b3, b4 und b
		vec.pop_back();
		// gibt 3 zurück
		vec.size();
		// zugriff aufs erste element wie bei array
		vec[0];

		// [][] size = 0 capacity = 2
		// [1][] size = 1 capacity = 2
		// [1][2] size = 2 capacity = 2
		// der speicher wird komplett neu angelegt, alle bisherigen daten werden
		// wieder dorthin kopiert
		// 1. schritt neue size wäre größer wie capacity -> neuer speicher
		// [][][][] 4 Speichergrößen anlegen
		// 2. Schritt kopieren der alten werte
		// 3. Freigeben des alten speichers
		// 4. hinzufügen des letzten elementes
		// [1][2][3][] size = 3 capacity = 4

		// Verkettung über =
		((b2 = b3) = b4) = b;

		// bruch wird in bool
		if ((double) b) {
			std::cout << "bruch is gültig" << std::endl;
		}
		std::cout << b << " " << std::endl;

		std::cout << b3 << " " << std::endl;
	}
} // ab hier destruktor von b
