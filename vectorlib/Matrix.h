#include "Vector.h"
template <typename T>
class TMatrix:public TVector<T>
{
protected:
	int widht;
	T* data;
public:
	TMatrix();
	~TMatrix();
	TMatrix(int n);
	TMatrix(int n, int m);
	TMatrix(const TMatrix& a);
	TMatrix operator+(const TMatrix& a);
	TMatrix operator-(const TMatrix& a);
	TMatrix operator*(const TMatrix& a);
	TMatrix& operator=(const TMatrix& a);
	bool operator==(const TMatrix& a);
	//void Resize(int NewLen);
};