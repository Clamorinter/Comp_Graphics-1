#pragma once
#include "line.h"

class lineBrezenham : public Line // линия, нарисованная при помощи алгоритма Брезенхэма
{
public:
	lineBrezenham(dot A, dot B) : Line(A, B) {};
	void draw();
	char method();
};
