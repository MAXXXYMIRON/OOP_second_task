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
	void Revers();
	//������ ������������ �������, ���� �� - ����������
	double Detr();

	//�������� ��� ���������� ������ �������
	std::vector<double> GetString(unsigned Row);
	void SetString(unsigned Row, std::vector<double> Str);

	//���������� �������� ������� � ����� �������
	void operator += (const Matrix& Matr2);
	void operator -= (const Matrix& Matr2);
	void operator *= (const Matrix& Matr2);

	//���������� �������� ������� � ����� �������
	void operator += (double Value);
	void operator -= (double Value);
	void operator *= (double Value);
	void operator /= (double Value);
};

