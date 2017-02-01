#include <string>
#include <iostream>

#pragma once

class bruch {
	// Zugriffsspezifizierer
	public : 
		// default heißt wird vom compiler erzeugt
		bruch() = default;
		// ohne default heißt muss man selber erstellen
		// bruch()
		// 1 ist default wert geht nicht nur bei konstruktoren
		bruch(int zaehler, int nenner = 1); 
		bruch(int zaehler, int nenner, int color);

		// Move Konstruktor - Verschiebekonstruktor
		bruch(const bruch &&b);
		// kopierkonstruktor
		bruch(const bruch &b);
		~bruch();
		int zaehler() const;
		int nenner() const;
		void zaehler(int zaehler);
		void nenner(int nenner);

		explicit operator bool() const;
		explicit operator double() const;
		bruch operator-(const bruch &b1);
		// Zuweisungsoperator
		bruch &operator=(const bruch &b1);
		// Verschiebezuweisungsoperator
		bruch &operator=(const bruch &&b1);

		// tauscht inhalte mit b 
		void swap(bruch &b);

		/**
		 * Alle Unären Operatoren kommen in klasse ~, -, +
		 * += -= *= usw kommen in klasse
		 * -> [] () = kommen in klasse
		 *  Alle anderen sind freie Funktion +, -, *, /, <<, >>, etc
		 *  werden als freie Funktionen implementiert
		 */
		virtual void test();
	// Zugriffsspezifizierer
	private : 
		int m_zaehler, m_nenner;
		int color;
		const int serial_nr;
		std::string str;

	friend std::ostream &operator<<(std::ostream &os, const bruch &b);
};

// bruch2 eine abgeleitete klasse und bruch eine basisklasse
class bruch2 : public bruch {
	public :
	bruch2() : bruch(1) {
		std::cout << __PRETTY_FUNCTION__ << std::endl;
	}
	virtual void test();
	
};

class drawable {
	// mit = 0 signalisiert man dass es sich um eine rein-virtuelle methode handelt;
	// schnittstelle braucht definitiv einen konstruktor
	public:
	drawable() = default; 
	virtual void draw() = 0;
};

class rechteck : public drawable {
	public:	
	virtual void draw() {
		std::cout << "Zeichne Rechteck" << std::endl;
	}

	virtual ~rechteck() {

	}
};

class dreieck : public drawable {
	public:	
	virtual void draw() {
		std::cout << "Zeichne Dreieck" << std::endl;
	}

	virtual ~dreieck() {

	}
};


// benutzt elementfunktion swap von bruch wird überladen
/*void swap(bruch &b1, bruch &b2) {
	b1.swap(b2);
}*/

bruch operator+(const bruch &b1, const bruch &b2);

extern bruch bru;
