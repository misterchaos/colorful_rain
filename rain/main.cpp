#include "rain.h"
int screenX=1200, screenY=800, vX = 0, vY = 10, rainSpeed=1, rainDropNumber=0;
volatile int stop = 1;
rainDrop *head;
std::mutex g_mutex;

void initgraphics(void)
{
	initgraph(screenX, screenY);
}

COLORREF getRandomColor() {
	return  RGB(rand()%256+1, rand() % 256 + 1, rand() % 256 + 1);
}

void recreatDrop(struct rainDrop *p)
{
	p->startX = rand() % screenX;
	p->startY = rand() % screenY - 30;
	p->endY = screenY - 60 + rand() % 50;
	p->curX = p->startX;
	p->curY = p->startY;
	p->rainColor = getRandomColor();
	p->rainLineLength =(float) (rand() % 15)/20;
	p->status = 0;
	p->water.x = p->startX;
	p->water.y = p->endY;
	p->water.r = rand() % 10;
	p->water.curR = rand() % 2;
	p->water.rainCircleStep = rand() % 2 + 1; 
}

struct rainDrop *creatDrop(void)
{
	struct rainDrop *p;
	p = (struct rainDrop *)malloc(LEN);
	recreatDrop(p);
	p->next = NULL;
	return (p);
}



void creatRain(void)
{
	struct rainDrop *p;
	int i;
	for (i = 0; i < rainDropNumber; i++)
	{
		p = creatDrop();
		Insert(&head,p);
	}
}

void updateRainLineData(struct rainDrop *p)
{
	p->curX += (vX*rainSpeed);
	p->curY += (vY*rainSpeed);
	p->startX = p->curX -vX*p->rainLineLength;
	p->startY = p->curY -vY*p->rainLineLength;
	p->water.x = p->curX;
}

void drawRainLine(struct rainDrop *p)
{
	setlinecolor(p->rainColor);
	line(p->startX, p->startY, p->curX, p->curY);
}

void clearRainLine(struct rainDrop *p)
{
	setlinecolor(BLACK);
	line(p->startX, p->startY, p->curX, p->curY);
}

void rainDropDown(struct rainDrop *p)
{
	if (p->curY >= p->endY)
	{
	clearRainLine(p);
		p->status = 1;
	}
	else
	{
		clearRainLine(p);
		updateRainLineData(p);
		drawRainLine(p);
	}
}

void updateRainCircleData(struct rainDrop *p)
{
	p->water.curR += p->water.rainCircleStep;
}

void drawRainCircle(struct rainDrop *p)
{
	setlinecolor(p->rainColor);
	circle(p->water.x, p->water.y, p->water.curR);
}

void clearRainCircle(struct rainDrop *p)
{
	setlinecolor(BLACK);
	circle(p->water.x, p->water.y, p->water.curR);
}



void fallToWater(struct rainDrop *p)
{
	if (p->water.curR >= p->water.r)
	{
		clearRainCircle(p);
		if (GetNumber(head)>rainDropNumber) {
			p->del = 1;//下次将被删除
		}
		else {
		    recreatDrop(p);
		}
	}
	else
	{
		clearRainCircle(p);
		updateRainCircleData(p);
		drawRainCircle(p);
	}
}


