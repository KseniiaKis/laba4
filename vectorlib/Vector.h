#pragma once
//до 15.05.2022 23:59
//Написать классы для работы с векторами и матрицами, использовать шаблоны.
//Вектора в математическом понимании : имеется набор значений из N мерного пространства, размерность задается как параметр.
//Матрица должна быть наследником вектора.
//Классы вектора и матрицы должны быть вынесены в статическую библиотеку.
//Продемонстрировать их работу на примере(написать в main пример).
//Должны быть :
//потоковый ввод и вывод;
//матриц(матрица + -*матрица), матрично - векторные(матрица * вектор и наоборот);

template <typename T>
class TVector
{
protected:
	int len;
	T* data;
public:
	TVector();
	~TVector();
	TVector(int n);
	TVector(const TVector &a);

	TVector operator+(const TVector &a);
	TVector operator-(const TVector &a);
	TVector operator*(const TVector &a);
	TVector operator/(const TVector &a);
	TVector & operator=(const TVector &a);
	bool operator==(const TVector &a);
	T& operator[](int a);
	int GetLen();
	void Resize(int NewLen);
};