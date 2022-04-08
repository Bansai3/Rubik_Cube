#pragma once
#include<iostream>
#include<fstream>
#include <iostream>

enum Facet
{
	Top = 0,
	Botton,
	Forward,
	Back,
	Left,
	Right
};

enum Color
{
	R = 0,
	O,
	Y,
	G,
	B,
	W
};

class Cube
{
	char colors[6] = { 'R', 'O', 'Y', 'W', 'G', 'B' };
	char cube[6][3][3];
	void turn_matrix(int facet, bool cw);

public:
	Cube();
	bool checkState();
	friend std::ostream& operator<<(std::ostream& out, Cube& cube);
	void load_from_file(std::string filename);
	void F(bool cw = true);
	void B(bool cw = true);
	void L(bool cw = true);
	void R(bool cw = true);
	void U(bool cw = true);
	void D(bool cw = true);
	void Mixing();


};

/*
��������:

1) F > front - ����������� ��� ����� �� ������� �������.

2) B > back - ������ ��� ������� ������� �� ������� �������. 
�������������� ���, ��� ����� ������� ��������� � ���!

3) L > left - ����� ������� �� ������� �������.

4) R > right - ������ ������� �� ������� �������.

5) U > up - ������� ������� �� ������� �������.

6) D > down - ������ ������� �� ������� �������.

7) M > middle - ������� ����, ����������� ����� ������ (R) � ����� (L) �������, ������������ ����(������� �� ������� �������).

8) M` > middle - ������� ����, ����������� ����� ������ (R) � ����� (L) �������, ������������ �����(������� ������ ������� �������).

9) S > standing - ������� ����, ����������� ����� ����������� (F) � ������ (B) ���������, �� ������� �������.

10) S`> standing - ������� ����, ����������� ����� ����������� � ������ ���������, ������ ������� �������.

11) E > equatorial - ������� ����, ����������� ����� ������� (U) � ������ (D) ���������, ������������ �����(������� �� ������� �������, ���� �������� ������ �� ���). 

12) E`> equatorial - ������� ����, ����������� ����� ������� � ������ ���������,  ������������ ������(������� ������ ������� �������, ���� �������� ������ �� ���).



*/