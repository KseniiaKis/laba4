#include "Matrix.h"
#include "Vector.h"

template<typename T>
TMatrix<T>::TMatrix()
{
	this->len = 0;
	this->widht = 0;
	this->data = 0;
}

template<typename T>
TMatrix<T>::~TMatrix()
{
	if (this->data != 0)
		delete[]this->data;
	this->len = 0;
	this->widht = 0;
}

template<typename T>
TMatrix<T>::TMatrix(int n)
{
	if (n > 0)
	{
		len = n;
		widht = n;
		data = new TVector<T>[n];
		for (int i = 0; i < len; i++)
			data[i] = new T [n];
	}
	else
		throw "Eror, n <= 0"
}

template<typename T>
TMatrix<T>::TMatrix(int n, int m)
{
	if (n > 0)&&(m > 0)
	{
		len = n;
		widht = m;
		data = new TVector<T>[m];
		for (int i = 0; i < m; i++)
			data[i] = new T[n];
	}
	else
		throw "Eror, n <= 0 or m <= 0"
}

template<typename T>
TMatrix<T>::TMatrix(const TMatrix& a)
{
	this->len = a.len;
	this->widht = a.widht;
	data = new TVector<T>[widht];
	for (int i = 0; i < widht; i++)
		this->data[i] = a.data[i];
}

template<typename T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix& a)
{
	if (this->widht == a.widht)
	{
		TMatrix res(*this);
		for (int i = 0; i < widht; i++)
			res.data[i] = this->data[i] + a.data[i];
		return res;
	}
	else
		throw "cannot be folded";
}

template<typename T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix& a)
{
	if (this->widht == a.widht)
	{
		TMatrix res(*this);
		for (int i = 0; i < widht; i++)
			res.data[i] = this->data[i] - a.data[i];
		return res;
	}
	else
		throw "cannot be deducted";
}

template<typename T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix& a)
{
	if (this->widht == a.len)&&(this->len == a.widht)
	{
		TMatrix res(widht);
		for (int i = 0; i < len; i++)
			for  (int j = 0; j < len; j++)
			{
				res.data[i][j] = 0;
				for (int x = 0; x < a.len; x++)
				{
					res.data[i][j] = this->data[i][x] + a.data[x][j];
				}
			}
		return res;
	}
	else
		throw "cannot be multiplied";
}

template<typename T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix& a)
{
	this->len = a.len;
	this->widht = a.widht;
	data = new TVector<T>[widht];
	for (int i = 0; i < widht; i++)
		this->data[i] = a.data[i];
}

template<typename T>
bool TMatrix<T>::operator==(const TMatrix& a)
{
	if (this->widht != a.widht)
		return false;
	else
	{
		for (int i = 0; i < a.widht; i++)
			return this->data[i] == a.data[i];
	}
}
