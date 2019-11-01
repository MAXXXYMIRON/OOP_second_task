#include "Matrix.h"
using namespace std;

void main()
{
	setlocale(0, "");

	Matrix M = Matrix(5, 5);
	Matrix X = Matrix(9, 9);
	M.FixValue(5);
	X.RandValue(0, 5);

	
	X.Display();
	cout << "\n" << X.Detr() << endl;
	X.Inverse();
	X.Display();

	system("pause");
}