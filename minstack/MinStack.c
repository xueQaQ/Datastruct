#include<stlib.h>
#include<stdio.h>
#include"MinStack.h"

//初始化
void SeqStackInit(SeqStack* stack){
    if(stack == NULL){
        //非法输入
        return;
    }
    stack->size = 0;
    stack->capacity = 1000;
    stack->data = (SeqStackType*)malloc(stack->capacity* sizeof(SeqStackType));
}

//打印函数
void SeqStackPrint(SeqStack* stack,const char* ch){
    if(stack == NULL){
        return;
    }
    printf("*****%s*******\n",ch);
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
        //TOOD
        ///home/xue/mycd/mycd/DataStructure/stackseqlist
        return;
    }
    stack->size = stack->capacity * 2 + 1;
    SeqStackType* new_ptr = (SeqStackType*)malloc(stack->capacity*sizeof(SeqStackType));
    size_t i = 0 ;
    for(; i < stack->size; ++i){
        new_ptr[i] = stack->data[i];
    }
    free(stack->data);
    stack->data = new_ptr;
    return;
}

//入栈
void SeqStackPush(SeqStack* stack,SeqStackType value){
    if(stack == NULL){
        return;
    }
    if(stack->size == stack->capacity){    //BUG
        SeqStackResize(stack); 
    }
    stack->data[stack->size++] = value;
}

//出栈
void SeqStackPop(SeqStack* stack){
    if(stack == NULL){
        return;
    }
    if(stack->size = 0){
        printf("空栈");
        return;
    }
    stack->size--;
}

//取栈顶元素
SeqStackType SeqStackTopValue(SeqStack* stack){
    if(stack == NULL){
        return;
    }
    size_t i = stack->size - 1;
    SeqStackType value = stack->data[i];
    return value;
}

//销毁
void SeqStackDestory(SeqStack* stack){
    free(stack->data);
    stack->size = 0;
    stack->capacity = 0;
}

//方法一：
//创建一个辅助栈,每次入栈之前把栈顶元素和辅助栈的栈顶元素比较
//如果小于等于辅助栈栈顶元素,则入栈辅助栈
//出栈时,把辅助栈栈顶元素和出栈元素相比较
//如果小于等于辅助栈栈顶元素,则把辅助栈栈顶元素也出栈

//方法一
//可求出最小元素的push    flag == 1表示入栈 flag == 0 表示出栈
void SeqStackMin1(SeqStack* stack,SeqStack* stack2,int flag,SeqStackType value){
    if(flag == 1){
        if(stack->size == 1){
            SeqStackPush(stack2,value);
        }
        //比较当前元素和辅助元素栈顶元素的大小
        //如果大于辅助栈栈顶元素，则不理会
        //反之则需要压入辅助栈
        else{
            //调用入栈的栈顶元素value和 辅助栈的栈顶元素比较
            SeqStackType cur = SeqStackTopValue(stack2);
            if(value > cur){
                return;
            }
            else{
                SeqStackPush(stack2,value);
            }
        }
    }
    //0表示操作为出栈操作
    else if(flag == 0){
        //出栈时，把栈顶元素和辅助栈栈顶元素相比较，如果大于则不理会
        SeqStackType cur2 = SeqStackTopValue(stack2);
        if(value > cur2){
            return;
        }
        else{
            //如果当前栈顶元素小于等于辅助栈的栈顶元素，则辅助栈栈顶元素也该出栈
            SeqStackPop(stack2);
        }
    }
}

//入栈
void SeqStackPush2(SeqStack* stack1,SeqStack* stack2,SeqStackType value){
    if(stack1 == NULL){
        return;
    }
    if(stack2 == NULL){
        return;
    }
    if(stack1->size >= stack1->capacity){
        SeqStackResize(stack1);
    }
    stack1->data[stack1->size] = value;
    stack1->size++;
    SeqStackMin1(stack1,stack2,1,value);
}


//出栈
void SeqStackPop2(SeqStack* stack1,SeqStack* stack2){
    if(stack1 == NULL){
        return;
    }
    if(stack2 == NULL){
        return;
    }
    //出栈得先判断
    SeqStackType tmp = SeqStackTopValue(stack1);
    SeqStackMin1(stack1,stack2,0,tmp);

    stack1->size--;

    if(stack1->size == 0){
        //此时栈已经空了
        return;
    }
}

//入栈一个元素
void SeqStackPush3(SeqStack* stack, SeqStackType value){
    if(stack == NULL){
        return;
    }
    //判断空栈
    if(stack->size == 0){
        //空栈的时候压栈两次，规定栈顶元素为最小值
        stack->data[stack->size] = value;
        stack->size++;
        stack->data[stack->size] = value;
        stack->size++;
        return;
    }
    //不是空栈
    //取出栈顶元素，与当前元素比较
    //如果当前元素大于已知最小元素，则压栈时，把当前元素入栈，再把最小元素入栈
    //如果当前元素小于一直元素，则把当前元素入栈两次
    //取出栈顶元素
    SeqStackType tmp = SeqStackTopValue(stack);
    //把当前元素入栈，再把最小元素入栈，即tmp
    if(value > tmp){
        SeqStackPush(stack,value);
        SeqStackPush(stack,tmp);
    }
    else{
        SeqStackPush(stack,value);
        SeqStackPush(stack,value);
    }
}

