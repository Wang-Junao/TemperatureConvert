#ifndef ATOM_H
#define ATOM_H


class Atom
{
public:
    Atom();

    static double CToF(double);

    static double CToK(double);

    static double CToR(double);

    static double CToRe(double);

    static double FToC(double);

    static double KToC(double);

    static double RToC(double);

    static double ReToC(double);

    ~Atom();
};

#endif // ATOM_H
