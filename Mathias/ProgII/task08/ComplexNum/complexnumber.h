#pragma once
#include <string>



class ComplexNumber
{
public:
    //ComplexNumber();
    //ComplexNumber(double real);
    //ComplexNumber(double real,double Imag);
    ComplexNumber(double Real = 0.0, double Imag = 0.0, std::string name =""); //damit kann ich entweder den einen(Real) oder beide nehmen
    // Vorteil direkt Deklaration sobald das OBJ erstellt wird?!
    ~ComplexNumber();
    double Real() const;
    double Imag() const;
    std::string Name() const;
    void Real(double r);
    void Imag(double i);
    void Name(std::string name);
    bool isReal() const;
    bool isImag() const;
    void add(const ComplexNumber& c);
    static ComplexNumber add(const ComplexNumber& c1,const ComplexNumber& c2);
    std::string toString() const;
    std::string toSVG() const;
    std::string Color() const;
    int SVGRadius() const;
    void Color(const std::string c);
    void SVGRadius(const int r);


private:
    double mReal {0.0};
    double mImag {0.0};
    std::string mName;
    std::string mColor{"black"};
    int mSVGRadius {1};
};
std::ostream& operator<<(std::ostream& outs, const ComplexNumber& c);
ComplexNumber& operator+=(ComplexNumber& c1, const ComplexNumber& c2);
ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2);
bool operator==(const ComplexNumber& c1, const ComplexNumber& c2);
bool operator!=(const ComplexNumber& c1, const ComplexNumber& c2);
// COMPLEXNUMBER_H

