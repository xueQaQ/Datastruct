#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef char SeqStackType;

typedef struct SeqStack{
    SeqStackType* data;    
    size_t size;
    size_t capacity;    //MAX_SIZE的替代品，data这段内存能容纳的元素个数
}SeqStack;

typedef struct MinStack{
    SeqStack stack;
}MinStack;

//初始化
void SeqStackInit(SeqStack* stack);

//打印函数
void SeqStackPrint(SeqStack* stack,const char* ch);

//扩容
void SeqStackResize(SeqStack* stack);

//入栈
void SeqStackPush(SeqStack* stack,SeqStackType value);

//出栈
void SeqStackPop(SeqStack* stack);

//取栈顶元素
SeqStackType SeqStackTopValue(SeqStack* stack);

//销毁
void SeqStackDestory(SeqStack* stack);

//方法一
//可求出最小元素的push    flag == 1表示入栈 flag == 0 表示出栈
void SeqStackMin1(SeqStack* stack,SeqStack* stack2,int flag,SeqStackType value);

//入栈
void SeqStackPush2(SeqStack* stack1,SeqStack* stack2,SeqStackType value);

//出栈
void SeqStackPop2(SeqStack* stack1,SeqStack* stack2);

//入栈一个元素
void SeqStackPush3(SeqStack* stack, SeqStackType value);

//出栈一个元素
void SeqStackPop3(SeqStack* stack);

//取栈顶元素
SeqStackType SeqStackGetTop(SeqStack* stack);

