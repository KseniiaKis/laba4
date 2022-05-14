#include "Vector.h"

template<class T>
TVector<T>::TVector()
{
	this->len = 0;
	this->data = 0;
}

template<class T>
TVector<T>::~TVector()
{
	if (data != 0)
	{
		delete[] data;
		data = 0;
		len = 0;
	}
}

template<class T>
TVector<T>::TVector(int n)
{
	if (n >= 0)
	{
		len = n;
		data = new T[len];
		for (int i = 0; i < len; i++)
			data[i] = 0;
	}
	else
		throw "Eror, n < 0";
}

template<class T>
TVector<T>::TVector(const TVector<T>& a)
{
	len = a.len;
	if (a.len == 0)
		this->data = 0;
	else
	{
		this->data = new T[len];
		for (int i = 0; i <= len; i++)
			this->data[i] = a.data[i];
	}
}

template<class T>
inline TVector<T> TVector<T>::operator+(const TVector<T>& a)
{
	TVector<T> res;
	if (this->len != a.len)
		throw "eror, len rasnie";
	if ((this->len == 0) && (a.len == 0))
	{
		res.len = 0;
		res.data = 0;
	}
	else
	{
		res.len = a.len
			res.data = new T[res.len];
		for (int i = 0; i <= res.len; i++)
			res[i] = this->data[i] + a.data[i];
	}
	return res;
}

template<class T>
TVector<T> TVector<T>::operator-(const TVector<T>& a)
{
	TVector<T> res;
	if (this->len != a.len)
		throw "eror, len rasnie";
	if ((this->len == 0) && (a.len == 0))
	{
		res.len = 0;
		res.data = 0;
	}
	else
	{
		res.len = a.len
			res.data = new T[res.len];
		for (int i = 0; i <= res.len; i++)
			res[i] = this->data[i] - a.data[i];
	}
	return res;
}

template<class T>
TVector<T> TVector<T>::operator*(const TVector<T>& a)
{
	TVector<T> res;
	if (this->len != a.len)
		throw "eror, len rasnie";
	if ((this->len == 0) && (a.len == this->len))
	{
		res.len = 0;
		res.data = 0;
	}
	else
	{
		res.len = a.len
			res.data = new T[res.len];
		for (int i = 0; i <= res.len; i++)
			res[i] = this->data[i] * a.data[i];
	}
	return res;
}

template<class T>
TVector<T> TVector<T>::operator/(const TVector<T>& a)
{
	TVector<T> res;
	if (this->len != a.len)
		throw "eror, len rasnie";
	if (a.len == 0)
		throw "eror, na 0 delit nelsy";
	if (this->len == 0 && a.len != 0)
	{
		res.len = 0;
		res.data = 0;
	}
	else
	{
		res.len = a.len
			res.data = new T[res.len];
		for (int i = 0; i <= res.len; i++)
			res[i] = this->data[i] / a.data[i];
	}
	return res;
}

template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& a)
{
	this->len = a.len;
	if (a.len == 0)
		this->data = 0;
	else
	{
		this->data = new T[len];
		for (int i = 0; i <= len; i++)
			this->data[i] = a.data[i];
	}
}

template<class T>
bool TVector<T>::operator==(const TVector<T>& a)
{
	if (this->len !=a.len)
		return false;
	else
	{
		for (int i = 0; i <= a.len; i++)
		{
			if (this->data[i] != a.data[i])
				return false;
			else
				return true;
		}
	}
}

template<class T>
T& TVector<T>::operator[](int a)
{
	T res;
	res = data[a];
	retern res;
}

template<class T>
int TVector<T>::GetLen()
{
	return this->len;
}

template<class T>
void TVector<T>::Resize(int NewLen)
{
	if (NewLen < 0)
		throw "Eror len < 0";
	else
	{
		T* t = new T[NewLen];
		for (int i = 0; i < min(NewLen, this->len); i++)
			t[i] = this->data[i];
		delete[]this->data;
		this->len = NewLen;
		this->data = t;
	}
}
