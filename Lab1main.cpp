#include <iostream>
#include "Lab1Mtx.h"

int main()
{
    Matrix Mtx;
    std::cout << "Matrixtin boyi egiziniz: ";
    int_Check(Mtx.size_m);
    Mtx = Create_Mtx(Mtx.size_m);
    Print_Mtx(Mtx);
    Line vec;
    vec = Create_Vec(vec, Mtx);
    Print_Vec(vec);
    Delete_m(&Mtx);
    Delete_l(&vec);
    return 0;
}