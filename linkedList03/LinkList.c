#include "LinkList.h"
#include<stdio.h>
#include<stdlib.h>

//实现创建
DLinkNode* DLinkListCreatNode(DLinkType value){
    DLinkNode* New_Node = (DLinkNode*)malloc(sizeof(DLinkNode));
    New_Node->data = value;
    New_Node->next = NULL;
    New_Node->prev = NULL;
    return New_Node;
}

//实现打印
void DLinkListPrint(DLinkNode* head,const char* msg){
    if(head == NULL){
        printf("非法输入\n");
        return;
    }
    printf("[*****%s*****]\n",msg);
    DLinkNode* cur = head->next;
    for(; cur != head; cur = cur->next){
        printf("[%c|%p]\t",cur->data,cur);
    }
    printf("\n");
    return;
}

//实现初始化
void DLinkListInit(DLinkNode** head){
    if(head == NULL){
        //非法输入
        return;
    } 
    *head =DLinkListCreatNode(0);
    (*head)->prev = *head;
    (*head)->next = *head;
    return;
}

//实现尾插
void DLinkListPushBack(DLinkNode* head, DLinkType value){
    if(head == NULL){
        //非法输入
        return;
    }
    DLinkNode* New_Node = DLinkListCreatNode(value);
    New_Node->data = value;
    DLinkNode* tail = head->prev;
   //此时三个值 tail(原来的末尾)  head(头)  New_Node(新加入的值,现在的末尾)
   //实现两组指针的指向prev和next的指向
   New_Node->next = head;
   head->prev = New_Node;
   New_Node->prev = tail;
   tail->next = New_Node;
}

//尾删
void DLinkListPopBack(DLinkNode* head){
    if(head == NULL){
        //非法输入
        return;
    }
    if(head->next == NULL){
        //空链表
        return;
    }
    DLinkNode* tailprev = head->prev->prev;
    free(tailprev->next);
    tailprev->next = head;
    head->prev = tailprev;
}

//头插
void DLinkListPushFront(DLinkNode*head, DLinkType value){
    if(head == NULL){
        //非法输入
        return;
    }
    DLinkNode* New_Node = DLinkListCreatNode(value);
    New_Node->next = head->next;
    New_Node->next->prev = New_Node;
    head->next = New_Node;
    New_Node->prev = head;
}

//头删
void DLinkListPopFront(DLinkNode* head){
    if(head == NULL){
        //非法输入
        return;
    }
    if(head->next == NULL){
        printf("空链表\n");
        return;
    }
    DLinkNode* to_deleted = head->next;
    head->next = to_deleted->next;
    to_deleted->next->prev = head;
    free(to_deleted);
}

//查找
DLinkNode* DLinkListFind(DLinkNode* head,DLinkType to_find){
    if(head == NULL){
        return;
    }
    DLinkNode* cur = head->next;;
    while(cur != head){
        if(cur->data == to_find){
                return cur;
        }
            cur = cur->next;
    }
    return NULL;
}

//在指定位置之前插入一个元素
void DLinkListInsert(DLinkNode* pos,DLinkType value){
    if(pos == NULL){
        return;
    }
    DLinkNode* New_Node = DLinkListCreatNode(value);
    DLinkNode* cur = pos->prev;
    cur->next = New_Node;
    New_Node->prev = cur;
    New_Node->next = pos;
    pos->prev = New_Node;
}

//在制定元素位置之后插入一个元素
void DLinkListInsertAfter(DLinkNode* pos,DLinkType value){
    if(pos == NULL){
        return;
    }
    DLinkNode* New_Node = DLinkListCreatNode(value);
    DLinkNode* Next_Node =pos->next;
    New_Node->next = Next_Node;
    Next_Node->prev = New_Node;
    pos->next = New_Node;
    New_Node->prev = pos;
}

//替换一个元素
void DLinkListErase(DLinkNode* pos,DLinkType value){
    if(pos == NULL){
        return;
    }
    pos-> data = value;
}

//
void DLinkListRemoceAll(DLinkNode* head, DLinkType value){
    if(head == NULL){
        return;
    }
    
}

//////////////////////////////////////////////
//********************************************
//*********Test Code**************************
//////////////////////////////////////////////

//测试尾插
void TestDLinkListPushBack(){
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPrint(head,"尾插元素");
}

//测试尾删
void TestDLinkListPopBack(){
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPopBack(head);
    DLinkListPrint(head,"尾删元素");
}

//测试头插
void TestDLinkListPushFront(){
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushFront(head,'a');
    DLinkListPushFront(head,'b');
    DLinkListPushFront(head,'c');
    DLinkListPushFront(head,'d');
    DLinkListPrint(head,"头插元素");
}

//测试头删
void TestDLinkListPopFront(){
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkListPopFront(head);
    DLinkListPrint(head,"头删元素");
}

//测试在一个元素之前插入
void TestDLinkListInsert(){
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkNode* pos = DLinkListFind(head,'c');
    DLinkListInsert(pos,'x');
    DLinkListPrint(head,"在元素之前插入一个元素");
}


//测试在一个元素之后插入
void TestDLinkListInsertAfter(){
    DLinkNode* head;
    DLinkListInit(&head);
    DLinkListPushBack(head,'a');
    DLinkListPushBack(head,'b');
    DLinkListPushBack(head,'c');
    DLinkListPushBack(head,'d');
    DLinkNode* pos = DLinkListFind(head,'c');
    DLinkListInsertAfter(pos,'x');
    DLinkListPrint(head,"在元素之后插入一个元素");
}

int main(){
    TestDLinkListPushBack();
    TestDLinkListPopBack();
    TestDLinkListPushFront();
    TestDLinkListPopFront();
    TestDLinkListInsert();
    TestDLinkListInsertAfter();
    return 0;
}
