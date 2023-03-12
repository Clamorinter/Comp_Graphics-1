#pragma once
#include <windows.h>
#include <cmath>

#include "graphics.h"
#pragma comment(lib,"graphics.lib")

struct dot { // структура, представляю собой точку с двумя координатами
	int x = 0;
	int y = 0;
};

class Line { // класс, представляющий собой линию
public:
	Line(dot A, dot B);
	void move(dot start, dot end);
	void dragA(dot A);
	void dragB(dot B);
	void rotate(float rad);
	void changeLength(float dlength);
	virtual void draw();

	void setColor(int color);

	bool isinLine(dot X);
	char isonEdge(dot X);

	virtual char method();
protected:
	dot A; // первая точка линии
	dot B; // вторая точка линии
	int color = 0; // цвет линии
};