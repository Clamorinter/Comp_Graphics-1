#include "linegraphics.h"

void lineGraphics::draw() // нарисовать линию
{
		setcolor(color);
		line(A.x, A.y, B.x, B.y);
}

char lineGraphics::method() // метод, возвращающий тип линии
{
	return 'g';
}