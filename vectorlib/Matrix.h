#pragma once
#include "Vector.h"

template <class T>
class TMatrix : public TVector<T> 
{
protected:
  int rowsCount;
  int columnsCount;
  TVector<T>* columns;
public:
  TMatrix();
  TMatrix(const int _rowsCount, const int _columnsCount, const T a);
  TMatrix(const int _columnsCount, const TVector<T>* _columns);
  TMatrix(const int _columnsCount, const TVector<T>& _column);
  TMatrix(const TMatrix<T>& obj);
  TMatrix(const TVector<T>& vect);
  ~TMatrix();

  bool operator==(const TMatrix<T>& m);
  TMatrix<T>& operator=(const TMatrix<T>& m);
  TVector<T>& operator[](const int indx);
  TMatrix<T> operator+(const TMatrix<T>& m);
  TMatrix<T> operator-(const TMatrix<T>& m);
  TMatrix<T> operator*(const TMatrix<T>& m);
  TMatrix<T> operator*(const T a);
  TVector<T> operator*(const TVector<T>& v);

  T GetElem(const int row, const int column) const;
  int GetRowsCount() const;
  int GetColumnsCount() const;
  TVector<T> GetVector(int column) const;
  void SetElem(const int row, const int column, T a);
  void SetMatrix(const int _columnsCount, const TVector<T>* _columns);
  void Transp();

  friend ostream& operator<<(ostream& t, const TMatrix<T>& m)
  {
    if (m.GetColumnsCount() == 0)
      throw "Error: cannot print 0-matrix";

    for (int i = 0; i < m.GetRowsCount(); i++)
    {
      for (int j = 0; j < m.GetColumnsCount(); j++)
        t << m.GetElem(i, j) << ' ';
      t << '\n';
    }
    return t;
  }
  friend istream& operator>>(istream& t, const TMatrix<T>& m)
  {
    if (m.GetColumnsCount() == 0)
      throw "Error: cannot write in 0-matrix";

    for (int i = 0; i < m.GetRowsCount(); i++)
    {
      for (int j = 0; j < m.GetColumnsCount(); j++)
      {
        cout << "Enter (" << j << ", " << i << ") element:" << endl;
        t >> m[j][i];
      }
    }
    return t;
  }
};

template <class T>
TMatrix<T>::TMatrix()
{
  rowsCount = 0;
  columnsCount = 0;
  columns = 0;
}

template <class T>
TMatrix<T>::~TMatrix()
{
  if (columns != 0)
  {
    delete[] columns;
    columns = 0;
  }
}

template <class T>
TMatrix<T>::TMatrix(const int _rowsCount, const int _columnsCount, const T a)
{
  if (_rowsCount == 0 || _columnsCount == 0)
  {
    TMatrix();
    return;
  }

  rowsCount = _rowsCount;
  columnsCount = _columnsCount;
  columns = new TVector<T>[columnsCount];

  for (int i = 0; i < columnsCount; i++)
      columns[i] = TVector<T>(rowsCount, a);
}

template <class T>
TMatrix<T>::TMatrix(const int _columnsCount, const TVector<T>* _columns)
{
  if (_columnsCount == 0 || _columns == 0)
  {
    TMatrix();
    return;
  }

  columnsCount = _columnsCount;
  rowsCount = _columns[0].GetLen();
  columns = new TVector<T>[columnsCount];

  for (int i = 0; i < columnsCount; i++)
    columns[i] = _columns[i];
}

template <class T>
TMatrix<T>::TMatrix(const int _columnsCount, const TVector<T>& _column)
{
  if (_columnsCount == 0 || _column.GetLen() == 0)
  {
    TMatrix();
    return;
  }

  columnsCount = _columnsCount;
  rowsCount = _column.GetLen();
  columns = new TVector<T>[columnsCount];

  for (int i = 0; i < columnsCount; i++)
    columns[i] = _column;
}

template <class T>
TMatrix<T>::TMatrix(const TMatrix<T>& obj)
{
  if (obj.columnsCount == 0)
  {
    TMatrix();
    return;
  }

  columnsCount = obj.columnsCount;
  rowsCount = obj.rowsCount;
  columns = new TVector<T>[columnsCount];

  for (int i = 0; i < columnsCount; i++)
    columns[i] = obj.columns[i];
}

template <class T>
TMatrix<T>::TMatrix(const TVector<T>& vect)
{
  if (vect.GetLen() == 0)
  {
    TMatrix();
    return;
  }
  columnsCount = 1;
  rowsCount = vect.GetLen();
  columns = new TVector<T>[1];
  columns[0] = vect;
}
template <class T>
bool TMatrix<T>::operator==(const TMatrix<T>& m)
{
  if (columnsCount == m.GetColumnsCount() && rowsCount == m.GetRowsCount())
  {
    for (int i = 0; i < columnsCount; i++)
    {
      if (columns[i] != m.GetVector(i))
        return false;
    }
    return true;
  }
  return false;
}

