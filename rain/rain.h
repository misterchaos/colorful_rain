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
	int id;//代表结点的序号
	struct rainDrop *next;//结构体的指针域
	int del;//是否将被删除
}rainDrop;

typedef struct Thunder
{
	int x0, y0;
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x4, y4;
	int x5, y5;
	int x6, y6;
	int x7, y7;
	int x8, y8;
	int x9, y9;
	int x10, y10;
	int x11, y11;
	int x12, y12;
	int x13, y13;
	int x14, y14;
	int x15, y15;
	int x16, y16;
	int x17, y17;
	int x18, y18;
	int x19, y19;
}Thunder;

enum Status { FAIL, OK };

void CreatList(rainDrop** ppHead);
int Insert(rainDrop** ppHead, rainDrop* pN);
int Clean(rainDrop** ppHead);
int GetNumber(rainDrop *L);
int FreeList(rainDrop* L);
void Traverse(rainDrop* L, void(*visit)(rainDrop*));
int Delete(rainDrop** ppHead, rainDrop* pN);


