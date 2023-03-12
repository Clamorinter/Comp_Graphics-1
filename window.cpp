#include "Window.h"

Window::Window(int x, int y) // инициализация окна с названием "lines" и белым фоном
{
	initwindow(x, y, "lines");

	setbkcolor(15);
	cleardevice();
}

Window::~Window() // удаление окна, очистка памяти
{
	closegraph();
	for (int i = 0; i < count; i++)
	{
		delete lines[i];
	}
	delete[] lines;
}

void Window::doAKey(char key) // ответ окна в ответ на нажатую пользователем клавишу
{
	switch (key)
	{
	case 'g':
		graphicsflag = true;
		createflag = true;
		menuchange = true;
		break;
	case 'b':
		graphicsflag = false;
		createflag = true;
		menuchange = true;
		break;
	case 'l':
		if (createflag)
		{
			std::cout << std::endl << "Enter coordinates of first dot: ";
			std::cin >> A.x >> A.y;
			createmode(A);
			std::cout << "Enter coordinates of second dot: ";
			std::cin >> B.x >> B.y;
			createmode(B);
			menuchange = true;
		}
		break;
	case '\\':
		if (chooseflag)
		{
			if (choosed != -1)
			{
				delete lines[choosed];
				count--;
				Line** buff = new Line * [count];
				int counter = 0;
				for (int i = 0; i < count + 1; i++)
				{
					if (i != choosed)
					{
						buff[counter] = lines[i];
						counter++;
					}
				}
				delete[] lines;
				lines = buff;
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					delete lines[i];
				}
				count = 0;
			}
			changeflag = true;
			chooseflag = false;
			menuchange = true;
		}
		break;
	case 'w':
		if (chooseflag && !createflag)
		{
			A = { 0, 10 };
			B = { 0, 5 };
			if (choosed != -1)
			{
				lines[choosed]->move(A, B);
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					lines[i]->move(A, B);
				}
			}
			changeflag = true;
		}
		break;
	case 's':
		if (chooseflag && !createflag)
		{
			A = { 0, 5 };
			B = { 0, 10 };
			if (choosed != -1)
			{
				lines[choosed]->move(A, B);
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					lines[i]->move(A, B);
				}
			}
			changeflag = true;
		}
		break;
	case 'd':
		if (chooseflag && !createflag)
		{
			A = { 0, 0 };
			B = { 5, 0 };
			if (choosed != -1)
			{
				lines[choosed]->move(A, B);
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					lines[i]->move(A, B);
				}
			}
			changeflag = true;
		}
		break;
	case 'a':
		if (chooseflag && !createflag)
		{
			A = { 10, 0 };
			B = { 5, 0 };
			if (choosed != -1)
			{
				lines[choosed]->move(A, B);
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					lines[i]->move(A, B);
				}
			}
			changeflag = true;
		}
		break;
	case 'q':
		if (chooseflag)
		{
			if (choosed != -1)
			{
				lines[choosed]->rotate((float)0.02);
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					lines[i]->rotate((float)0.02);
				}
			}
			changeflag = true;
		}
		break;
	case 'e':
		if (chooseflag)
		{
			if (choosed != -1)
			{
				lines[choosed]->rotate((float)-0.02);
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					lines[i]->rotate((float)-0.02);
				}
			}
			changeflag = true;
		}
		break;
	case '=':
		if (chooseflag && !createflag)
		{
			if (choosed != -1)
			{
				lines[choosed]->changeLength((float)1.05);
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					lines[i]->changeLength((float)1.05);
				}
			}
			changeflag = true;
		}
		break;
	case '-':
		if (chooseflag && !createflag)
		{
			if (choosed != -1)
			{
				lines[choosed]->changeLength((float)(20.0 / 21.0));
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					lines[i]->changeLength((float)(20.0 / 21.0));
				}
				
			}
			changeflag = true;
		}
		break;
	case 'f':
		if (choosed != 0 && chooseflag && !createflag)
		{
			if (choosed != -1)
			{
				lines[choosed--]->setColor(0);
				lines[choosed]->setColor(9);
			}
			else {
				for (int i = 0; i < count; i++)
				{
					lines[i]->setColor(0);
				}
				choosed = count - 1;
				lines[choosed]->setColor(9);
			}
			menuchange = true;
			changeflag = true;
		}
		if (!createflag && !chooseflag && count != 0)
		{
			choosed = count - 1;
			lines[choosed]->setColor(9);
			chooseflag = true;
			menuchange = true;
			changeflag = true;
		}
		break;
	case 'r':
		if (choosed != count - 1 && chooseflag && !createflag)
		{
			if (choosed != -1)
			{
				lines[choosed++]->setColor(0);
				lines[choosed]->setColor(9);
			}
			else
			{
				for (int i = 0; i < count; i++)
				{
					lines[i]->setColor(0);
				}
				choosed = 0;
				lines[choosed]->setColor(9);
			}
			menuchange = true;
			changeflag = true;
		}
		if (!createflag && !chooseflag && count != 0)
		{
			choosed = 0;
			lines[choosed]->setColor(9);
			chooseflag = true;
			menuchange = true;
			changeflag = true;
		}
		break;
	case '`':
		changeflag = true;
		choosed = -1;
		for (int i = 0; i < count; i++)
		{
			lines[i]->setColor(9);
		}
		menuchange = true;
		break;
	case '0':
		exit = true;
		break;
	}
}

void Window::doAMouse(dot click) // реагирование на нажатие левой кнопки мыши пользователем
{
	if (createflag && !moveflag && !dragflag)
	{
		createmode(click);
	}
	if (!createflag && !moveflag && !dragflag)
	{
		choose(click);
	}
	if (!moveflag && !createflag && chooseflag && choosed != -1)
	{
		dragmode(click);
	}
	if (!createflag && chooseflag && !dragflag && choosed != -1)
	{
		movemode(click);
	}
}

