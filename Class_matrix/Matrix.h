#pragma once
#include<iostream>
#include <vector>

typedef std::vector<std::vector<double>> matrix;

class Matrix
{
private:
	matrix Matr;
public:
	//Конструкторы класса
	Matrix();
	~Matrix();
	Matrix(unsigned Row, unsigned Col);

	//Получить или установить эл. матрицы
	double GetIndex(unsigned n, unsigned m);
	void SetIndex(unsigned n, unsigned m, double Value);

	//Задание значений эл. матрицы
	//Все эл. одним значением
	void FixValue(double Value);
	//Верхняя и нижняя грань рандомных значений для эл. матрицы
	//Все эл. разные
	void RandValue(int FirstLim, int LastLim);

	//Присвоит полученое значение новой матрице
	Matrix operator + (const Matrix& Matr2) const;
	Matrix operator - (const Matrix& Matr2) const;
	Matrix operator * (const Matrix& Matr2) const;

	//Присвоит полученое значение новой матрице
	Matrix Add(double Value);
	Matrix Sub(double Value);
	Matrix Mul(double Value);
	Matrix Div(double Value);

	//Текущая матрица преобразуется в транспонированную, или диагональную, или обратную
	void Transpose();
	void Diagonal();
	void Inverse();
	//Вернет определитель матрицы, если та - квадратная
	double Detr();

	//Получить или установить строку матрицы
	std::vector<double> GetString(unsigned Row);
	void SetString(unsigned Row, std::vector<double> Str);

	//Полученное значение запишет в текущую матрицу
	void operator += (const Matrix& Matr2);
	void operator -= (const Matrix& Matr2);
	void operator *= (const Matrix& Matr2);

	//Полученное значение запишет в текущую матрицу
	void operator += (double Value);
	void operator -= (double Value);
	void operator *= (double Value);
	void operator /= (double Value);

	void Display();

private:
	//Проверка на не выход индекса за границы матрицы
	bool WithinBorders(unsigned IndexRow, unsigned IndexCol);
	//Проверка на равенстнво матриц
	bool EqualMatrix(matrix Matr1, matrix Matr2) const;
	//Проверка на равенство строки столбцу
	bool EqualRowCol(matrix Matr1, matrix Matr2) const;
	//Проверка на не ступенчатость матрицы
	bool RectMatrix(matrix Matr1) const;
	//Проверка матрицы на квадратность
	bool SquareMatrix(matrix Matr1);
};

