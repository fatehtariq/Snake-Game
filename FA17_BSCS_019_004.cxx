/*	
	Muhammad Fateh Tariq - FA17/BSCS/019
	Abdullah Mansoor Malik - FA17/BSCS/004
	PT - Snake Game Project 
*/
#include "graphics.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
struct snake{
	int x;
	int y;
	int unit;
};
void draw(snake body[10], char key, int &xrincrease, int &yrincrease, int &xradius, int &yradius);
void SnakeBodyMech(snake body[10], char key, int &xrincrease, int &yrincrease, int &xradius, int &yradius);
using namespace std;
int main()
{
	int midx = 0, midy = 0;
	snake body[10]; int xrincrease = 0, yrincrease = 0; char key = '\0';
	int xradius = 7, yradius = 7;
	SnakeBodyMech(body, key, xrincrease, yrincrease, xradius, yradius);
	draw(body, key, xrincrease, yrincrease, xradius, yradius);

	return 0;
}
void draw(snake body[10], char key, int &xrincrease, int &yrincrease, int &xradius, int &yradius)
{
	int gdriver = DETECT, gmode, errorcode;/* request autodetection */
	int left, top, right, bottom;
	initgraph(&gdriver, &gmode, "");/* initialize graphics and local variables */
	errorcode = graphresult();/* read result of initialization */
	if (errorcode != grOk) {  /* an error occurred */

		printf("Graphics error: %s\n", grapherrormsg(errorcode));
		printf("Press any key to halt:");
		getch();
		exit(1);               /* terminate with an error code */
	}
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;
	while (1)
	{
		/* Set Text Style and Outputs a Text */
		setcolor(YELLOW);
		settextstyle(2, 0, 7);
		outtextxy(getmaxx() - 380, 5, " S N A K E");
		settextstyle(3, 0, 2);
		outtextxy(9, 425, " Name : Name String");
		outtextxy(510, 425, " Score 0000");
		int l1 = 310, t1 = 210, r1 = 300, b1 = 170;
		/* This prints a series of Rectangles with change in size as the iteration preceeds ,and after a set iteration count changes in color */
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
		/* Obstacles are made and are given a fill pattern along with a color */
		setfillstyle(BKSLASH_FILL, MAGENTA);
		bar(midx + 50, midy - 40, midx + 200, midy - 100);
		bar(midx - 30, midy + 30, midx + 90, midy + 100);
		bar(midx - 100, midy - 140, midx - 250, midy - 50);
			/* Snake is made here */
			setfillstyle(INTERLEAVE_FILL, LIGHTGREEN);
			setcolor(GREEN);
			
			body[0].x = midx + xrincrease; body[0].y = midy + yrincrease;
			for (int i = 0; i < 2; i++)
			{
				fillellipse(body[i].x, body[i].y, xradius, yradius);
			}
			//while (!kbhit())
			//{
			//	key = (char)getch();
			//	switch (key)
			//	{
			//	case KEY_UP:
			//		break;
			//	case KEY_DOWN:
			//		break;
			//	case KEY_RIGHT:
			//		xrincrease += 10; //use snakebody[]x and y and unit to change direction and use the ellipse print function ,its x y up and down as snake structures
			//		delay(100);
			//		cleardevice();
			//		break;
			//	case KEY_LEFT:
			//		break;
			//	default:
			//		break;
			//	}
			//}
			delay(100);
			cleardevice();
			yrincrease -= 7;
			///* Food is drawn here ,color is given aswell */

			//int xradius = 10; int yradius = 10;
			//setfillstyle(INTERLEAVE_FILL, RED);
			//setcolor(LIGHTRED);
			//fillellipse(midx, midy - 100, xradius, yradius);
			//fillellipse(midx - 200, midy - 30, xradius, yradius);
	}
	getch();
	closegraph();
}
void SnakeBodyMech(snake body[10], char key, int &xrincrease, int &yrincrease ,int &xradius, int &yradius )
{
	int midx = getmaxx() / 2;
	int midy = getmaxy() / 2;
	body[0].x = midx + xrincrease; body[0].y = midy + yrincrease;
	for (int i = 1; i < 5; i++)
	{
		body[i].x = body[i - 1].x - xradius;
		body[i].y = body[i - 1].y - yradius;
	}
}