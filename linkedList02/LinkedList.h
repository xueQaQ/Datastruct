#pragma once
#include<stdio.h>

typedef char LinkType;     //重定义类型

typedef struct LinkNode{       //定义结构体
	LinkType data;         //数据域
	struct LinkNode* next;     //指针域
}LinkNode;

void LinkListInit(LinkNode** head);    //初始化链表

void PrintChar(LinkNode* head,char* msg);    //打印链表

void DestoryNode(LinkNode* node);        //实现销毁一个结点

void LinkListDestory(LinkNode** head);      //实现删除一个结点

LinkNode* CrearNewNode(LinkType value);      //创建一个新结点

void LinkListPushBack(LinkNode** head,LinkType value);    //尾插一个元素到链表中

void LinkListPosBack(LinkNode** head);        //尾删一个元素

void LinkListPushHead(LinkNode** head,LinkType value);     //头插一个元素

void LinkListPopHead(LinkNode** head);     //头删一个元素

LinkNode* LinkListFind(LinkNode* head,LinkType value);      //查找元素值的下标

void LinkListPushPos(LinkNode* pos,LinkType value);        //在Pos下标后插入值

//LinkNode* ReverseLinkList(LinkNode* head);                //逆转

void Fac(LinkNode* head);

void LinkedListInsertBef(LinkNode** head,LinkNode* pos,LinkType value);     //在pos下标前插入元素
