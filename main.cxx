
#include "graphics.h"
#include <ctime>
#include <iostream>
#include <stdlib.h>                    
#include <ctype.h>    
#include <fstream>
using namespace std;

struct SnakeBody
{
	int snakeX[20];
	int snakeY[20];
	int lenght;
	int radius;
	char direction;
	char tempDirection;
	int xincrease;
	int yincrease;
	int x;
	int y;
	int counter;
	int tempX;
	int tempY;
	int BlackSnaketempX;
	int BlackSnaketempY;
};
struct food
{
	int x, y;
	int radius;
	int color;
};
struct boundary
{
	int xMax;
	int yMax;
	int xMin;
	int yMin;

	int top;
	int bottom;
	int right;
	int left;
};
struct playerInfo
{
	char name[20];
	int score;
	char scoreString[10];
	int highScore;
	int temp;
	char tempString[100];
};

void Menu(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void MenuPause(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void BoundryDraw(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void ObstacleDraw(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void FoodInitialize(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void FoodDraw(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void FoodConsume(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void FoodRePosition(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void SnakeInitialize(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void SnakeDraw(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void BlackSnakeDraw(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void SnakeControls(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void SnakeReInitialize(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void SnakeDirection(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void SnakeSelfColiDetect(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void ColiDetect(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void FetchPlayerData(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void MenuPause(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void Save(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void Load(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void MainSnakeGameEngine(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void LoadScreen(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);
void gameOver(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake);

int APIENTRY WinMain
(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SnakeBody snake;	food food;	boundary limits;	playerInfo player;	bool isSnake = false;	
	initwindow(800, 600, "Snake Game v1.0.5 (BETA)");

	LoadScreen(snake, food, limits, player, isSnake);
	Menu(snake, food, limits, player, isSnake);
	while (!kbhit())
	{
		delay(200);
	}
	return 0;
}
void Menu(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	cleardevice();
	char choice = 0;
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;
	/* Set Text Style and Outputs a Text */
	setcolor(YELLOW);
	settextstyle(2, 0, 10);
	outtextxy(getmaxx() - 520, 30, " S N A K E");
	settextstyle(3, 0, 2);
	int l1 = 310, t1 = 210, r1 = 300, b1 = 170;
	/* This prints a series of Rectangles with change in size as the iteration preceeds ,and after a set iteration count changes in color */
	int left, top, right, bottom;
	for (int i = 0; i <= 5; i++)
	{
		left = getmaxx() / 2 - l1;
		top = getmaxy() / 2 - t1;
		right = getmaxx() / 2 + r1;
		bottom = getmaxy() / 2 + b1;
		if (i == 0 || i == 1 || i == 4 || i == 5)
		{
			setcolor(BLUE);
			rectangle(left, top, right, bottom);
		}
		if (i == 2 || i == 3)
		{
			setcolor(LIGHTBLUE);
			rectangle(left, top, right, bottom);
		}

		l1 -= 2; r1 -= 2; t1 -= 2; b1 -= 2;
	}
	setcolor(YELLOW);
	outtextxy(top + 20, 150, " -> Press ( 1 ) to Play ! ");
	outtextxy(top + 20, 250, " -> Press ( 2 ) to see Top Three High Scores ! ");
	outtextxy(top + 20, 350, " -> Press ( Q ) to Quit the Game ! ");

	choice = getch();

	switch (choice)
	{
	case '1':
		cleardevice();
		setcolor(YELLOW);
		settextstyle(2, 0, 10);
		outtextxy(getmaxx() - 520, 30, " S N A K E");
		settextstyle(3, 0, 2);
		l1 = 310, t1 = 210, r1 = 300, b1 = 170;
		for (int i = 0; i <= 5; i++)
		{
			left = getmaxx() / 2 - l1;
			top = getmaxy() / 2 - t1;
			right = getmaxx() / 2 + r1;
			bottom = getmaxy() / 2 + b1;
			if (i == 0 || i == 1 || i == 4 || i == 5)
			{
				setcolor(BLUE);
				rectangle(left, top, right, bottom);
			}
			if (i == 2 || i == 3)
			{
				setcolor(LIGHTBLUE);
				rectangle(left, top, right, bottom);
			}

			l1 -= 2; r1 -= 2; t1 -= 2; b1 -= 2;
		}
		setcolor(YELLOW);
		outtextxy(top + 20, 150, " -> Press ( 1 ) to Play a New Game ! ");
		outtextxy(top + 20, 250, " -> Press ( 2 ) to Load a Game ! ");
		char choice1;
		choice1 = getch();
		switch (choice1)
		{
		case '1':
			//GAME START FUNCTION HERE
			MainSnakeGameEngine(snake, food, limits, player, isSnake);
			break;
		case '2':
			//GAME START WITH LOAD FEATURE
			Load(snake, food, limits, player, isSnake);
			BoundryDraw(snake, food, limits, player, isSnake);
			ObstacleDraw(snake, food, limits, player, isSnake);
			while (1)
			{
				SnakeDirection(snake, food, limits, player, isSnake);
			}
			break;
		}
		break;
	case '2':
		break;
	case 'q':
	case 'Q':
		exit(0);
		break;
	}
}
void MenuPause(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	char choice;
	initwindow(800, 600, "Game Paused");
	BoundryDraw(snake, food, limits, player, isSnake);
	setcolor(YELLOW);
	settextstyle(2, 0, 10);
	outtextxy(getmaxx() - 520, 30, " S N A K E");
	outtextxy(getmaxx() / 2 - 180, getmaxy() / 2 - 140, "Game Paused ! ");
	settextstyle(3, 0, 2);
	outtextxy(getmaxx() / 2 - 140, 250, " -> Press ( 1 ) to Resume ! ");
	outtextxy(getmaxx() / 2 - 140, 300, " -> Press ( 2 ) to Save the Game ! ");
	outtextxy(getmaxx() / 2 - 140, 350, " -> Press ( Q ) to Quit the Game ! ");
	choice = getch();
	switch (choice)
	{
	case '1':
		cleardevice();
		break;
	case '2':
		Save(snake, food, limits, player, isSnake);
		cleardevice();
		break;
	case 'Q':
	case 'q':
		cleardevice();
		Menu(snake, food, limits, player, isSnake);
		break;
	default:
		cleardevice();
		break;
	}
}
void MainSnakeGameEngine(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	BoundryDraw(snake, food, limits, player, isSnake);
	SnakeInitialize(snake, food, limits, player, isSnake);
	FoodInitialize(snake, food, limits, player, isSnake);
	FetchPlayerData(snake, food, limits, player, isSnake);
	ObstacleDraw(snake, food, limits, player, isSnake);
	while (1)
	{
		SnakeDirection(snake, food, limits, player, isSnake);
	}
}
void FetchPlayerData(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	player.name[20] = { '\0' };
	for (int i = 0; i < 20; i++)
		player.name[i] = ' ';
	cleardevice();
	for (int i = 0; i < 20; i++)
	{
		BoundryDraw(snake, food, limits, player, isSnake);
		setcolor(YELLOW);
		outtextxy(getmaxx() / 2 - 100, getmaxy() / 2 - 50, " Enter Your Name ");
		player.name[i] = getch();
		outtextxy(getmaxx() / 2 - 120, getmaxy() / 2 - 20, player.name);
	}
	cleardevice();
}
void BoundryDraw(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	char choice = 0;
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;
	int l1 = 310, t1 = 210, r1 = 300, b1 = 170;
	/* This prints a series of Rectangles with change in size as the iteration preceeds ,and after a set iteration count changes in color */
	int left, top, right, bottom;
	for (int i = 0; i <= 5; i++)
	{
		left = getmaxx() / 2 - l1;
		top = getmaxy() / 2 - t1;
		right = getmaxx() / 2 + r1;
		bottom = getmaxy() / 2 + b1;
		if (i == 0 || i == 1 || i == 4 || i == 5)
		{
			setcolor(BLUE);
			rectangle(left, top, right, bottom);
		}
		if (i == 2 || i == 3)
		{
			setcolor(LIGHTBLUE);
			rectangle(left, top, right, bottom);
		}

		l1 -= 2; r1 -= 2; t1 -= 2; b1 -= 2;
	}
	limits.xMax = 685;
	limits.xMin = 105;
	limits.yMax = 455;
	limits.yMin = 105;
}
void SnakeDraw(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	for (int i = snake.lenght; i >= 0; i--)
	{
			setfillstyle(4, LIGHTGREEN);
			setcolor(GREEN);
			fillellipse(snake.snakeX[i], snake.snakeY[i], 4, 4);
			if (i == 0)
			{
				if (snake.tempDirection == 'R')
				{
					setfillstyle(3, BLACK);
					setcolor(BLACK);
					fillellipse(snake.snakeX[i] - 8, snake.snakeY[i], 4, 4);
					fillellipse(snake.snakeX[i] - 8, snake.snakeY[i] + 8, 4, 4);
					fillellipse(snake.snakeX[i] - 8, snake.snakeY[i] - 8, 4, 4);
					fillellipse(snake.snakeX[i], snake.snakeY[i] + 8, 4, 4);
					fillellipse(snake.snakeX[i], snake.snakeY[i] - 8, 4, 4);
				}
				if (snake.tempDirection == 'L')
				{
					setfillstyle(3, BLACK);
					setcolor(BLACK);
					fillellipse(snake.snakeX[i] + 8, snake.snakeY[i], 4, 4);
					fillellipse(snake.snakeX[i] + 8, snake.snakeY[i] + 8, 4, 4);
					fillellipse(snake.snakeX[i] + 8, snake.snakeY[i] - 8, 4, 4);
					fillellipse(snake.snakeX[i], snake.snakeY[i] + 8, 4, 4);
					fillellipse(snake.snakeX[i], snake.snakeY[i] - 8, 4, 4);
				}
				if (snake.tempDirection == 'U')
				{
					setfillstyle(3, BLACK);
					setcolor(BLACK);
					fillellipse(snake.snakeX[i] - 8, snake.snakeY[i] + 8, 4, 4);
					fillellipse(snake.snakeX[i] + 8, snake.snakeY[i] + 8, 4, 4);
					fillellipse(snake.snakeX[i] + 8, snake.snakeY[i], 4, 4);
					fillellipse(snake.snakeX[i] - 8, snake.snakeY[i], 4, 4);
					fillellipse(snake.snakeX[i], snake.snakeY[i] + 8, 4, 4);
				}
				if (snake.tempDirection == 'D')
				{
					setfillstyle(3, BLACK);
					setcolor(BLACK);
					fillellipse(snake.snakeX[i] - 8, snake.snakeY[i] - 8, 4, 4);
					fillellipse(snake.snakeX[i] + 8, snake.snakeY[i] - 8, 4, 4);
					fillellipse(snake.snakeX[i] + 8, snake.snakeY[i], 4, 4);
					fillellipse(snake.snakeX[i] - 8, snake.snakeY[i], 4, 4);
					fillellipse(snake.snakeX[i], snake.snakeY[i] - 8, 4, 4);
				}
			}
	}
}
void FoodDraw(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	setfillstyle(INTERLEAVE_FILL, food.color);
	setcolor(LIGHTRED);
	fillellipse(food.x, food.y, food.radius, food.radius);
}
void ObstacleDraw(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	setfillstyle(BKSLASH_FILL, MAGENTA);
	bar((getmaxx() / 2) + 50, (getmaxy() / 2) - 40, (getmaxx() / 2) + 200, (getmaxy() / 2) - 100);
	bar((getmaxx() / 2) - 100, (getmaxy() / 2) - 140, (getmaxx() / 2) - 250, (getmaxy() / 2) - 50);
}
void SnakeInitialize(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	snake.lenght = 10;	snake.xincrease = 8;	snake.yincrease = 0;	player.score = 0;
	snake.x = (getmaxx() / 2);
	snake.y = (getmaxy() / 2);
	snake.snakeX[snake.lenght] = snake.x;
	snake.snakeY[snake.lenght] = snake.y;
	snake.tempX = snake.snakeX[snake.lenght];
	snake.tempY = snake.snakeY[snake.lenght];

	for (int i = snake.lenght; i >= 0; i--)
	{
		snake.snakeX[i - 1] = snake.snakeX[i] - snake.xincrease;
		snake.snakeY[i - 1] = snake.snakeY[i] - snake.yincrease;
	}
	snake.counter = snake.lenght - 1;
	snake.tempDirection = 'R';
}
void FoodInitialize(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	bool isXRight = false;
	bool isYRight = false;
	food.radius = 7;
	srand(time(NULL));
	while (1)
	{
		food.x = (rand() % limits.xMax - limits.xMin) + 1;
		food.y = (rand() % limits.yMax - limits.yMin) + 1;
		if (food.x <= 685 && food.x >= 105)
		{
			isXRight = true;
		}
		if (food.y <= 455 && food.y >= 105)
		{
			isYRight = true;
		}
		if (isXRight == true && isYRight == true)
		{
			break;
		}
		else
		{
			food.x = (rand() % limits.xMax - limits.xMin) + 1;
			food.y = (rand() % limits.yMax - limits.yMin) + 1;
		}
	}
		/*for (int i = 0; i < snake.lenght; i++)
		{
			if (food.x + 5 == snake.snakeX[i] || food.y + 5 == snake.snakeY[i])
			{
				food.x = rand() % limits.xMax - limits.xMin + 1;
				food.y = rand() % limits.yMax - limits.yMin + 1;
			}
		}*/
}
void SnakeDirection(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	char choice;
	if (kbhit())
	{
		snake.direction = getch();
		SnakeControls(snake, food, limits, player, isSnake);
		if (snake.direction == 'p')
		{
			MenuPause(snake, food, limits, player, isSnake);
		}
		isSnake = true;
	}
		setcolor(YELLOW);
		outtextxy(getmaxx() / 2 - 310, getmaxy() / 2 + 220, "Player : ");
		setcolor(YELLOW);
		outtextxy(getmaxx() / 2 - 230, getmaxy() / 2 + 220, player.name);
		_itoa(player.score ,player.scoreString ,10);
		outtextxy(getmaxx() / 2 + 200, getmaxy() / 2 + 220, "Score : ");
		outtextxy(getmaxx() / 2 + 270, getmaxy() / 2 + 220, player.scoreString);
		BlackSnakeDraw(snake, food, limits, player, isSnake);
		SnakeDraw(snake, food, limits, player, isSnake);
		FoodConsume(snake, food, limits, player, isSnake);
		FoodDraw(snake, food, limits, player, isSnake);
		BoundryDraw(snake, food, limits, player, isSnake);
		ObstacleDraw(snake, food, limits, player, isSnake);
		delay(50);
		ColiDetect(snake, food, limits, player, isSnake);
		snake.tempX = snake.snakeX[snake.lenght];
		snake.tempY = snake.snakeY[snake.lenght];
		snake.snakeX[snake.lenght] += snake.xincrease;
		snake.snakeY[snake.lenght] += snake.yincrease;

		SnakeReInitialize(snake, food, limits, player, isSnake);
		snake.counter--;
		
}
void SnakeControls(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	if (snake.direction == KEY_UP)
	{
		if (snake.tempDirection == 'D')
		{
			//Ignores an Up Input if direction is down
		}
		else if (snake.tempDirection == 'U')
		{

		}
		else
		{
			snake.tempDirection = 'U';
			snake.xincrease = 0;
			snake.yincrease = -8;
			snake.tempX = snake.snakeX[snake.lenght];
			snake.tempY = snake.snakeY[snake.lenght];
			snake.snakeY[snake.lenght] += snake.yincrease;
			snake.snakeX[snake.lenght] += snake.xincrease;
		}
	}
	if (snake.direction == KEY_DOWN)
	{
		if (snake.tempDirection == 'U')
		{

		}
		else if (snake.tempDirection == 'D')
		{

		}
		else
		{
			snake.tempDirection = 'D';
			snake.xincrease = 0;
			snake.yincrease = 8;
			snake.tempX = snake.snakeX[snake.lenght];
			snake.tempY = snake.snakeY[snake.lenght];
			snake.snakeY[snake.lenght] += snake.yincrease;
			snake.snakeX[snake.lenght] += snake.xincrease;
		}
	}
	if (snake.direction == KEY_RIGHT)
	{
		if (snake.tempDirection == 'L')
		{

		}
		else if (snake.tempDirection == 'R')
		{

		}
		else
		{
			snake.tempDirection = 'R';
			snake.xincrease = 8;
			snake.yincrease = 0;
			snake.tempX = snake.snakeX[snake.lenght];
			snake.tempY = snake.snakeY[snake.lenght];
			snake.snakeY[snake.lenght] += snake.yincrease;
			snake.snakeX[snake.lenght] += snake.xincrease;
		}
	}
	if (snake.direction == KEY_LEFT)
	{
		if (snake.tempDirection == 'R')
		{

		}
		else if (snake.tempDirection == 'L')
		{

		}
		else
		{
			snake.tempDirection = 'L';
			snake.xincrease = -8;
			snake.yincrease = 0;
			snake.tempX = snake.snakeX[snake.lenght];
			snake.tempY = snake.snakeY[snake.lenght];
			snake.snakeY[snake.lenght] += snake.yincrease;
			snake.snakeX[snake.lenght] += snake.xincrease;
		}
	}
}
void SnakeReInitialize(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	snake.snakeX[snake.lenght - 1] = snake.tempX;
	snake.snakeY[snake.lenght - 1] = snake.tempY;
	snake.BlackSnaketempX = snake.snakeX[0];
	snake.BlackSnaketempY = snake.snakeY[0];
	for (int i = 0; i < snake.lenght; ++i)
	{
		snake.snakeX[i] = snake.snakeX[i + 1];
		snake.snakeY[i] = snake.snakeY[i + 1];
	}
}
void FoodConsume(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	 if(snake.xincrease > 0 || snake.xincrease < 0 && snake.yincrease == 0)
	{
		 if ((snake.snakeX[snake.lenght] + 7 >= food.x - 8 && snake.snakeX[snake.lenght] + 7 <= food.x + 8) && (snake.snakeY[snake.lenght] - 7 <= food.y + 8 && snake.snakeY[snake.lenght] + 7 >= food.y - 8))
	{
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	fillellipse(food.x, food.y, 7, 7);
	FoodInitialize(snake, food, limits, player, isSnake);
	FoodDraw(snake, food, limits, player, isSnake);
	player.score += 10;
	snake.BlackSnaketempX = snake.snakeX[snake.lenght] + snake.xincrease;
	snake.BlackSnaketempY = snake.snakeY[snake.lenght] + snake.yincrease;
	snake.lenght++;
	snake.snakeX[snake.lenght] = snake.BlackSnaketempX;
	snake.snakeY[snake.lenght] = snake.BlackSnaketempY;

	}
	}
	/*else if (snake.yincrease > 0 || snake.yincrease < 0 && snake.xincrease == 0 )
	{
	if ((snake.snakeY[snake.lenght] - 7 <= food.y + 8 && snake.snakeY[snake.lenght] + 7 >= food.y - 8))
	{
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	fillellipse(food.x, food.y, 7, 7);
	FoodInitialize(snake, food, limits, player, isSnake);
	FoodDraw(snake, food, limits, player, isSnake);
	player.score += 10;
	}
	}*/
	/*if (((snake.snakeY[snake.lenght] - food.y) * (snake.snakeY[snake.lenght] - food.y) )+ ((snake.snakeX[snake.lenght] - food.x) * (snake.snakeX[snake.lenght] - food.x)) <= (snake.radius + food.radius) * (snake.radius + food.radius))
	{
		setfillstyle(1, BLACK);
		setcolor(BLACK);
		fillellipse(food.x, food.y, 7, 7);
		FoodInitialize(snake, food, limits, player, isSnake);
		FoodDraw(snake, food, limits, player, isSnake);
		player.score += 10;
	}*/
}
void LoadScreen(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			setcolor(YELLOW);
			settextstyle(2, 0, 10);
			outtextxy(getmaxx() - 530, 150, " S N A K E");
			settextstyle(2, 0, 9);
			outtextxy(getmaxx() - 200, 500, "Loading...");
			setcolor(BLACK);
			setfillstyle(1, 2 + i);
			fillellipse(getmaxx() - 500 + (j * 15), getmaxy() / 2 + 100, 5, 5);
			delay(100);
		}
	}
	setcolor(BLACK);
	setfillstyle(1, BLACK);
	for (int j = 0; j < 12; j++)
	fillellipse(getmaxx() - 500 + (j * 15), getmaxy() / 2 + 100, 5, 5);
	settextstyle(2, 0, 9);
	setcolor(YELLOW);
	outtextxy(getmaxx() - 600, 300, "Press any Key to Continue");
	setcolor(BLACK);
	outtextxy(getmaxx() - 200, 500, "Loading...");
	getch();
}
void ColiDetect(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	if (snake.snakeX[snake.lenght] + 7 >= limits.xMax || snake.snakeX[snake.lenght] <= limits.xMin || snake.snakeY[snake.lenght] >= limits.yMax || snake.snakeY[snake.lenght] <= limits.yMin)
	{
		gameOver(snake, food, limits, player, isSnake);
		getch();
	}
	if (snake.snakeX[snake.lenght] + 7 >= (getmaxx() / 2) + 50 && snake.snakeX[snake.lenght] + 7 <= (getmaxx() / 2) - 40 && snake.snakeY[snake.lenght] + 7 >= (getmaxy() / 2) - 100 && snake.snakeY[snake.lenght] + 7 <= (getmaxy() / 2) - 100)
	{
		gameOver(snake, food, limits, player, isSnake);
		getch();
	}

}
void gameOver(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	cleardevice();
	setcolor(YELLOW);
	outtextxy(getmaxx() / 2 - 50, getmaxy() / 2 , "Game Over !");
	setcolor(YELLOW);
	outtextxy(getmaxx() / 2 - 310, getmaxy() / 2 + 220, "Player : ");
	setcolor(YELLOW);
	outtextxy(getmaxx() / 2 - 230, getmaxy() / 2 + 220, player.name);
	_itoa(player.score, player.scoreString, 10);
	outtextxy(getmaxx() / 2 + 200, getmaxy() / 2 + 220, "Score : ");
	outtextxy(getmaxx() / 2 + 270, getmaxy() / 2 + 220, player.scoreString);
	outtextxy(getmaxx() / 2 - 130, getmaxy() / 2 + 240, "Press any Key to Continue");
	getch();
	Menu(snake, food, limits, player, isSnake);
}
void BlackSnakeDraw(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	setfillstyle(1, BLACK);
	setcolor(BLACK);
	fillellipse(snake.BlackSnaketempX,snake.BlackSnaketempY ,4,4);

}
void Save(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	ofstream file;
	file.open("SaveGame.txt");
	file << player.name << endl;
	file << player.score << endl;
	file << food.x << endl;
	file << food.y << endl;
	file << food.radius << endl;
	file << snake.lenght << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < snake.lenght; j++)
		{
			file << snake.snakeX[i] << endl;
			file << snake.snakeY[j] << endl;
		}
		file << endl;
	}
	file << snake.xincrease << " ";
	file << snake.yincrease << " ";
	file << endl;
	file.close();

}
void Load(SnakeBody &snake, food &food, boundary &limits, playerInfo &player, bool &isSnake)
{
	ifstream file;
	file.open("SaveGame.txt");
	while (!file.eof())
	{
		file.getline(player.tempString, 100);
		strcpy(player.name ,player.tempString);
		file.getline(player.tempString, 100);
		player.score = atoi(player.tempString);
		file.getline(player.tempString, 100);
		food.x = atoi(player.tempString);
		file.getline(player.tempString, 100);
		food.y = atoi(player.tempString);
		file.getline(player.tempString, 100);
		food.radius = atoi(player.tempString);
		file.getline(player.tempString, 100);
		snake.lenght = atoi(player.tempString);
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < snake.lenght; j++)
			{
				file.getline(player.tempString, 100);
				snake.snakeX[i] = atoi(player.tempString);
				file.getline(player.tempString, 100);
				snake.snakeY[j] = atoi(player.tempString);
			}
		}
		snake.xincrease = atoi(player.tempString);
		file.getline(player.tempString, 100);
		snake.yincrease = atoi(player.tempString);
	}
	file.close();
	cleardevice();
}
