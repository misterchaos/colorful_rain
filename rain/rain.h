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


//水圈结构体
typedef struct rainCircle
{
	int x;
	int y;
	int r;
	int curR;
	int rainCircleStep;
}rainCircle;

//雨滴结构体
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

//闪电结构体
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

//状态码
enum Status { FAIL, OK };

//创建链表
void CreatList(rainDrop** ppHead);
//插入链表
int Insert(rainDrop** ppHead, rainDrop* pN);
//删除已经落水的雨滴
int DeleteFellRainDrop(rainDrop** ppHead);
//获取链表中的雨滴个数
int GetNumber(rainDrop *L);
//销毁链表
int FreeList(rainDrop* L);
//遍历链表
void Traverse(rainDrop* L, void(*visit)(rainDrop*));
//删除某个结点
int Delete(rainDrop** ppHead, rainDrop* pN);
//初始化图形界面
void Initgraphics(void);
//获取随机颜色
COLORREF GetRandomColor();
//生成雨滴
struct rainDrop *CreatDrop(void);
//生成雨滴链表
void CreatRainList(void);
//更新雨滴位置
void UpdateRainLineData(struct rainDrop *p);
//绘制雨滴
void DrawRainLine(struct rainDrop *p);
//擦除雨滴
void ClearRainLine(struct rainDrop *p);
//雨滴下落
void RainDropDown(struct rainDrop *p);
//更新水圈位置
void UpdateRainCircleData(struct rainDrop *p);
//绘制水圈
void DrawRainCircle(struct rainDrop *p);
//擦除水圈
void ClearRainCircle(struct rainDrop *p);
//雨滴落水
void FallToWater(struct rainDrop *p);
//绘制闪电
void StartThunder();
//清空
void ClearAll(void);
//访问雨滴
void VisitDrop(rainDrop * p);
//开始下雨
void StartRain(void);
//添加新的雨滴
void AddNewRaindrop();
//监听键盘事件
void KeyBoardListener();





