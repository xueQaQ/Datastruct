#include"Stack.h"
#include<stdio.h>
//初始化
void SeqStackInit(SeqStack* stack){
    if(stack == NULL){
        //非法输入
        return;
    }
    stack->size = 0;
    stack->capacity = 1000;             //设置元素个数
    stack->data = (SeqStackType*)malloc(stack->capacity* sizeof(SeqStackType));
}

//销毁
void SeqStackDestory(SeqStack* stack){
    free(stack->data);
    stack->size = 0;
    stack->capacity = 0;
}

//打印
void SeqStackPrint(SeqStack* stack,const char *ch){
    if(stack == NULL){
        printf("非法输入\n");
    }
    printf("******%s**********\n",ch);
    size_t i = 0;
    for(; i < stack->size; ++i){
        if(stack->data[i] == 0){
            return;
        }
        printf("入栈的第%d个元素是:[%c]\n",i+1,stack->data[i]);
    }
    printf("size = %d\n",stack->size);
}


//扩容
void SeqStackResize(SeqStack* stack){
    if(stack->size < stack->capacity){
        return;
    }
    stack->size = stack->capacity * 2 + 1;
    SeqStackType* new_ptr = (SeqStackType*)malloc(stack->capacity* sizeof(SeqStackType));
    size_t i = 0;                               //扩容后讲原来的值拷贝过来
    for(; i < stack->size; ++i ){
        new_ptr[i] = stack->data[i];
    }
    free(stack->data);
    stack->data = new_ptr;
    return;
}

//压栈
void SeqStackPush(SeqStack* stack,SeqStackType value){
    //判空
    if(stack == NULL){
        return;
    }
    if(stack->size >= stack->capacity){             //大小超过最大分配空间，需要扩容
        SeqStackResize(stack);            
    }
    stack->data[stack->size] = value;
    ++stack->size;
}

//出栈
void SeqStackPop(SeqStack* stack){
    if(stack == NULL){
        //非法输入
        return;
    }
    if(stack->size == 0){
        return;
    }
    --stack->size;
}

//取栈顶元素
//返回值-1表示出错，0表示返回成功
int SeqStackTop(SeqStack* stack,SeqStackType* value){
    if(stack == NULL|| value == NULL){
        return -1;
    }
    if(stack->size == 0){
        return -1;
    }
    *value = stack->data[stack->size-1];
}


//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
//**************Test Code*********************************
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

//测试入栈
TestSeqStackPush(){
    SeqStack stack;
    SeqStackInit(&stack);
    SeqStackPush(&stack,'a');
    SeqStackPush(&stack,'b');
    SeqStackPush(&stack,'c');
    SeqStackPush(&stack,'d');
    SeqStackPrint(&stack,"******顺序栈压栈*******");
    SeqStackTop(stack,&value);
    SeqStackPrint(&stack,"******栈顶元素*******");
}

//测试出栈
TestSeqStackPop(){
    SeqStack stack;
    SeqStackInit(&stack);
    SeqStackPush(&stack,'a');
    SeqStackPush(&stack,'b');
    SeqStackPush(&stack,'c');
    SeqStackPush(&stack,'d');
    SeqStackPop(&stack);
    SeqStackPrint(&stack,"******顺序栈出栈*******");
}

int main(){
    TestSeqStackPush();
    TestSeqStackPop();
    return 0;
}
