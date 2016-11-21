#include "complexvector.h"
#include "complexnumber.h"
#include "simpletest.h"
#include <iostream>
#include "ppcmath.h"
#include <cmath>
ComplexVector::ComplexVector(ComplexNumber begin, ComplexNumber end) :
    mBegin(begin), mEnd(end)
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl; // <> Das intrinsische Präprozessormakro `__PRETTY_FUNCTION__` evaluiert zum Namen der umgebenden Funktion.
} // <> Am Ende dieses Konstruktors werden die *lokalen Parametervariablen* `begin` und `end` zerstört, daher erfolgt ein _Destruktor_-Aufruf.
ComplexVector::~ComplexVector()
{
    //std::cout << __PRETTY_FUNCTION__ << std::endl; // <> Protokollierung des _Destruktor_-Aufrufs.
}

ComplexNumber ComplexVector::Begin() const{
    return mBegin;
}

ComplexNumber ComplexVector::End() const{
    return mEnd;
}

void ComplexVector::Begin(const ComplexNumber& b){
    mBegin=b;
}

void ComplexVector::End(const ComplexNumber& e){
    mEnd=e;
}

std::string ComplexVector::toString() const{
    std::string ret = "[Vector: ";
    ret += "(Name Begin: " + ComplexVector::Begin().Name()+ " ";
    ret += std::to_string(ComplexVector::Begin().Real()) +" + ";
    ret += std::to_string(ComplexVector::Begin().Imag()) +" * i)";
    ret += "(Name End: " + ComplexVector::End().Name()+ " ";
    ret += std::to_string(ComplexVector::End().Real()) +" + ";
    ret += std::to_string(ComplexVector::End().Imag()) +" * i)]";
    return ret;
}

std::ostream& operator<<(std::ostream& outs, const ComplexVector& v){
    outs << v.toString();
    return outs;
}

std::string ComplexVector::toSVG() const
{
    std::string svgString = "<line "; // <> Definition der _lokalen_ Variable `svgString` und Initialisierung mit einem C-String-Literal
    svgString += "x1=\"" + std::to_string(Math::toInt(mBegin.Real())) + "\" ";
    svgString += "y1=\"" + std::to_string(Math::toInt(mBegin.Imag())) + "\" ";
    svgString += "x2=\"" + std::to_string(Math::toInt(mEnd.Real())) + "\" ";
    svgString += "y2=\"" + std::to_string(Math::toInt(mEnd.Imag())) + "\" ";
    svgString += "stroke-width=\"" + std::to_string(mBegin.SVGRadius()) + "\" "; // <> Umwandlung eines primitiven DT in ein `std::string`-Objekt
    svgString += "stroke=\"" + mBegin.Color() + "\" "; // <> Operatoren `+=` und `+` für den Typ `std::string` und implizite Konvertierung von C-String -> std::string
    svgString +=  "/>";
    return svgString;

}

SIMPLETEST("Standartkonstruktor") {
    ComplexVector v1(ComplexNumber{},ComplexNumber{});
    if (!Math::equal(v1.Begin().Real(), 0.0)) return false;
    if (!Math::equal(v1.Begin().Imag(), 0.0)) return false;
    if (!Math::equal(v1.End().Real(), 0.0)) return false;
    if (!Math::equal(v1.End().Imag(), 0.0)) return false;
    return true;
};

SIMPLETEST("Mutatoren u Beobachter") {
    ComplexVector v1(ComplexNumber{},ComplexNumber{});
    ComplexNumber c1(3.2,2.2);
    ComplexNumber c2(1.1);
    v1.Begin(c1);
    v1.End(c2);
    if (!Math::equal(v1.Begin().Real(), 3.2)) return false;
    if (!Math::equal(v1.Begin().Imag(), 2.2)) return false;
    if (!Math::equal(v1.End().Real(), 1.1)) return false;
    if (!Math::equal(v1.End().Imag(), 0.0)) return false;
    return true;
};
