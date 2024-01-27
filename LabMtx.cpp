#include <iostream>
#include "Lab1Mtx.h"

void int_Check(int& x)
{
    std::cin >> x;
    while (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Durys emes" << std::endl;
        std::cout << "Tagyda iste: ";
        std::cin >> x;
    }
    if (x < 0)
    {
        std::cout << "engizilgen san nol'den az, biz ony tyzetemiz" << std::endl;
        x *= (-1);
        std::cout << "x = " << x << std::endl;
    }
}

Matrix Create_Mtx(int& m)
{
    Matrix Mtx;
    try
    {
        Mtx.size_m = m;
        Mtx.line_m = new Line[Mtx.size_m];

        for (int i = 0; i < (Mtx.size_m); i++)
        {
            Mtx.line_m[i].size_l = (i + 1);
            Mtx.line_m[i].line = new int[i + 1];
        }
    }
    catch (const std::bad_alloc& ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        if (Mtx.line_m != nullptr)
        {
            for (int i = 0; i < Mtx.size_m; i++)
            {
                delete[] Mtx.line_m[i].line;
            }
            delete[] Mtx.line_m;
        }
        throw;
    }
    std::cout << "Martica bar" << std::endl;
    Mtx = Filling_Mtx(Mtx);
    return Mtx;
}

Matrix Filling_Mtx(Matrix& Mtx)
{
    if (!Mtx.line_m)
    {
        std::cout << "Martica zhok, ket bar" << std::endl;
    }
    else
    {
        for (int i = 0; i < Mtx.size_m; i++)
        {
            std::cout << i << "inshi zholga " << i + 1 << " mandi egiziniz: ";
            for (int j = 0; j < Mtx.line_m[i].size_l; j++)
            {
                int_Check(Mtx.line_m[i].line[j]);
            }
        }
    }
    
    return Mtx;
}

void Print_Mtx(Matrix& Mtx)
{
    if (!Mtx.line_m)
    {
        std::cout << "Matrica zok, ket bar" << std::endl;
        return;
    }
    for (int i = 0; i < Mtx.size_m; i++)
    {
        for (int j = 0; j < Mtx.line_m[i].size_l; j++)
        {
            std::cout << Mtx.line_m[i].line[j] << " ";
        }
        for (int k = Mtx.line_m[i].size_l; k < Mtx.size_m; k++)
        {
            std::cout << Mtx.line_m[k].line[i] << " ";
        }
        std::cout << std::endl;
    }
}

void Print_Vec(Line& vec)
{
    if (!vec.line)
    {
        std::cout << "Vector zok, ket bar" << std::endl;
        return;
    }
    for (int i = 0; i < vec.size_l; i++)
    {
        std::cout << "vec[" << i << "]= " << vec.line[i] << " ";
    }
}

Line Create_Vec(Line& vec, Matrix& Mtx)
{
    try
    {
        vec.size_l = Mtx.size_m;
        vec.line = new int[vec.size_l];
        std::cout << "Vector bar" << std::endl;
    }
    catch (const std::bad_alloc& ex)
    {
        std::cerr << "Error: " << ex.what() << std::endl;
        if (vec.line != nullptr)
        {
            delete[] vec.line;
        }
        throw;
    }
    vec = Filling_Vec(vec, Mtx);
    return vec;
}

int Modul(int n)
{
    if (n < 0)
    {
        n *= (-1);
    }
    return n;
}

int Summ(int n)
{
    n = Modul(n);
    int tmp = 0;
    while (n != 0)
    {
        tmp += n % 10;
        n /= 10;
    }
    return tmp;
}

Line Filling_Vec(Line& vec, Matrix& Mtx)
{
    if (!Mtx.line_m)
    {
        std::cout << "Matrica zok, ket bar" << std::endl;
    }
    else
    {
        int first, sum = 0, x;
        for (int i = 0; i < Mtx.size_m; i++)
        {
            first = Summ(Mtx.line_m[i].line[0]);
            sum = Mtx.line_m[i].line[0];
            for (int j = 1; j < Mtx.line_m[i].size_l; j++)
            {
                x = Summ(Mtx.line_m[i].line[j]);
                if (x == first)
                {
                    sum += Mtx.line_m[i].line[j];
                }
            }
            for (int k = Mtx.line_m[i].size_l; k < Mtx.size_m; k++)
            {
                x = Summ(Mtx.line_m[k].line[i]);
                if (x == first)
                {
                    sum += Mtx.line_m[k].line[i];
                }
            }
            vec.line[i] = sum;
        }
    }
    return vec;
}

void Delete_m(Matrix* Mtx)
{
    if (!Mtx->line_m)
    {
        std::cout << "Matrica zhok" << std::endl;
    }
    else
    {
        for (int i = 0; i < Mtx->size_m; i++)
        {
            delete[] Mtx->line_m[i].line;
        }
        delete[] Mtx->line_m;
    }
}

void Delete_l(Line* vec)
{
    if (!vec->line)
    {
        std::cout << "Vector zhok" << std::endl;
    }
    else
    {
        delete[] vec->line;
    }
}
