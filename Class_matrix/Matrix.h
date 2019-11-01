#pragma once
#include<iostream>
#include <vector>
#include <math.h>
#include <ctime>

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
	Matrix Add(double Value) const;
	Matrix Sub(double Value) const;
	Matrix Mul(double Value) const;
	Matrix Div(double Value) const;

	//������� ������� ������������� � �����������������, ��� ������������, ��� ��������
	void Transpose();
	void Diagonal();
	void Inverse();
	//������ ������������ �������, ���� �� - ����������
	double Detr() const;

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
	bool EqualMatrix(const matrix& Matr1, const matrix& Matr2) const;
	//�������� �� ��������� ������ �������
	bool EqualRowCol(const matrix& Matr1, const matrix& Matr2) const;
	//�������� �� �� ������������� �������
	bool RectMatrix(const matrix& Matr1) const;
	//�������� ������� �� ������������
	bool SquareMatrix(const matrix& Matr1) const;

	//������������ ������� 2 �� 2
	double Detr(const matrix& M) const;
	//���������� ������������� ������� �������
	double Detr(const matrix& M, unsigned Row, unsigned Col) const;

	//�������� �� ��������� ������������� ������, ��� ���������� �������� �������
	bool RepeatUsedLine(const std::vector<double>& ArrayIndexLine, unsigned IndexLine);
	//������� ������ ������� �� �����
	std::vector<double> LineDivNumber(const std::vector<double>& Line, double Number);
	//��������� �����, ���� �� ������� ��������� �� Index ��. ������
	std::vector<double> SubLine(const std::vector<double>& Line1, const std::vector<double>& Line2, unsigned Index);
	//������������ ��������� �������
	void Unit(matrix& Matr1);
};
