#pragma once  //防止头文件包含

#include<stdlib.h>

#define SeqListMaxNum 1000 

typedef char SeqListType;   //重定义类型  定义类型
typedef struct SeqList{
	SeqListType SeqListArr[SeqListMaxNum];
	size_t size;           //元素个数  标志有效元素
}SeqList;

void SeqListInit(SeqList* seq);    //初始化顺序表

void SeqListPrint(SeqList* seq,char* ch);   //打印顺序表

void SeqListPushEnd(SeqList* seq,SeqListType value);   //尾插一个元素

void SeqListPopEnd(SeqList* seq);     //尾删一个元素

void SeqListPushStart(SeqList* seq,SeqListType value);   //头插一个元素

void SeqListPopStart(SeqList* seq);    //头删一个元素

void SeqListPushPosition(SeqList*seq ,size_t pos,SeqListType value);   //在下标为pos处插入元素

void SeqListPopPosition(SeqList* seq, size_t pos);               //删除下标为pos的元素

void SeqListSetList(SeqList* seq, size_t pos, SeqListType value);     //修改下标为pos的元素

SeqListType SeqListGetList(SeqList* seq, size_t pos);       //读下标为pos的元素

size_t SeqListGetpos(SeqList* seq, SeqListType value);      //查找value元素值的下标

