#pragma once
#include <windows.h>
#include <cmath>

#include "graphics.h"
#pragma comment(lib,"graphics.lib")

struct dot { 
	int x = 0;
	int y = 0;
};

class Line { 
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
	dot A; 
	dot B; 
	int color = 0; 
};