#include <cassert>
// Für std::swap()
#include <algorithm>

#include "Bruch.h"

namespace bruchrechnung {

				// Definition der statischen Klassenvariable
				const int bruch::class_id = 0;

				// Definition der extern Variable im Header
				// benutzt man, wenn die Variable Programmweit bekannt sein soll
				int global_int = 0;

				// Hinter dem Doppelpunkt befindet sich entweder die
				// a.) Elementinitialisierungsliste oder
				bruch::bruch(int zaehler, int nenner) :
								m_nenner(nenner), m_zaehler(zaehler) {
				}

				// b.) eine Konstruktordelegation
				// Diese Anweisungen werden ausgeführt bevor man den Konstruktorrumpf betritt
				bruch::bruch() : bruch(0, 1) {
				}

				bruch::bruch(const bruch &b) : bruch(b.m_zaehler, b.m_nenner) {

				}

				// Hätte ein Bruch eine große Menge von Daten besser gesagt einen Pointer
				// zu einem großen Block von Daten würde lediglich der Pointer von b in diesen
				// Bruch geschrieben werden und anschließend wird verhindert, dass der Block
				// gelöscht wird, so hat man die große Operation gespart einen Block voll mit
				// Daten zu erzeugen.
				bruch::bruch(bruch &&b) {
								swap(b);
				}

				// bruch::~bruch() {
				// }
				// Muss nicht Implementiert werden, denn durch = default (im Header) wird
				// dem Kompiler befohlen den Desktruktor zu generieren

				bruch::operator bool() const {
								return m_nenner != 0;
				}

				bruch::operator double() const {
								// Sichert zu, dass dieser Bruch gültig ist, ruft die Methode
								// operator bool() auf
								assert((bool) *this);
								return m_zaehler / (double) m_nenner;
				}

				bruch bruch::operator-() const {
								bruch result(-m_zaehler, m_nenner);
								return result;
				}

				bruch bruch::operator+() const {
								bruch result(m_zaehler, m_nenner);
								return result;
								// Kann man auch direkt schreiben :
								// return bruch(m_zaehler, m_nenner);
				}

				bruch &bruch::operator=(const bruch &b) {
								m_zaehler = b.m_zaehler;
								m_nenner = b.m_nenner;
								return *this;
				}

				bruch &bruch::operator=(bruch &&b) {
								swap(b);
								return *this;
				}

				bruch &bruch::operator+=(const bruch &b) {
								m_zaehler = m_zaehler * b.m_nenner + b.m_zaehler * m_nenner;
								m_nenner = b.m_nenner * m_nenner;
								return *this;
				}

				bruch &bruch::operator-=(const bruch &b) {
								m_zaehler = m_zaehler * b.m_nenner - b.m_zaehler * m_nenner;
								m_nenner = b.m_nenner * m_nenner;
								return *this;
				}

				bruch &bruch::operator*=(const bruch &b) {
								m_nenner *= b.m_nenner;
								m_zaehler *= b.m_zaehler;
								return *this;
				}

				bruch &bruch::operator/=(const bruch &b) {
								m_nenner *= b.m_zaehler;
								m_zaehler *= b.m_nenner;
								return *this;
				}

				void bruch::swap(bruch &b) {
								std::swap(m_nenner, b.m_nenner);
								std::swap(m_zaehler, b.m_zaehler);
				}

				int bruch::nenner() const {
								return m_nenner;
				}

				int bruch::zaehler() const {
								return m_zaehler;
				}

				void bruch::nenner(int nenner) {
								m_nenner = nenner;
				}

				void bruch::zaehler(int zaehler) {
								m_zaehler = zaehler;
				}

				void swap(bruch &b1, bruch &b2) {
								b1.swap(b2);
				}

				std::ostream &operator<<(std::ostream &os, const bruch &b1) {
								return os << "[" << b1.m_zaehler << "|" << b1.m_nenner << "]";
				}

				bool operator==(const bruch &b1, const bruch &b2) {
								return b1.m_zaehler * b2.m_nenner == b2.m_zaehler * b1.m_nenner;
				}

				bool operator!=(const bruch &b1, const bruch &b2) {
								return !(b1 == b2);
				}

				bool operator<(const bruch &b1, const bruch &b2) {
								return b1.m_zaehler * b2.m_nenner < b2.m_zaehler * b1.m_nenner;
				}

				bool operator>(const bruch &b1, const bruch &b2) {
								return b1.m_zaehler * b2.m_nenner > b2.m_zaehler * b1.m_nenner;
				}

				bool operator<=(const bruch &b1, const bruch &b2) {
								return !(b1 > b2);
				}

				bool operator>=(const bruch &b1, const bruch &b2) {
								return !(b1 < b2);
				}

				bruch operator+(const bruch &b1, const bruch &b2) {
								bruch result(b1);
								result += b2;
								return result;
				}

				bruch operator-(const bruch &b1, const bruch &b2) {
								bruch result(b1);
								result -= b2;
								return result;
				}

				bruch operator*(const bruch &b1, const bruch &b2) {
								bruch result(b1);
								result *= b2;
								return result;
				}

				bruch operator/(const bruch &b1, const bruch &b2) {
								bruch result(b1);
								result /= b2;
								return result;
				}
}
