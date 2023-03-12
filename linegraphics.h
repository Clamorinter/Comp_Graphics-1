#pragma once
#include "line.h"

class lineGraphics : public Line // линия, нарисованная при помощи graphics.h
{
public:
	lineGraphics(dot A, dot B) : Line(A, B) {};
	void draw();
	char method();
};