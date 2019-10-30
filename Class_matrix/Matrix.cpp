#include "Matrix.h"

//Конструкторы класса
Matrix::Matrix()
{
}
Matrix::~Matrix()
{
}
Matrix::Matrix(unsigned Row, unsigned Col)
{

}




//Получить или установить эл. матрицы
double Matrix::GetIndex(unsigned n, unsigned m)
{

}
void Matrix::SetIndex(unsigned n, unsigned m, double Value)
{

}




//Задание значений эл. матрицы
//Все эл. одним значением
void Matrix::FixValue(double Value)
{

}
//Верхняя и нижняя грань рандомных значений для эл. матрицы
//Все эл. разные
void Matrix::RandValue(int FirstLim, int LastLim)
{

}




//Присвоит полученое значение новой матрице
Matrix Matrix::operator + (const Matrix& Matr2) const
{

}
Matrix Matrix::operator - (const Matrix& Matr2) const
{

}
Matrix Matrix::operator * (const Matrix& Matr2) const
{

}




//Присвоит полученое значение новой матрице
Matrix Matrix::Add(double Value)
{

}
Matrix Matrix::Sub(double Value)
{

}
Matrix Matrix::Mul(double Value)
{

}
Matrix Matrix::Div(double Value)
{

}




//Текущая матрица преобразуется в транспонированную, или диагональную, или обратную
void Matrix::Transpose()
{

}
void Matrix::Diagonal()
{

}
void Matrix::Revers()
{

}

//Вернет определитель матрицы, если та - квадратная
double Matrix::Detr()
{

}




//Получить или установить строку матрицы
std::vector<double> Matrix::GetString(unsigned Row)
{

}
void Matrix::SetString(unsigned Row, std::vector<double> Str)
{

}




//Полученное значение запишет в новую матрицу
void Matrix::operator += (const Matrix& Matr2)
{

}
void Matrix::operator -= (const Matrix& Matr2)
{

}
void Matrix::operator *= (const Matrix& Matr2)
{

}




//Полученное значение запишет в новую матрицу
void Matrix::operator += (double Value)
{

}
void Matrix::operator -= (double Value)
{

}
void Matrix::operator *= (double Value)
{

}
void Matrix::operator /= (double Value)
{

}
