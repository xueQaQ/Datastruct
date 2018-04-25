#pragma once
#include<stdio.h>

#define SeqListMaxNum 1000 
typedef char SeqListType;       // 防止重定义类型 
typedef struct SeqList{
	SeqListType SeqListArr[SeqListMaxNum];
	size_t size;
}SeqList;

//初始化顺序表元素
void SeqListInit(SeqList* seq);

//打印顺序表
void SeqListPrint(SeqList* seq,char* ch);

//尾插一个元素
void SeqListPushEnd(SeqList* seq,SeqListType value);

//实现尾删
void SeqListPopEnd(SeqList* seq);

//实现头插一个元素
void SeqListPushStart(SeqList* seq,SeqListType value);

//实现头删
void SeqListPopStart(SeqList* seq);

//取顺序表的任意位置的元素
SeqListType SeqListPopGet(SeqList* seq,size_t pos);
// seq 顺序表的指针  pos 要取得元素下标  

//冒泡排序
//void SeqListBubbleSortEx(SeqList* seq);

//在顺序表的指定下标插入元素
void SeqListPushPosition(SeqList* seq,size_t pos,SeqListType value);

//在顺序表的指定下删除元素
void SeqListPosPosition(SeqList* seq,size_t pos);

