#include <iostream>
#include <iomanip>
#include<Windows.h>
#define аминь return 0;


//слу метод «ейдул€-√аусса

const int size = 8;

void Start();
void Calculation(float Arr_Matrix[size][size], float Arr_Number[size], int cal_p);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Start();

    аминь;
}

void Start()
{
    int  Quantity_Variables;
    std::cout << "¬ведите количество переменных:\n";
    std::cin >> Quantity_Variables;

    float Arr_Matrix[size][size], Arr_Number[size];

    for (int i = 0; i < Quantity_Variables; i++)
    {
        std::cout << "¬ведите коэффициенты матрицы(" << i + 1 <<" строка):\n";
        for (int j = 0; j < Quantity_Variables; j++)
        {
            std::cin >> Arr_Matrix[i][j];
        }

        std::cout << "¬ведите свободные члены матрицы(" << i + 1 << " строка):\n";
        std::cin >> Arr_Number[i];
    }

    Calculation(Arr_Matrix, Arr_Number, Quantity_Variables);
}

void Calculation(float Arr_Matrix[size][size], float Arr_Number[size], int  Quantity_Variables)
{
    for (int i = 0; i < Quantity_Variables; i++)
    {
        for (int j = i + 1; j < Quantity_Variables; j++)
        {
            float factor = Arr_Matrix[j][i] / Arr_Matrix[i][i];
            for (int g = i; g < Quantity_Variables; g++)
            {
                Arr_Matrix[j][g] -= factor * Arr_Matrix[i][g];
            }
            Arr_Number[j] -= factor * Arr_Number[i];
        }
    }

    int Arr_End[size];

    for (int i = Quantity_Variables - 1; i >= 0; i--)
    {
        Arr_End[i] = Arr_Number[i];
        for (int j = i + 1; j < Quantity_Variables; j++)
        {
            Arr_End[i] -= Arr_Matrix[i][j] * Arr_End[j];
        }
        Arr_End[i] /= Arr_Matrix[i][i];
    }

    std::cout << "–езультат:\n";

    for (int i = 0; i < Quantity_Variables; i++)
    {
        std::cout << "x" << i + 1 << " = " 
            << std::fixed << std::setprecision(6) << Arr_End[i] << "\n";
    }
}
