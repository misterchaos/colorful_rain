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

enum Status { FAIL, OK };

void CreatList(rainDrop** ppHead);
int Insert(rainDrop** ppHead, rainDrop* pN);
int Clean(rainDrop** ppHead);
int GetNumber(rainDrop *L);
int FreeList(rainDrop* L);
void Traverse(rainDrop* L, void(*visit)(rainDrop*));
int Delete(rainDrop** ppHead, rainDrop* pN);


