#include "linebrezenham.h"

void lineBrezenham::draw() 
{
	int deltax = abs(B.x - A.x);
	int deltay = abs(B.y - A.y);
	int error = 0;
	if (deltax > deltay)
	{
		int deltaErr = (deltay + 1);
		int y = A.y;
		int diry = B.y - A.y;
		if (diry > 0)
		{
			diry = 1;
		}
		if (diry < 0)
		{
			diry = -1;
		}
		if (B.x < A.x)
		{
			for (int x = A.x; x >= B.x; x--)
			{
				putpixel(x, y, color);
				error = error + deltaErr;
				if (error >= (deltax + 1))
				{
					y = y + diry;
					error = error - (deltax+1);
				}
			}
		}
		else {
			for (int x = A.x; x <= B.x; x++)
			{
				putpixel(x, y, color);
				error = error + deltaErr;
				if (error >= (deltax+1))
				{
					y = y + diry;
					error = error - (deltax+1);
				}
			}
		}
	}
	else
	{
		int deltaErr = (deltax + 1);
		int x = A.x;
		int dirx = B.x - A.x;
		if (dirx > 0)
		{
			dirx = 1;
		}
		if (dirx < 0)
		{
			dirx = -1;
		}
		if (B.y < A.y)
		{
			for (int y = A.y; y >= B.y; y--)
			{
				putpixel(x, y, color);
				error = error + deltaErr;
				if (error >= (deltay+1))
				{
					x = x + dirx;
					error = error - (deltay+1);
				}
			}
		}
		else {
			for (int y = A.y; y <= B.y; y++)
			{
				putpixel(x, y, color);
				error = error + deltaErr;
				if (error >= (deltay+1))
				{
					x = x + dirx;
					error = error - (deltay+1);
				}
			}
		}
	}
	
}

char lineBrezenham::method() 
{
	return 'b';
}