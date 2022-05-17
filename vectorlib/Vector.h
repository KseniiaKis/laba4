#pragma once
//�� 15.05.2022 23:59
//�������� ������ ��� ������ � ��������� � ���������, ������������ �������.
//������� � �������������� ��������� : ������� ����� �������� �� N ������� ������������, ����������� �������� ��� ��������.
//������� ������ ���� ����������� �������.
//������ ������� � ������� ������ ���� �������� � ����������� ����������.
//������������������ �� ������ �� �������(�������� � main ������).
//������ ���� :
//��������� ���� � �����;
//������(������� + -*�������), �������� - ���������(������� * ������ � ��������);

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