void Window::createmode(dot click) // создание новой линии
{
	if (!Aget)
	{
		A.x = click.x;
		A.y = click.y;
		Aget = true;
		menuchange = true;
	}
	else if (!Bget)
	{
		B.x = click.x;
		B.y = click.y;
		if (B.x != A.x || B.y != A.y)
		{
			Bget = true;
			menuchange = true;
		}
	}
	if (Aget && Bget)
	{
		count++;
		Line** buff = new Line * [count];
		if (count > 1)
		{
			memcpy(buff, lines, sizeof(Line*) * (count - 1));
			delete[] lines;
		}
		lines = buff;
		if (graphicsflag)
		{
			lines[count - 1] = new lineGraphics(A, B);
		}
		else
		{
			lines[count - 1] = new lineBrezenham(A, B);
		}
		createflag = false;
		Aget = false;
		Bget = false;
		changeflag = true;
	}
}

void Window::choose(dot click) // выбор линии
{
	int er = 2;
	A = { click.x, click.y };
	for (int f = 0; f < count; f++)
	{
		if (lines[f]->isinLine(A))
		{
			if (chooseflag)
			{
				if (choosed != f)
				{
					if (choosed != -1)
					{
						lines[choosed]->setColor(0);
					}
					else
					{
						for (int i = 0; i < count; i++)
						{
							lines[i]->setColor(0);
						}
					}
				}
				else
				{
					break;
					changeflag = true;
				}

			}
			choosed = f;
			chooseflag = true;
			lines[choosed]->setColor(9);
			changeflag = true;
			menuchange = true;
			break;
		}
	}
}

void Window::dragmode(dot click) // перетаскивание мышью точки линии
{
	if (!dragflag)
	{
		dots = lines[choosed]->isonEdge(click);
	}
	if (dots)
	{
		if (!dragflag)
		{
			dragflag = true;
			lines[choosed]->setColor(12);
			menuchange = true;
		}
	}
	if (dragflag)
	{
		if (dots == 'A')
		{
			lines[choosed]->dragA(click);
		}
		if (dots == 'B')
		{
			lines[choosed]->dragB(click);
		}
		changeflag = true;
	}
}

void Window::movemode(dot click) // передвижение мышью линии
{
	A = { click.x, click.y };
	if (lines[choosed]->isinLine(A))
	{
		if (!moveflag)
		{
			B = A;
			moveflag = true;
			lines[choosed]->setColor(1);
			menuchange = true;
		}
	}
	if (moveflag)
	{
		lines[choosed]->move(B, A);
		B = A;
		changeflag = true;
	}
}

void Window::draggingOff() // отключение режима перетаскивания точки
{
	dragflag = false;
	lines[choosed]->setColor(9);
	changeflag = true;
	menuchange = true;
}

void Window::movingOff() // отключение режима движения точки
{
	moveflag = false;
	lines[choosed]->setColor(9);
	changeflag = true;
	menuchange = true;
}

void Window::doAChange() // обновление содержимого окна
{
	cleardevice();
	for (int i = 0; i < count; i++)
	{
		lines[i]->draw();
	}
	changeflag = false;
}

bool Window::isDragging() // возвращение флага dragflag
{
	return dragflag;
}

bool Window::isMoving() // возвращение флага moveflag
{
	return moveflag;
}

bool Window::isChange() // возвращение флага changeflag
{
	return changeflag;
}

bool Window::isExit() // возвразение флага exit
{
	return exit;
}

void Window::menu() // реализация диалога с пользователем в консоли
{
	if (menuchange)
	{
		system("cls");
		if (chooseflag)
		{
			if (choosed != -1)
			{
				std::cout << "Choosed line number " << choosed + 1 << std::endl;
				std::cout << "Method: ";
				if (lines[choosed]->method() == 'g')
				{
					std::cout << "graphics.h" << std::endl << std::endl;
				}
				if (lines[choosed]->method() == 'b')
				{
					std::cout << "Brezenham algorithm" << std::endl << std::endl;
				}
			}
			else
			{
				std::cout << "Choosed " << count << " lines." << std::endl << std::endl;
			}
			
		}
		std::cout << "Mouse proccess: ";
		if (createflag)
		{
			std::cout << "To create a line, left-click on two points or press 'l'" << std::endl << std::endl;
		} 
		else if (moveflag)
		{
			std::cout << "Moving the line." << std::endl << std::endl;
		} 
		else if (dragflag)
		{
			std::cout << "Dragging the dot of line." << std::endl << std::endl;
		}
		else
		{
			std::cout << "None." << std::endl << std::endl;
		}
	
		std::cout << "The keys of program:" << std::endl;
		std::cout << "\tg - create new line with graphics.h" << std::endl;
		std::cout << "\tb - create new line with Brezenham algorithm" << std::endl;
		std::cout << "\tr - select next line" << std::endl;
		std::cout << "\tf - select previous line" << std::endl;
		std::cout << "\tw - move selected line up" << std::endl;
		std::cout << "\ts - move selected line down" << std::endl;
		std::cout << "\ta - move selected line left" << std::endl;
		std::cout << "\td - move selected line right" << std::endl;
		std::cout << "\tq - rotate left selected line" << std::endl;
		std::cout << "\te - rotate right selected line" << std::endl;
		std::cout << "\t= - zoom in selected line" << std::endl;
		std::cout << "\t- - zoom out selected line" << std::endl;
		std::cout << "\t\\ - delete selected line" << std::endl;
		std::cout << "\t` - choose all lines" << std::endl;
		std::cout << "\t0 - exit the program" << std::endl;
		menuchange = false;
	}
}