//出栈一个元素
void SeqStackPop3(SeqStack* stack){
    if(stack == NULL){
        return;
    }
    if(stack->size == 0){
        printf("栈为空");
        return;
    }
    //压栈时压入两个元素，出栈时也要出两个元素
    SeqStackPop(stack);
    SeqStackPop(stack);
}

//取栈顶元素
SeqStackType SeqStackGetTop(SeqStack* stack){
    if(stack == NULL){
        return;
    }
    //栈顶元素是最小值
    SeqStackType min = SeqStackTopValue(stack);
    SeqStackPop(stack);
    SeqStackType top_value = SeqStackTopValue(stack);
    //再把最小值入栈
    SeqStackPush(stack,min);
    return top_value;
}

/////////////////////////////////////
//**********************************
//*******Test***********************
////////////////////////////////////


#define TESTHEAD printf("\n\n===============%s=====================\n",__FUNCTION__)

//测试入栈
void TestPush(){
    SeqStack stack;
    TESTHEAD;
    SeqStackInit(&stack);
    SeqStackPush(&stack,'a');
    SeqStackPush(&stack,'b');
    SeqStackPush(&stack,'c');
    SeqStackPush(&stack,'d');
    SeqStackPush(&stack,'e');
    SeqStackPush(&stack,'f');
    SeqStackPrint(&stack,"入栈六个元素");
}

//测试出栈
void TestPop(){
    SeqStack stack;
    TESTHEAD;
    SeqStackInit(&stack);
    SeqStackPush(&stack,'a');
    SeqStackPush(&stack,'b');
    SeqStackPush(&stack,'c');
    SeqStackPush(&stack,'d');
    SeqStackPush(&stack,'e');
    SeqStackPush(&stack,'f');
    SeqStackPrint(&stack,"入栈六个元素");
    
    SeqStackPop(&stack);
    SeqStackPop(&stack);
    SeqStackPop(&stack);
    SeqStackPrint(&stack,"出栈三个元素");
}

//测试取栈顶元素
void TesGetTop(){
    SeqStack stack;
    TESTHEAD;
    SeqStackInit(&stack);
    SeqStackPush(&stack,'a');
    SeqStackPush(&stack,'b');
    SeqStackPush(&stack,'c');
    SeqStackPush(&stack,'d');
    SeqStackPush(&stack,'e');
    SeqStackPush(&stack,'f');
    SeqStackPrint(&stack,"入栈六个元素");
    
    SeqStackType tmp = SeqStackTopValue(&stack);
    printf("expect f,actual:%c\n\n",tmp);
}

//测试取最小元素
void TestMinValue1(){
    SeqStack stack1;
    SeqStack stack2;
    SeqStackInit(&stack1);
    SeqStackInit(&stack2);
    TESTHEAD;
    SeqStackPush2(&stack1,&stack2,'g');
    SeqStackPush2(&stack1,&stack2,'d');
    SeqStackPush2(&stack1,&stack2,'c');
    SeqStackPush2(&stack1,&stack2,'a');
    SeqStackPush2(&stack1,&stack2,'e');
    SeqStackPush2(&stack1,&stack2,'f');

    SeqStackPop2(&stack1,&stack2);
    SeqStackPop2(&stack1,&stack2);
    SeqStackPop2(&stack1,&stack2);
    SeqStackPop2(&stack1,&stack2);

    SeqStackPrint(&stack1,"栈1");
    SeqStackPrint(&stack2,"栈2");

    SeqStackType min = SeqStackTopValue(&stack2);
    printf("expect d,actual:%c\n\n",min);
}

//测试取最小元素
void TestMinValue2(){
    SeqStack stack;
    SeqStackInit(&stack);

    TESTHEAD;
    SeqStackPush3(&stack,'d');
    SeqStackPush3(&stack,'e');
    SeqStackPush3(&stack,'f');
    SeqStackPush3(&stack,'a');
    SeqStackPush3(&stack,'c');

    SeqStackPop3(&stack);
    SeqStackPop3(&stack);

    SeqStackPrint(&stack,"栈打印");

    SeqStackType min = SeqStackTopValue(&stack);
    printf("expect d,actual:%c\n\n",min);

    //尝试取栈顶元素
    SeqStackType top = SeqStackGetTop(&stack);
    printf("expect f,actual:%c",top);
}

//测试出栈

int main(){
    TestPush();
    TestPop();
    TesGetTop();
    TestMinValue1();
    TestMinValue2();
    return 0;
}
