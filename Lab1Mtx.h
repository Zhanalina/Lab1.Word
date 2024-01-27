#ifndef MATRIX_OPERATIONS_HHP
#define MATRIX_OPERATIONS_HHP

struct Line
{
    int size_l=0;
    int* line=nullptr;
};

struct Matrix
{
    int size_m=0;
    Line* line_m=nullptr;
};

void int_Check(int& x);
Matrix Create_Mtx(int& m);
Matrix Filling_Mtx(Matrix& Mtx);
void Print_Mtx(Matrix& Mtx);
void Print_Vec(Line& vec);
Line Filling_Vec(Line& vec, Matrix& Mtx);
void Delete_m(Matrix* Mtx);
void Delete_l(Line* vec);
Line Create_Vec(Line& vec, Matrix& Mtx);
int Modul(int n);
int Summ(int n);

#endif