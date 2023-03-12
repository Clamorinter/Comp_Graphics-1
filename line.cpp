#include "line.h"

Line::Line(dot A, dot B) 
{
	this->A = A; 
	this->B = B;
}

void Line::draw() 
{
	return;
}

char Line::method() 
{
	return ' ';
}

void Line::move(dot start, dot end) 
{
	int dx = end.x - start.x;
	int dy = end.y - start.y;
	A.x = A.x + dx;
	B.x = B.x + dx;
	A.y = A.y + dy;
	B.y = B.y + dy;
}

void Line::dragA(dot A) 
{
	this->A.x = A.x;
	this->A.y = A.y;
}

void Line::dragB(dot B) 
{
	this->B.x = B.x;
	this->B.y = B.y;
}

void Line::rotate(float rad) 
{
	dot center{ (int)round((float)(A.x + B.x) / 2.0), (int)round((float)(A.y + B.y) / 2.0) };
	dot null{ 0, 0 };
	move(center, null);
	int new_ax = (int)round((float)A.x * cos(rad)) + (int)round((float)A.y * sin(rad));
	int new_ay = -(int)round((float)A.x * sin(rad)) + (int)round((float)A.y * cos(rad));

	int new_bx = (int)round((float)B.x * cos(rad)) +(int)round((float)B.y * sin(rad));
	int new_by = -(int)round((float)B.x * sin(rad)) + (int)round((float)B.y * cos(rad));
	A = { new_ax, new_ay };
	B = { new_bx, new_by };
	move(null, center);
}

void Line::changeLength(float dlength) 
{
	dot center{ (int)round((float)(A.x + B.x) / 2.0), (int)round((float)(A.y + B.y) / 2.0) };
	dot null{ 0, 0 };
	float rad = atan((float)abs(A.y - B.y) / (float)abs(A.x - B.x));
	rotate(0.78539 - rad);
	move(center, null);
	dot A_prev = A;
	dot B_prev = B;
	
	A = { (int)round((float)A.x * dlength),  (int)round((float)A.y * dlength) };
	B = { (int)round((float)B.x * dlength),  (int)round((float)B.y * dlength) };
	if (dlength < 1.0)
	{
		if (abs(A.x - A_prev.x) <= 1 || abs(A.y - A_prev.y) <= 1 || abs(B.x - B_prev.x) <= 1 || abs(B.y - B_prev.y) <= 1)
		{
			A = A_prev;
			B = B_prev;
		}
	}
	rotate(rad - 0.78539);
	move(null, center);
}

void Line::setColor(int color) 
{
	this->color = color;
}

bool Line::isinLine(dot X) 
{
	int xx;
	int yy;
	bool ends;
	int er = 10;
	for (int i = X.x - er; i <= X.x + er; i++)
	{
		for (int j = X.y - er; j <= X.y + er; j++)
		{
			xx = (i - A.x) * (B.y - A.y);
			yy = (j - A.y) * (B.x - A.x);
			ends = true;
			if (abs(xx - yy) <= abs(B.y-A.y+B.x-A.x) || abs(xx - yy) <= abs(B.y - A.y - B.x + A.x))
			{
				if (B.x - A.x > er)
				{
					if (X.x < A.x || X.x > B.x)
						ends = false;
				}
				else if (A.x - B.x > er)
					{
						if (X.x > A.x || X.x < B.x)
							ends = false;
					}
				if (B.y - A.y > er)
				{
					if (X.y < A.y || X.y > B.y)
						ends = false;
				}
				else if (A.y - B.y > er)
				{
					if (X.y > A.y || X.y < B.y)
						ends = false;
				}
			}
			else
				ends = false;

			if (ends)
				return ends;
		}
	}
	return ends;
}

char Line::isonEdge(dot X) 
{
	int er = 15;
	for (int i = X.x - er; i <= X.x + er; i++)
	{
		for (int j = X.y - er; j <= X.y + er; j++)
		{
			if (A.x == i && A.y == j)
			{
				return 'A';
			}
			if (B.x == i && B.y == j)
			{
				return 'B';
			}
		}
	}
	return '\0';
}
