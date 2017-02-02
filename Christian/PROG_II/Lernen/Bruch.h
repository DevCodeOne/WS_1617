#pragma once

#include <iostream>
#include <string>

namespace bruchrechnung {
	// Schnittstelle
	class decimal_number {
		public:
			virtual ~decimal_number() = default;
			virtual explicit operator double() const = 0;
	};

	// Schnittstelle
	class evaluable {
		public:
			virtual ~evaluable() = default;
			virtual explicit operator bool() const = 0;
	};

	class bruch final : public decimal_number, public evaluable {
		public:
			// Defaultkonstruktor
			bruch();
			// Typumwandlungskonstruktor weil Konstruktor mit nur einem
			// benötigten Wert
			bruch(int zaehler, int nenner = 1);
			// Kopierkonstruktor
			bruch(const bruch &b);
			// Verschiebekonstruktor
			bruch(bruch &&b);
			// Destruktor
			~bruch() = default;

			// Typumwandlungsoperatoren
			explicit operator bool() const override;
			explicit operator double() const override;
			// Unäre Operatoren
			bruch operator-() const;
			bruch operator+() const;
			// Kopierzuweisungsoperator
			bruch &operator=(const bruch &b);
			// Verschiebezuweisungsoperator
			bruch &operator=(bruch &&b);
			// Verschiedene Zuweisungsoperatoren mit Rechnung
			bruch &operator+=(const bruch &b);
			bruch &operator-=(const bruch &b);
			bruch &operator*=(const bruch &b);
			bruch &operator/=(const bruch &b);

			// Swap Methode vertauscht die Inhalte der beiden Objekte
			void swap(bruch &b);

			// Observer
			int nenner() const;
			int zaehler() const;
			// Mutatoren
			void nenner(int nenner);
			void zaehler(int zaehler);

			// Statische Klassenvariable muss außerhalb der Klasse angelegt
			// werden
			static const int class_id;
		private:
			// Member
			int m_nenner;
			int m_zaehler;

			// Binäre Operatoren, die als freie Funktionen implementiert werden
			// sollen
			friend std::ostream &operator<<(std::ostream &os, const bruch &b);
			friend bool operator==(const bruch &b1, const bruch &b2);
			friend bool operator!=(const bruch &b1, const bruch &b2);
			friend bool operator<(const bruch &b1, const bruch &b2);
			friend bool operator>(const bruch &b1, const bruch &b2);
			friend bool operator<=(const bruch &b1, const bruch &b2);
			friend bool operator>=(const bruch &b1, const bruch &b2);
			friend bruch operator+(const bruch &b1, const bruch &b2);
			friend bruch operator-(const bruch &b1, const bruch &b2);
			friend bruch operator*(const bruch &b1, const bruch &b2);
			friend bruch operator/(const bruch &b1, const bruch &b2);

	};

	// Ruft die Swap Methode eines Objektes auf
	// Methode ist für generische Programmierung wichtig ->
	// Viele Funktionen in <algorithm> benutzen swap
	void swap(bruch &b1, bruch &b2);

	std::ostream &operator<<(std::ostream &os, const bruch &b);
	bool operator==(const bruch &b1, const bruch &b2);
	bool operator!=(const bruch &b1, const bruch &b2);
	bool operator<(const bruch &b1, const bruch &b2);
	bool operator>(const bruch &b1, const bruch &b2);
	bool operator<=(const bruch &b1, const bruch &b2);
	bool operator>=(const bruch &b1, const bruch &b2);

	extern int global_int;
}
