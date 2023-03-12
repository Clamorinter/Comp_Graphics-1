#pragma once
#include "line.h"

class lineGraphics : public Line 
{
public:
	lineGraphics(dot A, dot B) : Line(A, B) {};
	void draw();
	char method();
};