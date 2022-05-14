#include "Vector.h"
#include "Matrix.h"
int main()
{
	TVector <int> a;
	TVector <int> b(3);
	a = b;
	TVector <int> c(a);
	a = b + c;
	return 0;
	a.~TVector();
	b.~TVector();
	c.~TVector();
	return 0;
}