#pragma once
#include<iostream>
#include<fstream>
#include <iostream>
#include <string>
#include <map>
#include <set>

enum Facet
{
	Top = 0,
	Bottom = 1,
	Forward = 2,
	Back = 3,
	Left = 4,
	Right = 5
};

enum Color
{
	R = 0,
	B,
	Y,
	O,
	G,
	W
};

class Cube
{
	char colors[6] = { 'R', 'O', 'Y', 'W', 'G', 'B' };
	char cube[6][3][3];
	void turn_matrix(int facet, bool cw);
	char colors[6] = { 'R', 'B', 'Y', 'O', 'G', 'W' };
	std::map<std::set<char>, int> centerCubes = { {{'R','O'}, 0}, {{'B','G'}, 0}, {{'Y','W'}, 0} };

	std::map<std::set<char>, int> middleCubes = { {{'R','B'}, 0}, {{'B','Y'}, 0}, {{'Y','O'}, 0},
												  {{'O','G'}, 0}, {{'G','W'}, 0}, {{'W','R'}, 0},
												  {{'R','Y'}, 0}, {{'B','O'}, 0}, {{'Y','G'}, 0},
												  {{'O','W'}, 0}, {{'G','R'}, 0}, {{'B','W'}, 0}
	};

	std::map<std::string, int> cornerCubes = { {{'W','G','O'}, 0}, {{'G','O','Y'}, 0},
											   {{'O','Y','B'}, 0}, {{'Y','B','R'}, 0},
											   {{'B','R','W'}, 0}, {{'R','W','G'}, 0},
											   {{'W','O','B'}, 0}, {{'G','Y','R'}, 0}
	};

	Color cube[6][3][3];
	void turnMatrix(int matrixIndex, bool isClockwise = true);
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
Повороты:

1) F > front - фронтальная или фасад по часовой стрелке.

2) B > back - задняя или тыльная сторона по часовой стрелке. 
Поворачивается так, как будто сторона повернута к вам!

3) L > left - левая сторона по часовой стрелке.

4) R > right - правая сторона по часовой стрелке.

5) U > up - верхняя сторона по часовой стрелке.

6) D > down - нижнюю сторону по часовой стрелке.

7) M > middle - средний слой, находящийся между правой (R) и левой (L) гранями, поворачиваем вниз(вращаем по часовой стрелке).

8) M` > middle - средний слой, находящийся между правой (R) и левой (L) гранями, поворачиваем вверх(вращаем против часовой стрелке).

9) S > standing - средний слой, находящийся между фронтальной (F) и задней (B) сторонами, по часовой стрелке.

10) S`> standing - средний слой, находящийся между фронтальной и задней сторонами, против часовой стрелки.

11) E > equatorial - средний слой, находящийся между верхней (U) и нижней (D) сторонами, поворачиваем влево(вращать по часовой стрелке, если смотреть сверху на куб). 

12) E`> equatorial - средний слой, находящийся между верхней и нижней сторонами,  поворачиваем вправо(вращать против часовой стрелке, если смотреть сверху на куб).



*/