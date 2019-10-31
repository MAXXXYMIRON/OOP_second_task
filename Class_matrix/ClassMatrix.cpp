#include "Matrix.h"
using namespace std;

void main()
{
	setlocale(0, "");

	Matrix M = Matrix(5, 5);
	Matrix X = Matrix(5, 5);
	M.FixValue(5);
	X.FixValue(5);


	system("pause");
}