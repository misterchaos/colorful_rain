#pragma once

using namespace std;
#define LEN sizeof(struct rainDrop)
#define UP			72
#define DOWN		80
#define LEFT		75
#define RIGHT		77
#define ENTER       13
#define ESC			27
#define PLUS	    61
#define SUB			45

#include <stdlib.h>
#include <time.h>
#include <dos.h>
#include <iostream>
#include <math.h>
#include <easyx.h>
#include <conio.h>
#include <thread>
#include <mutex>
#include <stdio.h>



typedef struct rainCircle
{
	int x;
	int y;
	int r;
	int curR;
	int rainCircleStep;
}rainCircle;

typedef struct rainDrop
{
	int startX;
	int startY;
	int endY;
	int curX;
	int curY;
	int rainColor;
	float rainLineLength;
	int status;
	struct rainCircle water;
	struct rainDrop *next;
}rainDrop;



typedef struct node
{
	rainDrop *data;                   //数据域指针
	struct node*next;  //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
	Node *front;                   //队头
	Node *rear;                    //队尾
	size_t length;            //队列长度
} LQueue;

enum Status { FAIL, OK };


void InitLQueue(LQueue *Q);
void DestoryLQueue(LQueue *Q);
Status IsEmptyLQueue(const LQueue *Q);
Status GetHeadLQueue(LQueue *Q, rainDrop *e);
int LengthLQueue(LQueue *Q);
Status EnLQueue(LQueue *Q, rainDrop *data);
Status DeLQueue(LQueue *Q);
void ClearLQueue(LQueue *Q);
Status TraverseLQueue(const LQueue *Q, void(*foo)(rainDrop *q));


