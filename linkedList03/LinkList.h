#pragma once

typedef char DLinkType;

typedef struct DLinkNode{
    DLinkType data;
    struct DLinkNode* next;     //指向下一个结点
    struct DLinkNode* prev;     //指向上一个结点
}DLinkNode;

//创建一个新结点
DLinkNode* DLinkListCreatNode(DLinkType value);

//打印
void DLinkListPrint(DLinkNode* head,const char* msg);

//初始化
void DLinkListInit(DLinkNode** head);

//尾插
void DLinkListPushBack(DLinkNode* head, DLinkType value);

//尾删
void DLinkListPopBack(DLinkNode* head);

//头插
void DLinkListPushFront(DLinkNode* head, DLinkType value);

//头删
void DLinkListPopFront(DLinkNode* head);

//在指定元素之前插入一个元素
void DLinkListInsert(DLinkNode* pos,DLinkType value);

//在指定元素之后插入一个元素
void DLinkListInsertAfter(DLinkNode* pos,DLinkType value);

//查找
DLinkNode* DLinkListFind(DLinkNode* head,DLinkType to_find);
