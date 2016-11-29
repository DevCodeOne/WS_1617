#include "complexnumber.h"
#include "complexvector.h"
#include "svgfile.h"
#include <iostream>
#include <cassert>
extern bool testing;

int main(){
    SVGFile svg("SVGDatei.svg");
    ComplexNumber c1(300.0,200.0,"C1");
    c1.SVGRadius(5);
    ComplexNumber c2(200.0,300.0,"C2");
    c2.SVGRadius(5);
    ComplexVector v1(c1,c2);
    svg.add(v1.toSVG());
    svg.add(c1.toSVG());
    svg.add(c2.toSVG());

    std::cout << c1 << std::endl;
    std::cout << v1 << std::endl;

    ComplexNumber cn = 1.0;
    ComplexNumber cn2;
    cn2 = cn + 2.0; //erstellt aus der 2.0 eine neue Complexnumber und nutzt die add

    /*
    std::cout << "Beginn MAIN()" << std::endl;
    ComplexNumber cn1;
    assert(cn1.isReal()); // <> Die Zahl (0.0, 0.0) erfüllt beide Präd..
    assert(cn1.isImag());
    ComplexNumber cn2{1.0}; // <> Dies ist eine _reelle_ Zahl.
    assert(cn2.isReal());
    assert(!cn2.isImag());
    ComplexNumber cn3{0.0, 1.0}; // <> Dies ist die imaginÃ¤re Einheit _i_ (oder _j_ fÃ¼r den Elektrotechniker)
    assert(!cn3.isReal());
    assert(cn3.isImag());


    ComplexNumber test01(9.9,8.3);
    std::cout<< test01.toString() << std::endl;
    ComplexNumber c2(2.2,3.3,"c2");
    test01.add(c2);
    std::cout<< c2.toString() << std::endl;
    ComplexNumber c1(1.9);
    ComplexNumber c2(0.1,1.1,"C2");

    c1.add(c2);
    // ohne & wird ein neues OBJ erzeugt was am ende der Methode wieder zerstört wird.
    std::cout << "Ende MAIN()" << std::endl;*/
    return 0;
}
