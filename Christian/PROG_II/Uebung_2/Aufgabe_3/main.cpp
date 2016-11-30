#include <iostream>

#include <cstdlib>

#include "complexnumber.h"

using std::cout; 
using std::endl;

int main() {
	complexnumber_constructor nbr1{};
	complexnumber_in_class_equal nbr2;
	complexnumber_in_class_braces nbr3;

	cout << "Realanteil : " << nbr1.get_real() << " Imaginäranteil : " << nbr1.get_imaginary() << endl;
	cout << "Realanteil : " << nbr2.get_real() << " Imaginäranteil : " << nbr2.get_imaginary() << endl;
	cout << "Realanteil : " << nbr3.get_real() << " Imaginäranteil : " << nbr3.get_imaginary() << endl;

	/*
	 * Weil wir keinen Konstruktor definiert haben wird der default Konstruktor verwendet 
	 * d.h. die Member in der Klasse werden default initialisiert
	 * Außerdem sind die Variablen public weswegen der Nutzer direkt auf die Variablen 
	 * zugreifen kann und sie damit auch verändern kann, was nicht gewünscht ist.
	 */

	return EXIT_SUCCESS;
}
