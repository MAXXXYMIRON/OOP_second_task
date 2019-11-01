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
	srand(time(NULL));
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
Matrix Matrix::Add(double Value) const
{
	Matrix Matr3;
	Matr3.Matr = Matr;

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr3.Matr[i][j] = Matr[i][j] + Value;

	return Matr3;
}

Matrix Matrix::Sub(double Value) const
{
	Matrix Matr3;
	Matr3.Matr = Matr;

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr3.Matr[i][j] = Matr[i][j] - Value;

	return Matr3;
}

Matrix Matrix::Mul(double Value) const
{
	Matrix Matr3;
	Matr3.Matr = Matr;

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr[i].size(); j++)
			Matr3.Matr[i][j] = Matr[i][j] * Value;

	return Matr3;
}

Matrix Matrix::Div(double Value) const
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

	matrix Matr2;
	Matr2.resize(Matr[0].size());

	for (unsigned i = 0; i < Matr[0].size(); i++)
	{
		Matr2[i].resize(Matr.size());

		for (unsigned j = 0; j < Matr.size(); j++)
			Matr2[i][j] = Matr[j][i];
	}

	Matr = Matr2;
}


void Matrix::Diagonal()
{
	if (!SquareMatrix(Matr)) throw 7;

}


void Matrix::Inverse()
{
	if (!SquareMatrix(Matr)) throw 7;
	if (Detr() == 0) throw 8;

	matrix MatrE;//Текущая матрица и еденичная матрица
	std::vector<double> NumUsedLine;//Массив с номерами исп. строк
	MatrE.resize(Matr.size());
	NumUsedLine.resize(Matr.size());
	for (unsigned i = 0; i < MatrE.size(); i++)
	{
		MatrE[i].resize(MatrE.size() * 2);
		NumUsedLine[i] = -1;
	}
	//Инициализация матрицы с еденичной
	for (unsigned i = 0; i < MatrE.size(); i++)
		for (unsigned j = 0; j < MatrE[i].size(); j++)
		{
			if (j < Matr.size())
				MatrE[i][j] = Matr[i][j];
			else
				MatrE[i][j] = ((j - Matr.size()) == i) ? 1 : 0;
		}

	//Преобразование тек. матрицы к едничной и одновременное изменение еденичной второй той ну ты понял надеюсь
	for (unsigned j = 0; j < Matr.size(); j++)
		for (unsigned i = 0; i < Matr.size(); i++)
			if (MatrE[i][j] != 0 && RepeatUsedLine(NumUsedLine, i))
			{
				NumUsedLine[j] = i;
				MatrE[i] = LineDivNumber(MatrE[i], MatrE[i][j]);

				for (unsigned k = 0; k < MatrE.size(); k++)
				{
					if (k == i) continue;
					MatrE[k] = SubLine(MatrE[k], MatrE[i], j);
				}

				break;
			}

	Unit(MatrE); //Если еденицы расположены в неправильном порядке

	for (unsigned i = 0; i < Matr.size(); i++)
		for (unsigned j = 0; j < Matr.size(); j++)
			Matr[i][j] = MatrE[i][j + Matr.size()];
}
//Проверка на повторное использование строки, для нахождения обратной матрицы
bool Matrix::RepeatUsedLine(const std::vector<double>& ArrayIndexLine, unsigned IndexLine)
{
	for (unsigned i = 0; i < ArrayIndexLine.size(); i++)
		if (IndexLine == ArrayIndexLine[i]) return false;

	return true;
}
//Деление строки матрицы на число
std::vector<double> Matrix::LineDivNumber(const std::vector<double>& Line, double Number)
{
	std::vector<double> Result;
	Result.resize(Line.size());
	for (unsigned i = 0; i < Line.size(); i++)
	{
		Result[i] = Line[i] / Number;
	}
	return Result;
}
//Вычитание строк, одна из которых домножена на Index эл. первой
std::vector<double> Matrix::SubLine(const std::vector<double>& Line1, const std::vector<double>& Line2, unsigned Index)
{
	std::vector<double> Result;
	Result.resize(Line1.size());
	for (unsigned i = 0; i < Line1.size(); i++)
	{
		Result[i] = Line1[i] - (Line2[i] * Line1[Index]);
	}
	return Result;
}
//Выравнивание еденичной матрицы
void Matrix::Unit(matrix& Matr1)
{
	std::vector<double> CopyLine;
	for (unsigned j = 0; j < Matr1.size(); j++)
		for (unsigned i = 0; i < Matr1.size(); i++)
			if (Matr1[i][j] == 1)
			{
				CopyLine = Matr1[j];
				Matr1[j] = Matr1[i];
				Matr1[i] = CopyLine;
				break;
			}

}


//Вернет определитель матрицы, если та - квадратная
double Matrix::Detr() const
{
	if (!SquareMatrix(Matr)) throw 7;

	if (Matr.size() == 1) return Matr[0][0];
	if (Matr.size() == 2) return Detr(Matr);

	double Determinate = 0;
	for (unsigned i = 0; i < Matr[0].size(); i++)
		Determinate += Detr(Matr, 0, i);
	
	return Determinate;
}
//Нахождение определителей миноров матрицы
double Matrix::Detr(const matrix& M, unsigned Row, unsigned Col) const
{
	matrix Minor;
	Minor.resize(M.size() - 1);
	for (unsigned i = 0; i < Minor.size(); i++)
		Minor[i].resize(M[i].size() - 1);

	unsigned i1 = 0, j1 = 0;
 	for (unsigned i = 0; i < M.size(); i++)
	{
		if (i == Row) continue;
		for (unsigned j = 0; j < M[i].size(); j++)
		{
			if (j == Col) continue;
			Minor[i1][j1] = M[i][j];
			j1++;
		}
		i1++;
		j1 = 0;
	}

	if (Minor.size() == 2) return (pow(-1, Row + Col) * M[Row][Col]) * Detr(Minor);

	double Determinate = 0;
	for (unsigned i = 0; i < Minor[0].size(); i++)
		Determinate += (pow(-1, Row + Col) * M[Row][Col]) * Detr(Minor, 0, i);
	return Determinate;
}
//Определитель матрицы 2 на 2
double Matrix::Detr(const matrix& M) const
{
	return (M[0][0] * M[1][1]) - (M[0][1] * M[1][0]);
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
bool Matrix::EqualMatrix(const matrix& Matr1, const matrix& Matr2) const
{
	if (Matr1.size() != Matr2.size()) return false;

	for (unsigned i = 0; i < Matr1.size(); i++)
		if (Matr1[i].size() != Matr2[i].size()) return false;

	return true;
}
//Проверка на равенство строки столбцу
bool Matrix::EqualRowCol(const matrix& Matr1, const matrix& Matr2) const
{
	//Матрица не должна быть ступенчатой
	if (!RectMatrix(Matr1) || !RectMatrix(Matr2)) return false;

	if (Matr1[0].size() != Matr2.size()) return false;

	return true;
}
//Проверка на не ступенчатость матрицы
bool Matrix::RectMatrix(const matrix& Matr1) const
{
	for (unsigned i = 0; i < Matr1.size(); i++)
		if (Matr1[i].size() != Matr1[0].size()) return false;
	return true;
}
//Проверка матрицы на квадратность
bool Matrix::SquareMatrix(const matrix& Matr1) const
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
		std::cout << std::endl;
	}
}