#include "Vector.h"
#include "Matrix.h"
#include <iostream>
using namespace std;

int main()
{
	TVector<int> a(2, 3);
	int mas[2] = { 1, -1 };
	TVector<int> b(2, mas);

	TVector<int> c = a + b;
	TMatrix<int> Q(2, 2, 1);
	TMatrix<int> W(2, 2, 1);

	TMatrix<int> C = W * a;
	
	c.QuickSort();
	cout << mas[1] << endl;
	cout << c << endl;
	cout << C << endl;
	cout << Q * C << endl;
}