template <class T>
TMatrix<T>& TMatrix<T>::operator=(const TMatrix<T>& m)
{
  if (m.GetColumnsCount == 0 || m.GetRowsCount() == 0)
    throw "Error: matrix=0-matrix";

  columnsCount = m.GetColumnsCount();
  rowsCount = m.GetRowsCount();
  if (columns != 0)
  {
    delete[] columns;
    columns = 0;
  }
  columns = new TVector<T>[columnsCount];

  for (int i = 0; i < columnsCount; i++)
    columns[i] = m.GetVector(i);

  return *this;
}

template <class T>
TVector<T>& TMatrix<T>::operator[](const int indx)
{
  if (indx < 0 || indx >= columnsCount)
    throw "Error: run out of matrix range";
  return columns[indx];
}

template <class T>
TMatrix<T> TMatrix<T>::operator+(const TMatrix<T>& m)
{
  if (m.GetColumnsCount() != columnsCount || m.GetRowsCount() != rowsCount)
    throw "Error: different matrix size in +";

  TMatrix<T> temp(columnsCount, rowsCount, 0);

  for (int i = 0; i < columnsCount; i++)
    temp[i] = this->GetVector(i) + m.GetVector(i);
  return temp;
}

template <class T>
TMatrix<T> TMatrix<T>::operator-(const TMatrix<T>& m)
{
  if (m.GetColumnsCount() != columnsCount || m.GetRowsCount() != rowsCount)
    throw "Error: different matrix size in +";

  TMatrix<T> temp(columnsCount, rowsCount, 0);

  for (int i = 0; i < columnsCount; i++)
    temp[i] = this->GetVector(i) - m.GetVector();
  return temp;
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const T a)
{
  TMatrix<T> temp = this;

  for (int i = 0; i < columnsCount; i++)
    temp[i] = temp[i] * a;
  return temp;
}

template <class T>
TMatrix<T> TMatrix<T>::operator*(const TMatrix<T>& m)
{
  if (columnsCount != m.GetRowsCount())
    throw "Error: cannot multiply matrix (invalid size)";

  TMatrix<T> temp(m.GetColumnsCount(), rowsCount, 0);

  for (int k = 0; k < rowsCount; k++)
  {
    for (int j = 0; j < m.GetColumnsCount(); j++)
    {
      for (int i = 0; i < columnsCount; i++)
        temp[j][k] += this->GetElem(k, i) * m.GetElem(i, j);
    }
  }
  return temp;
}

template <class T>
TVector<T> TMatrix<T>::operator*(const TVector<T>& v)
{
  if (v.GetLen() != columnsCount)
    throw "Error: cannot muiltiply matrix*vector (invalid size)";

  TVector<T> temp(rowsCount);
  for (int i = 0; i < rowsCount; i++)
  {
    for (int j = 0; j < v.GetLen(); j++)
      temp[i] += this->GetElem(i, j) * v.GetCoord(j);
  }
  return temp;
}

template <class T>
int TMatrix<T>::GetRowsCount() const
{
  return rowsCount;
}
template <class T>
int TMatrix<T>::GetColumnsCount() const
{
  return columnsCount;
}

template <class T>
T TMatrix<T>::GetElem(const int row, const int column) const
{
  if (row < 0 || row >= rowsCount || column < 0 || column >= columnsCount)
    throw "Error: run out of matrix range";
  return columns[column][row];
}

template <class T>
TVector<T> TMatrix<T>::GetVector(int column) const
{
  if (column < 0 || column >= columnsCount)
    throw "Error: run out of matrix range";
  return columns[column];
}

template <class T>
void TMatrix<T>::SetElem(const int row, const int column, T a)
{
  if (row < 0 || row >= rowsCount || column < 0 || column >= columnsCount)
    throw "Error: out of matrix range";
  columns[column][row] = a;
  return;
}

template <class T>
void TMatrix<T>::SetMatrix(const int _columnsCount, const TVector<T>* _columns)
{
  if (_columnsCount == 0 || _columns == 0)
  {
    columnsCount = 0;
    rowsCount = 0;
    if (columns != 0)
    {
      delete[] columns;
      columns = 0;
    }
  }

  columnsCount = _columnsCount;
  rowsCount = _columns[0].GetLen();
  if (columns != 0)
  {
    delete[] columns;
    columns = 0;
  }
  columns = new TVector<T>[columnsCount];

  for (int i = 0; i < columnsCount; i++)
      columns[i] = _columns[i];
}

template <class T>
void TMatrix<T>::Transp()
{
  if (columns == 0)
    return;
  int tm;
  tm = columnsCount;
  columnsCount = rowsCount;
  rowsCount = tm;
  TVector<T>* temp = new TVector<T>[columnsCount];

  for (int i = 0; i < rowsCount; i++)
  {
    for (int j = 0; j < columnsCount; j++)
      temp[i][j] = columns[j][i];
  }

  delete[] columns;
  columns = new TVector<T>[columnsCount];
  for (int i = 0; i < columnsCount; i++)
    columns[i] = temp[i];
  return;
}