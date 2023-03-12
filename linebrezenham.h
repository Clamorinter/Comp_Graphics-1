#pragma once
#include "line.h"

class lineBrezenham : public Line 
{
public:
	lineBrezenham(dot A, dot B) : Line(A, B) {};
	void draw();
	char method();
};
