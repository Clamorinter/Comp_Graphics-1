#pragma once
#include <iostream> // для ввода-вывода в консоль
#include "linegraphics.h" // линия, реализованная с помощью graphics.h
#include "linebrezenham.h" // линия, реализованная с помощью алгоритма Брезенхэма
#include <conio.h> // для неблокирующего ввода

class Window // класс, реализующую окно с возможностями создания, удаления и взаимодействия с линиями
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
	dot A; // первая точка
	dot B; // вторая точка
	bool graphicsflag = false; // флаг, отвечающий за способ создания линии
	bool createflag = false; // флаг, отвечающий за создание линии
	bool Aget = false; // флаг, отвечающий за то, получена ли первая точка
	bool Bget = false; // флаг, отвечающий за то, получена ли вторая точка
	bool changeflag; // флаг, отвечающий за то, произошли ли изменения в итерации
	bool chooseflag = false; // флаг, отвечающий за то, выбрана ли линия/линии
	bool moveflag = false; // флаг, отвечающий за то, выполняется ли передвижение линии
	bool dragflag = false; // флаг, отвечающий за то, перетаскивается ли точка линии
	bool menuchange = true; // флаг, отвечающий за обновление текста в консоли
	char dots;
	bool exit = false; // флаг, отвечающий за то, нужен ли выход из программы
	int choosed; // индекс выбранной линии
	int count = 0; // количество линий
	Line** lines = new Line*; // массив указателей на классы типа Line
};
