#pragma once
#include<iostream>
#include <vector>

typedef std::vector<std::vector<double>> matrix;

class Matrix
{
private:
	matrix Matr;
public:
	//������������ ������
	Matrix();
	~Matrix();
	Matrix(unsigned Row, unsigned Col);

	//�������� ��� ���������� ��. �������
	double GetIndex(unsigned n, unsigned m);
	void SetIndex(unsigned n, unsigned m, double Value);

	//������� �������� ��. �������
	//��� ��. ����� ���������
	void FixValue(double Value);
	//������� � ������ ����� ��������� �������� ��� ��. �������
	//��� ��. ������
	void RandValue(int FirstLim, int LastLim);

	//�������� ��������� �������� ����� �������
	Matrix operator + (const Matrix& Matr2) const;
	Matrix operator - (const Matrix& Matr2) const;
	Matrix operator * (const Matrix& Matr2) const;

	//�������� ��������� �������� ����� �������
	Matrix Add(double Value);
	Matrix Sub(double Value);
	Matrix Mul(double Value);
	Matrix Div(double Value);

	//������� ������� ������������� � �����������������, ��� ������������, ��� ��������
	void Transpose();
	void Diagonal();
	void Inverse();
	//������ ������������ �������, ���� �� - ����������
	double Detr();

	//�������� ��� ���������� ������ �������
	std::vector<double> GetString(unsigned Row);
	void SetString(unsigned Row, std::vector<double> Str);

	//���������� �������� ������� � ������� �������
	void operator += (const Matrix& Matr2);
	void operator -= (const Matrix& Matr2);
	void operator *= (const Matrix& Matr2);

	//���������� �������� ������� � ������� �������
	void operator += (double Value);
	void operator -= (double Value);
	void operator *= (double Value);
	void operator /= (double Value);

	void Display();

private:
	//�������� �� �� ����� ������� �� ������� �������
	bool WithinBorders(unsigned IndexRow, unsigned IndexCol);
	//�������� �� ���������� ������
	bool EqualMatrix(matrix Matr1, matrix Matr2) const;
	//�������� �� ��������� ������ �������
	bool EqualRowCol(matrix Matr1, matrix Matr2) const;
	//�������� �� �� ������������� �������
	bool RectMatrix(matrix Matr1) const;
	//�������� ������� �� ������������
	bool SquareMatrix(matrix Matr1);
};

