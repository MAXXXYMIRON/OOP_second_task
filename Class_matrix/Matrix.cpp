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
	Matr.resize(Row);
	for (unsigned i = 0; i < Row; i++)
		Matr[i].resize(Col);
}




//Получить или установить эл. матрицы
double Matrix::GetIndex(unsigned n, unsigned m)
{
	if (WithinBorders(n, m))
		return Matr[n][m];
	else
		throw 1;
}
void Matrix::SetIndex(unsigned n, unsigned m, double Value)
{
	if (WithinBorders(n, m))
		Matr[n][m] = Value;
	else
		throw 1;
}




//Задание значений эл. матрицы
//Все эл. одним значением
void Matrix::FixValue(double Value)
{
	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr[i][j] = Value;
}
//Верхняя и нижняя грань рандомных значений для эл. матрицы
//Все эл. разные
void Matrix::RandValue(int FirstLim, int LastLim)
{
	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr[i][j] = FirstLim + rand() % (LastLim - FirstLim + 1);
}




//Присвоит полученое значение новой матрице
Matrix Matrix::operator + (const Matrix& Matr2) const
{
	if (EqualMatrix(Matr,Matr2.Matr)) throw 2;

	Matrix Matr3;
	Matr3.Matr = Matr;

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr3.Matr[i][j] = Matr[i][j] + Matr2.Matr[i][j];

	return Matr3;
}

Matrix Matrix::operator - (const Matrix& Matr2) const
{
	if (!EqualMatrix(Matr, Matr2.Matr)) throw 2;

	Matrix Matr3;
	Matr3.Matr = Matr;

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr3.Matr[i][j] = Matr[i][j] - Matr2.Matr[i][j];

	return Matr3;
}

Matrix Matrix::operator * (const Matrix& Matr2) const
{
	if (!EqualRowCol(Matr, Matr2.Matr)) throw 3;

	Matrix Matr3 = Matrix(Matr.size(), Matr2.Matr[0].size());

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr2.Matr[0].size(); j++)
			for (unsigned k = 0; k < Matr2.Matr.size(); k++)
				Matr3.Matr[i][j] += Matr[i][k] * Matr2.Matr[k][j];

	return Matr3;
}




//Присвоит полученое значение новой матрице
Matrix Matrix::Add(double Value)
{
	Matrix Matr3;
	Matr3.Matr = Matr;

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr3.Matr[i][j] = Matr[i][j] + Value;

	return Matr3;
}

Matrix Matrix::Sub(double Value)
{
	Matrix Matr3;
	Matr3.Matr = Matr;

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr3.Matr[i][j] = Matr[i][j] - Value;

	return Matr3;
}

Matrix Matrix::Mul(double Value)
{
	Matrix Matr3;
	Matr3.Matr = Matr;

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr3.Matr[i][j] = Matr[i][j] * Value;

	return Matr3;
}

Matrix Matrix::Div(double Value)
{
	if (Value == 0) throw 4;

	Matrix Matr3;
	Matr3.Matr = Matr;

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr3.Matr[i][j] = Matr[i][j] / Value;

	return Matr3;
}




//Текущая матрица преобразуется в транспонированную, или диагональную, или обратную
void Matrix::Transpose()
{
	if (!RectMatrix(Matr)) throw 6;


}
void Matrix::Diagonal()
{
	if (!SquareMatrix(Matr)) throw 7;

}
void Matrix::Inverse()
{
	if (!SquareMatrix(Matr)) throw 7;
	if (Detr() == 0) throw 8;

	
}

//Вернет определитель матрицы, если та - квадратная
double Matrix::Detr()
{
	if (!SquareMatrix(Matr)) throw 7;

	double Determinate;



	return Determinate;
}




//Получить или установить строку матрицы
std::vector<double> Matrix::GetString(unsigned Row)
{
	if (Row >= Matr.size() || Row < 0) throw 5;
	return Matr[Row];
}

void Matrix::SetString(unsigned Row, std::vector<double> Str)
{
	if (Row >= Matr.size() || Row < 0) throw 5;
	Matr[Row] = Str;
}




//Полученное значение запишет в текущую матрицу
void Matrix::operator += (const Matrix& Matr2)
{
	if (!EqualMatrix(Matr, Matr2.Matr)) throw 2;

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr[i][j] = Matr[i][j] + Matr2.Matr[i][j];
}

void Matrix::operator -= (const Matrix& Matr2)
{
	if (!EqualMatrix(Matr, Matr2.Matr)) throw 2;

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr[i][j] = Matr[i][j] - Matr2.Matr[i][j];
}

void Matrix::operator *= (const Matrix& Matr2)
{
	if (!EqualRowCol(Matr, Matr2.Matr)) throw 3;

	Matrix Matr3 = Matrix(Matr.size(), Matr2.Matr[0].size());

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr2.Matr[0].size(); j++)
			for (unsigned k = 0; k < Matr2.Matr.size(); k++)
				Matr3.Matr[i][j] += Matr[i][k] * Matr2.Matr[k][j];

	Matr = Matr3.Matr;
}




//Полученное значение запишет в текущую матрицу
void Matrix::operator += (double Value)
{
	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr[i][j] = Matr[i][j] + Value;
}

void Matrix::operator -= (double Value)
{
	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr[i][j] = Matr[i][j] - Value;
}

void Matrix::operator *= (double Value)
{
	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr[i][j] = Matr[i][j] * Value;
}

void Matrix::operator /= (double Value)
{
	if (Value == 0) throw 4;

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr[i][j] = Matr[i][j] / Value;
}




//Проверка на не выход за границы матрицы
bool Matrix::WithinBorders(unsigned IndexRow, unsigned IndexCol)
{
	return ( ((IndexRow >= 0 && IndexRow < Matr.size())) 
			&& (IndexCol >= 0 && IndexCol < Matr[IndexRow].size()) )
		? true 
		: false;
}
//Проверка на равенстнво матриц
bool Matrix::EqualMatrix(matrix Matr1, matrix Matr2) const
{
	if (Matr1.size() != Matr2.size()) return false;

	for (unsigned i = 0; i < Matr1.size(); i++)
		if (Matr1[i].size() != Matr2[i].size()) return false;

	return true;
}
//Проверка на равенство строки столбцу
bool Matrix::EqualRowCol(matrix Matr1, matrix Matr2) const
{
	//Матрица не должна быть ступенчатой
	if (!RectMatrix(Matr1) || !RectMatrix(Matr2)) return false;

	if (Matr1[0].size() != Matr2.size()) return false;

	return true;
}
//Проверка на не ступенчатость матрицы
bool Matrix::RectMatrix(matrix Matr1) const
{
	for (unsigned i = 0; i < Matr1.size(); i++)
		if (Matr1[i].size() != Matr1[0].size()) return false;
	return true;
}
//Проверка матрицы на квадратность
bool Matrix::SquareMatrix(matrix Matr1)
{
	if (!RectMatrix(Matr1)) return false;
	if (Matr1.size() != Matr1[0].size()) return false;
	return true;
}


void Matrix::Display()
{
	for (int i = 0; i < Matr.size(); i++)
	{
		for (int j = 0; j < Matr[i].size(); j++)
		{
			std::cout << Matr[i][j] << "     ";
		}
		std::cout << std::endl;
	}
}