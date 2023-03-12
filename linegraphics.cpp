#include "linegraphics.h"

void lineGraphics::draw() 
{
		setcolor(color);
		line(A.x, A.y, B.x, B.y);
}

char lineGraphics::method() 
{
	return 'g';
}