#pragma once
#include "complexnumber.h"


class ComplexVector
{
public:
    ComplexVector(ComplexNumber begin,ComplexNumber end);
    ~ComplexVector();    
    ComplexNumber Begin() const;
    ComplexNumber End() const;
    void Begin(const ComplexNumber& b);
    void End(const ComplexNumber& e);
    std::string toString() const;
    std::string toSVG() const;
private:
    ComplexNumber mBegin;
    ComplexNumber mEnd;

};
std::ostream& operator<<(std::ostream& outs, const ComplexVector& v);
// COMPLEXVECTOR_H
