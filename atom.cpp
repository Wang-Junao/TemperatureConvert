#include "atom.h"

Atom::Atom()
{

}
double Atom::CToF(double C) {
    double F = 32 + 1.8 * C;
    return F;
}

double Atom::CToK(double C) {
    double K = 273.15 + C;
    return K;
}

double Atom::CToR(double C) {
    double R = (C + 273.15) * 1.8;
    return R;
}

double Atom::CToRe(double C) {
    double Re = C / 1.25;
    return Re;
}

double Atom::FToC(double F) {
    double C = (F - 32) / 1.8;
    return C;
}

double Atom::KToC(double K) {
    double C = K - 273.15;
    return C;
}

double Atom::RToC(double R) {
    double C = R / 1.8 - 273.15;
    return C;
}

double Atom::ReToC(double Re) {
    double C = Re * 1.25;
    return C;
}
Atom::~Atom() {

}
