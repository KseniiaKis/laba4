#pragma once
#include <iostream>
using namespace std;

template <class T>
class TVector 
{
protected:
  int len;
  T* data;
public:
  TVector();
  TVector(const int n);
  TVector(const int n, const T* _data);
  TVector(const int _len, const T a);
  TVector(const TVector<T>& a);
  ~TVector();

  TVector<T>& operator=(const TVector<T>& a);
  TVector<T> operator+(const TVector<T>& a);
  TVector<T> operator-(const TVector<T>& a);
  TVector<T> operator*(const T a);
  T operator*(const TVector<T>& a);
  TVector<T> operator/(const TVector<T>& a);
  bool operator==(const TVector<T>& a);
  T& operator[](const int n);

  int GetLen() const;
  T GetCoord(const int n) const;
  void SetVector(const int _len, const T* _data);
  void Resize(int NewLen);
  void BubbleSort();
  void InsertSort();
  void QuickSort();

  friend ostream& operator<<(ostream& t, const TVector<T>& a) {
    if (a.GetLen() == 0)
    {
      t << 0 << endl;
      return t;
    }
    for (int i = 0; i < a.GetLen() - 1; i++)
    {
      t << a.GetCoord(i) << ", ";
    }
    t << a.GetCoord(a.GetLen() - 1) << endl;
    return t;
  }

  friend istream& operator>>(istream& t, TVector<T>& v)
  {
    if (v.GetLen() == 0)
      throw "Error: vector == 0";
    for (int i = 0; i < v.GetLen(); i++)
    {
      cout << "Enter vector " << i << " coordinate" << endl;
      t >> v[i];
    }
    return t;
  }

};

template <class T>
TVector<T>::TVector()
{
  len = 0;
  data = 0;
}

template <class T>
TVector<T>::~TVector()
{
  if (data != 0)
  {
    delete[] data;
    data = 0;
  }
}

template<class T>
TVector<T>::TVector(const int n)
{
	if (n >= 0)
	{
		len = n;
		data = new T[len];
		for (int i = 0; i < len; i++)
			data[i] = 0;
	}
	else
		throw "Error, n < 0";
}
template <class T>
TVector<T>::TVector(const int _len, const T* _data)
{
  if ((_len == 0) || (_data == 0))
  {
    TVector();
    return;
  }

  len = _len;
  data = new T[len];

  for (int i = 0; i < len; i++)
  {
    data[i] = _data[i];
  }
}

template<class T>
TVector<T>::TVector(const int n, const T a)
{
  if (n == 0)
  {
    TVector();
    return;
  }
  if (n > 0)
  {
    len = n;
    data = new T[len];
    for (int i = 0; i < len; i++)
      data[i] = a;
  }
  else
    throw "Error, n < 0";
}

template <class T>
TVector<T>::TVector(const TVector<T>& a)
{
  if (a.len == 0)
  {
    TVector();
    return;
  }

  len = a.len;
  data = new T[len];

  for (int i = 0; i < len; i++)
  {
    data[i] = a.GetCoord(i);
  }
}

template<class T>
TVector<T>& TVector<T>::operator=(const TVector<T>& a)
{
	len = a.len;
	if (a.len == 0)
		throw "Error: vector == 0";
  if (data != 0)
    {
      delete[] data;
      data = 0;
    }
	data = new T[len];
	for (int i = 0; i < len; i++)
		data[i] = a.data[i];
	return *this;
}

template<class T>
inline TVector<T> TVector<T>::operator+ (const TVector<T>& a)
{
	if (len != a.GetLen())
		throw "Error, len rasnie";
  TVector<T> res(len);
	for (int i = 0; i < len; i++)
		res[i] = this->data[i] + a.data[i];
	return res;
}

template <class T>
TVector<T> TVector<T>::operator-(const TVector<T>& a)
{
  return ((*this) + a * (-1));
}

template <class T>
TVector<T> TVector<T>::operator*(const T a)
{
  if (len == 0)
    return *this;
  TVector<T> res(len);
  for (int i = 0; i < len; i++)
    res[i] = a * data[i];
  return res;
}

template<class T>
T TVector<T>::operator*(const TVector<T>& a)
{
  if (len != a.GetLen())
    throw "Error: len rasnie";
  if (len == 0)
    throw "Error: len == 0";
  T res = 0;
  for (int i = 0; i < len; i++)
    res += (*this)[i] * a.GetCoord(i);
  return res;
}

template <class T>
TVector<T> TVector<T>::operator/(const TVector<T>& a)
{
  if (len != a.GetLen())
    throw "Error: len rasnie";
  if (len == 0)
    throw "Error: len == 0";
  TVector<T> res(len);
  for (int i = 0; i < len; i++)
  {
    if (a.GetCoord != 0)
      res[i] = data[i] / a.GetCoord(i);
    else res[i] = 0;
  }
  return res;
}

template<class T>
bool TVector<T>::operator==(const TVector<T>& a)
{
	if (len != a.len)
		return false;
	for (int i = 0; i <= a.len; i++)
	{
		if (data[i] != a.data[i])
			return false;
  }
	return true;
}

template <class T>
T& TVector<T>::operator[](const int n)
{
  if ((n < 0) || (n >= len))
  {
    throw "Error: out of tuple range";
  }
  return data[n];
}

template <class T>
int TVector<T>::GetLen() const
{
  return len;
}

template <class T>
T TVector<T>::GetCoord(const int n) const
{
  if (n < 0 || n >= len)
    throw "Error: out of tuple range";
  return data[n];
}

template <class T>
void TVector<T>::SetVector(const int _len, const T* _data)
{
  if (_len == 0)
  {
    if (data != 0)
    {
      delete[] data;
      data = 0;
    }
    return;
  }
  len = _len;
  if (data != 0)
  {
    delete[] data;
    data = 0;
  }
  data = new T[len];
  for (int i = 0; i < len; i++)
    data[i] = _data[i];
}

template<class T>
void TVector<T>::Resize(int NewLen)
{
  if (NewLen < 0)
    throw "Eror len < 0";
  else
  {
    T* t = new T[NewLen];
    for (int i = 0; i < min(NewLen, len); i++)
      t[i] = data[i];
    delete[]data;
    len = NewLen;
    data = t;
  }
}

template <class T>
void TVector<T>::BubbleSort()
{
  T temp;
  for (int i = 0; i < len; i++)
  {
    for (int j = len - 1; j > i; j--)
    {
      if (data[j - 1] > data[j])
      {
        temp = data[j - 1];
        data[j - 1] = data[j];
        data[j] = temp;
      }
    }
  }
}

template <class T>
void TVector<T>::InsertSort()
{
  T temp;
  for (int i = 1; i < len; i++)
  {
    for (int j = i - 1; j >= 0 && data[j] > data[j + 1]; j--)
    {
      temp = data[j + 1];
      data[j + 1] = data[j];
      data[j] = temp;
    }
  }
}

template <class T>
void Quick(T* a, int N)
{
  int i = 0, j = N - 1;
  T temp, p;
  p = a[N >> 1];
  while (i < j)
  {
    while (a[i] < p) i++;
    while (a[j] > p) j--;

    if (i < j)
    {
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
      i++;
      j--;
    }
  }
  if (j > 1) Quick(a, j);
  if (N > i + 1) Quick(a + i, N - i);

}

template <class T>
void TVector<T>::QuickSort()
{
  Quick(data, len);
  return;
}