void thunder()
{

	
	int x = rand() % screenX;;
	int y =0;
	int randY = rand() % 5;
	int stepY = screenY / 40;
	int stepX = screenX / 40;
	Thunder one;
	one.x0 = x + rand() % stepX; one.y0 = y + stepY*0;
	one.x1 = x + rand() % stepX; one.y1 = y + stepY*1;
	one.x2 = x + rand() % stepX; one.y2 = y + stepY*2;
	one.x3 = x + rand() % stepX; one.y3 = y + stepY*3;
	one.x4 = x + rand() % stepX; one.y4 = y + stepY*4;
	one.x5 = x + rand() % stepX; one.y5 = y + stepY*5;
	one.x6 = x + rand() % stepX; one.y6 = y + stepY*6;
	one.x7 = x + rand() % stepX; one.y7 = y + stepY*7;
	one.x8 = x + rand() % stepX; one.y8 = y + stepY*8;
	one.x9 = x + rand() % stepX; one.y9 = y + stepY*9;
	one.x10 = x + rand() % stepX; one.y10 = y + stepY * 10;
	one.x11 = x + rand() % stepX; one.y11 = y + stepY * 11;
	one.x12 = x + rand() % stepX; one.y12 = y + stepY * 12;
	one.x13 = x + rand() % stepX; one.y13 = y + stepY * 13;
	one.x14 = x + rand() % stepX; one.y14 = y + stepY * 14;
	one.x15 = x + rand() % stepX; one.y15 = y + stepY * 15;
	one.x16 = x + rand() % stepX; one.y16 = y + stepY * 16;
	one.x17 = x + rand() % stepX; one.y17 = y + stepY * 17;
	one.x18 = x + rand() % stepX; one.y18 = y + stepY * 18;
	one.x19 = x + rand() % stepX; one.y19 = y + stepY * 19;
	POINT thunder[] = {
		{ one.x0,one.y0 },
		{ one.x1,one.y1 },
		{ one.x2,one.y2 },
		{ one.x3,one.y3 },
		{ one.x4,one.y4 },
		{ one.x5,one.y5 },
		{ one.x6,one.y6 },
		{ one.x7,one.y7 },
		{ one.x8,one.y8 },
		{ one.x9,one.y9 },
		{ one.x10,one.y10},
		{ one.x11,one.y11 },
		{ one.x12,one.y12 },
		{ one.x13,one.y13 },
		{ one.x14,one.y14 },
		{ one.x15,one.y15 },
		{ one.x16,one.y16 },
		{ one.x17,one.y17 },
		{ one.x18,one.y18 },
		{ one.x19,one.y19 }
	};
	POINT thunder2[] = {
		{ one.x15,one.y15 },
		{ one.x16+  rand() % 20,one.y16 },
		{ one.x17 + rand() % 20,one.y17 },
		{ one.x18 + rand() % 20,one.y18 }
	};
	COLORREF yellow_thunder = RGB(181, 165, 95);
	COLORREF blue_thunder = RGB(73 ,147 ,255);

	int ops = rand() % 2;
	if (ops==1) {
		setlinecolor(yellow_thunder);
	}
	else {
		setlinecolor(blue_thunder);
	}
	
	polyline(thunder, 20);
	polyline(thunder2, 4);
	Sleep(2);
	setlinecolor(BLACK);
	polyline(thunder, 20);
	polyline(thunder2, 4);

}

void clearAll(void)
{
	struct rainDrop *p, *pf;
	p = head;
	while (p != NULL)
	{
		pf = p;
		p = p->next;
		free(pf);
	}
	closegraph();
}
void visitDrop(rainDrop * p) {
	if (p->status == 0) {
		rainDropDown(p);
	}
	else {
		fallToWater(p);
	}
}

void rain(void)
{
	CreatList(&head);
	creatRain();
	while (stop!=0)
	{
	    Sleep(10);
		Traverse(head,&visitDrop);
		Clean(&head);
		thunder();
	}
	clearAll();
}

void ChangeNumber(int number) {
    if (GetNumber(head)<number) {
		while (GetNumber(head) <number) {
			rainDrop *p = creatDrop();
			Insert(&head,p);
		}
	}
}





void KeyBoardListener()
{

	while(stop!=0)
	{
		if (_kbhit()) {

			int ch = _getch();
		//	cout << ch <<endl;
			switch (ch)
			{
			case UP:
			//	cout << "up" << endl;
				if (rainSpeed < 10) {
					rainSpeed++;
				}
				break;
			case DOWN:
			//	cout << "down" << endl;
				if (rainSpeed > 1) {
					rainSpeed--;
				}
				break;
			case RIGHT:
			//	cout << "right" << endl;
				if (vX < 14) {
					vX++;
				}
				break;
			case LEFT:
			//	cout << "left" << endl;
				if (vX > -14) {
					vX--;
				}
				break;
			case ENTER:
			//	cout << "stop" << endl;
				stop = 0;
				break;
			case ESC:
			//	cout << "esc" << endl;
				stop = 0;
				break;
			case PLUS:
			//	cout << "plus" << endl;
				if (rainDropNumber < 400) {
					rainDropNumber++;
				}
				ChangeNumber(rainDropNumber);
				break;
			case SUB:
			//	cout << "sub" << endl;
				if (rainDropNumber>0) {
				    rainDropNumber--;
				}
				break;
			default:
				break;
			}
		}

	}
}


void main()
{
	//cout << "Input screenX:" << endl;
	//cin >> screenX;
	//cout << "Input screenY:" << endl;
	//cin >> screenY;

	srand(1);
	initgraphics();

	std::thread t1(KeyBoardListener);
	std::thread t2(rain);
	t2.join();
	_getch();
}
