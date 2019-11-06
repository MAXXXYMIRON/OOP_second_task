#include "Matrix.h"
using namespace std;


void main()
{
	setlocale(0, "");

	Matrix x(3, 3), y(3, 3), z(3, 3);
	x.RandValue(0, 5);
	y.RandValue(8, 15);

	try
	{
		z = x + y;
		z = x - y;
		z = x * y;

		z = x.Add(2);
		z = y.Sub(7);
		z = x.Mul(3);
		z = y.Div(2);

		z += 2;
		z -= 3;
		z *= 9;
		z /= 1;

		z += x;
		z -= y;
		z *= x;

		z.Transpose();
		z.Inverse();
		cout << z.Detr() << endl;

		z.SetElement(1, 1, 10);
		cout << z.GetElement(1, 1) << endl;

		vector<double> Line = z.GetString(0);
		z.SetString(2, Line);
	}
	catch (Matrix::ERRORS e)
	{
		switch (e)
		{
		case Matrix::IndexOutsideMatrix:
		{
			cout << "Индекс вне границ матрицы" << endl;
		}
			break;
		case Matrix::MatricesNotEqual:
		{
			cout << "Порядки матриц не равны" << endl;
		}
			break;
		case Matrix::LineNotEqualColoumn:
		{
			cout << "Длина строки первой матрицы не равна длине столбца второй" << endl;
		}
			break;
		case Matrix::DivByZero:
		{
			cout << "Деление на ноль недопустимо" << endl;
		}
			break;
		case Matrix::OffLineIndex:
		{
			cout << "Индекс вне границ кол-ва строк матрицы" << endl;
		}
			break;
		case Matrix::NotRectMatrix:
		{
			cout << "Матрица не прямоугольная" << endl;
		}
			break;
		case Matrix::NotSquareMatric:
		{
			cout << "Матрица не квадратная" << endl;
		}
			break;
		case Matrix::DeterminateIsZero:
		{
			cout << "Определитель матрицы равен нулю" << endl;
		}
			break;
		case Matrix::OddElementsMatrix:
		{
			cout << "Матрица не квадратная или содежит нечетное кол-во эл." << endl;
		}
			break;
		default:
			break;
		}
	}

	system("pause");
}