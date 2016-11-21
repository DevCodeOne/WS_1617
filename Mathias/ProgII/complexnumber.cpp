#include "complexnumber.h"
#include "simpletest.h"
#include <iostream>
#include "ppcmath.h"
#include <cmath>
#include <sstream>

/*ComplexNumber::ComplexNumber():mReal(0.0), mImag(0.0)
{
}
ComplexNumber::ComplexNumber(double Real):mReal(Real), mImag(0.0)
{
}*/

ComplexNumber::ComplexNumber(double Real,double Imag, std::string name) :mReal(Real),mImag(Imag),mName(name)
{
    /*std::cout
            << "Neue ComplexNumber: "
            << mName
            << " "
            << "Realteil: "
            << mReal
            << " Imaginärteil: "
            << mImag
            << std::endl;
   std::cout << __PRETTY_FUNCTION__ << std::endl;*/
}
ComplexNumber::~ComplexNumber(){
    /*std::cout
            << "Ende ComplexNumber: "
            << mName
            << " "
            << "Realteil: "
            << mReal
            << " Imaginärteil: "
            << mImag
            << std::endl;
    std::cout << __PRETTY_FUNCTION__ << std::endl;*/
}

double ComplexNumber::Real() const{
    return mReal;
}

double ComplexNumber::Imag() const{
    return mImag;
}

std::string ComplexNumber::Name() const{
    return mName;
}

void ComplexNumber::Real(const double& r){
    mReal = r;
}

void ComplexNumber::Imag(const double& i){
    mImag = i;
}

void ComplexNumber::Name(const std::string& name){
    mName = name;
}

bool ComplexNumber::isReal() const{
    return std::fabs(mImag) < 1e-10;//fabs liefert absulutwert

}

bool ComplexNumber::isImag() const{
    return  std::fabs(mReal) < 1e-10;

}

void ComplexNumber::add(const ComplexNumber& c){
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    mReal += c.mReal;
    mImag += c.mImag;
}

ComplexNumber ComplexNumber::add(ComplexNumber& c1,const ComplexNumber& c2){
    //std::cout << __PRETTY_FUNCTION__ << std::endl;
    ComplexNumber sum = c1;
    sum.add(c2);
    return sum;
}

std::string ComplexNumber::toString() const{
    std::string ret = "(Number ";
    ret += "Name: " + ComplexNumber::Name() + " ";
    ret += std::to_string(ComplexNumber::Real()) +" + ";
    ret += std::to_string(ComplexNumber::Imag()) +" * i)";
    return ret;
}

std::ostream& operator<<(std::ostream& outs, const ComplexNumber& c){
    outs << c.toString();
    return outs;
}

ComplexNumber& operator+=(ComplexNumber& c1, const ComplexNumber& c2){
    c1.add(c2);
    return c1;
}

ComplexNumber operator+(ComplexNumber& c1, const ComplexNumber& c2){
    return ComplexNumber::add(c1,c2); // geht das so?!
}

bool operator==(ComplexNumber& c1, const ComplexNumber& c2){
    if ((c1.Real()==c2.Real())&(c1.Imag()==c2.Imag())) return true;
    return false;
}

bool operator!=(ComplexNumber& c1, const ComplexNumber& c2){
    return !(c1==c2);
}

std::string ComplexNumber::toSVG() const
{
    std::string svgString = "<circle "; // <> Definition der _lokalen_ Variable `svgString` und Initialisierung mit einem C-String-Literal
    svgString += "cx=\"" + std::to_string(Math::toInt(mReal)) + "\" ";
    svgString += "cy=\"" + std::to_string(Math::toInt(mImag)) + "\" ";
    svgString += "r=\"" + std::to_string(mSVGRadius) + "\" "; // <> Umwandlung eines primitiven DT in ein `std::string`-Objekt
    svgString += "stroke=\"" + mColor + "\" "; // <> Operatoren `+=` und `+` für den Typ `std::string` und implizite Konvertierung von C-String -> std::string
    svgString +=  "/>";
    return svgString;
}

std::string ComplexNumber::Color() const{
    return mColor;
}

int ComplexNumber::SVGRadius() const{
    return mSVGRadius;
}

void ComplexNumber::Color(const std::string& c){
    mColor = c;
}

void ComplexNumber::SVGRadius(const int& r){
    mSVGRadius = r;
}

SIMPLETEST("Standartkonstruktor") {
    ComplexNumber c;
    if (!Math::equal(c.Real(), 0.0)) return false;
    if (!Math::equal(c.Imag(), 0.0)) return false;
    return true;
};

SIMPLETEST("Konstruktor mit einer Variable") {
    ComplexNumber c(3.2);
    if (!Math::equal(c.Real(), 3.2)) return false;
    if (!Math::equal(c.Imag(), 0.0)) return false;
    return true;
};

SIMPLETEST("Konstruktor mit zwei") {
    ComplexNumber c(3.1,4.2);
    if (!Math::equal(c.Real(), 3.1)) return false;
    if (!Math::equal(c.Imag(), 4.2)) return false;
    return true;
};

