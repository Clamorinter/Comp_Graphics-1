#pragma once
#include <iostream> 
#include "linegraphics.h" 
#include "linebrezenham.h" 
#include <conio.h> 

class Window
{
public:
	Window(int x, int y); 
	~Window(); 
	void doAKey(char key);
	void doAMouse(dot click);

	void createmode(dot click);
	void choose(dot click);
	void dragmode(dot click);
	void movemode(dot click);

	void draggingOff();
	void movingOff();
	void doAChange();

	bool isDragging();
	bool isMoving();
	bool isChange();
	bool isExit();

	void menu();

private:
	dot A; 
	dot B; 
	bool graphicsflag = false; 
	bool createflag = false; 
	bool Aget = false; 
	bool Bget = false; 
	bool changeflag; 
	bool chooseflag = false; 
	bool moveflag = false; 
	bool dragflag = false; 
	bool menuchange = true; 
	char dots;
	bool exit = false; 
	int choosed; 
	int count = 0; 
	Line** lines = new Line*; 
};
