//栈后进先出
#pragma once
#include<stdlib.h>
#include<stdio.h>

typedef char SeqStackType;

typedef struct SeqStack{
    SeqStackType* data;    
    size_t size;
    size_t capacity;    //MAX_SIZE的替代品，data这段内存能容纳的元素个数
}SeqStack;

//初始化
void SeqStackInit(SeqStack* stack);

//销毁
void SeqStackDestory(SeqStack* stack);

//打印
void SeqStackPrint(SeqStack* stack,const char *ch);

//扩容
void SeqStackResize(SeqStack* stack);

//压栈
void SeqStackPush(SeqStack* stack,SeqStackType value);

//出栈
void SeqStackPop(SeqStack* stack);

//取栈顶元素
int SeqStackTop(SeqStack* stack,SeqStackType* value);
