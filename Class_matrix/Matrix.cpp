#include "Matrix.h"

//������������ ������
Matrix::Matrix()
{
}
Matrix::~Matrix()
{
}
Matrix::Matrix(unsigned Row, unsigned Col)
{

}




//�������� ��� ���������� ��. �������
double Matrix::GetIndex(unsigned n, unsigned m)
{

}
void Matrix::SetIndex(unsigned n, unsigned m, double Value)
{

}




//������� �������� ��. �������
//��� ��. ����� ���������
void Matrix::FixValue(double Value)
{

}
//������� � ������ ����� ��������� �������� ��� ��. �������
//��� ��. ������
void Matrix::RandValue(int FirstLim, int LastLim)
{

}




//�������� ��������� �������� ����� �������
Matrix Matrix::operator + (const Matrix& Matr2) const
{

}
Matrix Matrix::operator - (const Matrix& Matr2) const
{

}
Matrix Matrix::operator * (const Matrix& Matr2) const
{

}




//�������� ��������� �������� ����� �������
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




//������� ������� ������������� � �����������������, ��� ������������, ��� ��������
void Matrix::Transpose()
{

}
void Matrix::Diagonal()
{

}
void Matrix::Revers()
{

}

//������ ������������ �������, ���� �� - ����������
double Matrix::Detr()
{

}




//�������� ��� ���������� ������ �������
std::vector<double> Matrix::GetString(unsigned Row)
{

}
void Matrix::SetString(unsigned Row, std::vector<double> Str)
{

}




//���������� �������� ������� � ����� �������
void Matrix::operator += (const Matrix& Matr2)
{

}
void Matrix::operator -= (const Matrix& Matr2)
{

}
void Matrix::operator *= (const Matrix& Matr2)
{

}




//���������� �������� ������� � ����� �������
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
