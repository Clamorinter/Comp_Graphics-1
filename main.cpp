#include "Window.h"

int main(void)
{
	POINT click; // структура, определяющая точку в windows.h
	dot clickdot; // для структуры POINT
	int x = 800; 
	int y = 800; 
	char key; 
	HWND wind; // дескриптор окна для окна lines
	Window lines(x, y); // инициализация окна
	wind = FindWindowA(0, "lines"); // нахождение дескриптора для окна с название lines
	lines.menu(); // появление меню
	while (!lines.isExit()) // до выхода пользователя (нажатия 0)
	{
		Sleep(50); // задержка в 50 мс
		if (_kbhit()) // если была нажата какая-либо клавиша
		{
			key = _getch();
			lines.doAKey(key);
		}

		if (GetAsyncKeyState(VK_LBUTTON)) // если нажата левая кнопка мыши
		{
			GetCursorPos(&click); // получение позиции нажатия
			ScreenToClient(wind, &click); // конвертация координат экрана в координаты окна lines
			clickdot = { click.x, click.y}; // конвертация POINT в dot
			if ((clickdot.x <= x && clickdot.y <= y)) // если координаты нажатия не выходят за границы окна
			{
				lines.doAMouse(clickdot);
				
			}
		}
		else if (lines.isMoving()) // выход из режима передвижения линии в случае отжатия лкм
		{
			lines.movingOff();
		}
		else if (lines.isDragging()) // выход из режима перетаскивания точка в случае отжатия лкм
		{
			lines.draggingOff();
		}

		lines.menu(); // диалог с пользователем
		if (lines.isChange()) // отрисовка изменений в случае их наличия
		{
			lines.doAChange();
		}
	}
	return 0;
}