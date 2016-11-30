#include <iostream>

#include <cstdlib>

#include "complexnumber.h"

using std::cout; 
using std::endl;

int main() {
	complexnumber nbr1;
	complexnumber nbr2;

	cout << "Realanteil : " << nbr1.m_real << " Imaginäranteil : " << nbr1.m_imaginary << endl;
	cout << "Realanteil : " << nbr2.m_real << " Imaginäranteil : " << nbr2.m_imaginary << endl;

	/*
	 * Weil wir keinen Konstruktor definiert haben wird der default Konstruktor verwendet 
	 * d.h. die Member in der Klasse werden default initialisiert
	 * Außerdem sind die Variablen public weswegen der Nutzer direkt auf die Variablen 
	 * zugreifen kann und sie damit auch verändern kann, was nicht gewünscht ist.
	 */

	return EXIT_SUCCESS;
}
