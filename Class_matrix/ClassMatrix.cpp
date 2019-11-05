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
			cout << "Îøèáêà1" << endl;
		}
			break;
		case Matrix::MatricesNotEqual:
		{
			cout << "Îøèáêà2" << endl;
		}
			break;
		case Matrix::LineNotEqualColoumn:
		{
			cout << "Îøèáêà3" << endl;
		}
			break;
		case Matrix::DivByZero:
		{
			cout << "Îøèáêà4" << endl;
		}
			break;
		case Matrix::OffLineIndex:
		{
			cout << "Îøèáêà5" << endl;
		}
			break;
		case Matrix::NotRectMatrix:
		{
			cout << "Îøèáêà6" << endl;
		}
			break;
		case Matrix::NotSquareMatric:
		{
			cout << "Îøèáêà7" << endl;
		}
			break;
		case Matrix::DeterminateIsZero:
		{
			cout << "Îøèáêà8" << endl;
		}
			break;
		default:
			break;
		}
	}

	system("pause");
}