SIMPLETEST("Konstruktor mit drei") {
    ComplexNumber c(3.1,4.2,"KonstTest");
    if (!Math::equal(c.Real(), 3.1)) return false;
    if (!Math::equal(c.Imag(), 4.2)) return false;
    if (!(c.Name()=="KonstTest")) return false;
    return true;
};

SIMPLETEST("Mutatoren u Beobachter") {
    ComplexNumber c;
    c.Real(3.1);
    c.Imag(4.2);
    c.Name("MutTest");
    if (!Math::equal(c.Real(), 3.1)) return false;
    if (!Math::equal(c.Imag(), 4.2)) return false;
    if (!(c.Name()=="MutTest")) return false;
    return true;
};

SIMPLETEST("Mutator Color") {
    ComplexNumber c;
    c.Color("red");
    if (!(c.Color()== "red")) return false;
    return true;
};

SIMPLETEST("Mutator Radius") {
    ComplexNumber c;
    c.SVGRadius(3);
    if (!Math::equal(c.SVGRadius(), 3)) return false;
    return true;
};

SIMPLETEST("toSVG") {
    ComplexNumber c;
    if ("<circle cx=\"0\" cy=\"0\" r=\"1568209912\" stroke=\"black\" />"==c.toSVG()) return false;
    return true;
};

SIMPLETEST("isImag") {
    ComplexNumber c(0.0,4.2);
    if (!c.isImag()) return false;
    return true;
};

SIMPLETEST("isReal") {
    ComplexNumber c(4.3,0.0);
    if (!c.isReal()) return false;
    return true;
};

SIMPLETEST("Add") {
    ComplexNumber c1(3.1,4.2);
    ComplexNumber c2;
    c2.add(c1);
    if (!Math::equal(c2.Real(), 3.1)) return false;
    if (!Math::equal(c2.Imag(), 4.2)) return false;
    return true;
};

SIMPLETEST("static Add") {
    ComplexNumber c1(3.1,4.2);
    ComplexNumber c2(1.9,2.2);
    ComplexNumber c3 = ComplexNumber::add(c1,c2);
    if (!Math::equal(c3.Real(), 5.0)) return false;
    if (!Math::equal(c3.Imag(), 6.4)) return false;
    return true;
};

SIMPLETEST("toString") {
    ComplexNumber c(3.1,4.2);
    std::cout << c.toString();
    if (c.toString()=="(Number Name:  3.100000 + 4.200000 * i)") return true;
    return false;
};

SIMPLETEST("toString mit Testname") {
    ComplexNumber c(3.1,4.2,"Testname");
    std::cout << c.toString();
    if (c.toString()=="(Number Name: Testname 3.100000 + 4.200000 * i)") return true;
    return false;
};

SIMPLETEST("ComplexNumber <<") {
    ComplexNumber c1(5,6);
    std::stringstream ss;
    ss << c1;
    if (ss.str() != "(Number Name:  5.000000 + 6.000000 * i)") return false;
    return true;
};

SIMPLETEST("ComplexNumber +=") {
    ComplexNumber c1(5,6);
    ComplexNumber c2(3,1);
    c2 += c1;
    if (!Math::equal(c1.Real(), 5.0)) return false;
    if (!Math::equal(c1.Imag(), 6.0)) return false;
    if (!Math::equal(c2.Real(), 8.0)) return false;
    if (!Math::equal(c2.Imag(), 7.0)) return false;
    return true;
};

SIMPLETEST("ComplexNumber +") {
    ComplexNumber c1(5,6);
    ComplexNumber c2(3,1);
    ComplexNumber c3;
    c3 = c2 + c1;
    if (!Math::equal(c1.Real(), 5.0)) return false;
    if (!Math::equal(c1.Imag(), 6.0)) return false;
    if (!Math::equal(c2.Real(), 3.0)) return false;
    if (!Math::equal(c2.Imag(), 1.0)) return false;
    if (!Math::equal(c3.Real(), 8.0)) return false;
    if (!Math::equal(c3.Imag(), 7.0)) return false;
    return true;
};

SIMPLETEST("ComplexNumber ==") {
    ComplexNumber c1(5,6);
    ComplexNumber c2(3,1);
    ComplexNumber c3(3,1);
    if (c1==c2) return false;
    if (!(c2==c3)) return false;
    return true;
};

SIMPLETEST("ComplexNumber !=") {
    ComplexNumber c1(5,6);
    ComplexNumber c2(3,1);
    ComplexNumber c3(3,1);
    if (!(c1!=c2)) return false;
    if (c2!=c3) return false;
    return true;
};

SIMPLETEST("Typumwandlungskonstruktor") {
    ComplexNumber c1 = 3.5;
    if (!Math::equal(c1.Real(), 3.5)) return false;
    if (!Math::equal(c1.Imag(), 0.0)) return false;
    return true;
};


SIMPLETEST("Typumwandlungskonstruktor mit add") {
    ComplexNumber c1 = 3.5;
    ComplexNumber c2;
    c2 = c1 + 2.0;
    if (!Math::equal(c1.Real(), 3.5)) return false;
    if (!Math::equal(c1.Imag(), 0.0)) return false;
    if (!Math::equal(c2.Real(), 5.5)) return false;
    if (!Math::equal(c2.Imag(), 0.0)) return false;
    return true;
};

