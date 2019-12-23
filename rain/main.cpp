#include "rain.h"
int screenX=1200, screenY=800, vX = 0, vY = 10, rainSpeed=1, rainDropNumber=300;
volatile int stop = 1;
rainDrop *head;
LQueue Q;
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
		EnLQueue(&Q,p);
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
		recreatDrop(p);
	}
	else
	{
		clearRainCircle(p);
		updateRainCircleData(p);
		drawRainCircle(p);
	}
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
	initgraphics();
	creatRain();
	while (stop!=0)
	{
	    Sleep(10);
		TraverseLQueue(&Q,&visitDrop);
	}
	clearAll();
}

void ChangeNumber(LQueue * Q,int number) {
	if (Q->length > number) {
		while (Q->length>number)
		{
			DeLQueue(Q);
		}
	}
	else if (Q->length<number) {
		while (Q->length<number) {
			rainDrop *p = creatDrop();
			EnLQueue(Q,p);
		}
	}
}




void KeyBoardListener()
{

	while(stop!=0)
	{
		if (_kbhit()) {

			int ch = _getch();
			cout << ch <<endl;
			switch (ch)
			{
			case UP:
				cout << "up" << endl;
				rainSpeed ++;
				break;
			case DOWN:
				cout << "down" << endl;
				rainSpeed --;
				break;
			case RIGHT:
				cout << "right" << endl;
				vX ++;
				break;
			case LEFT:
				cout << "left" << endl;
				vX --;
				break;
			case ENTER:
				cout << "stop" << endl;
				stop = 0;
				break;
			case ESC:
				cout << "esc" << endl;
				stop = 0;
				break;
			case PLUS:
				cout << "plus" << endl;
				rainDropNumber++;
				ChangeNumber(&Q,rainDropNumber);
				break;
			case SUB:
				cout << "sub" << endl;
				rainDropNumber--;
				ChangeNumber(&Q, rainDropNumber);
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
	//cout << "Input rainDrop Number:(<300)" <<endl ;
	//cin>>rainDropNumber;
	//cout << "Input rainSpeed" << endl;
	//cin >> rainSpeed;
	srand(1);

	std::thread t1(KeyBoardListener);
	std::thread t2(rain);
	t2.join();
	_getch();
}
