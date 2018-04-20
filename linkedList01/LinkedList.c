#include "LinkedList.h"
#include<stdlib.h>

//初始化链表
void LinkListInit(LinkNode** head){
	*head = NULL;
}

//实现创建一个新的结点
LinkNode* CreatNewNode(LinkType value){     
	LinkNode* NewNode = (LinkNode*)malloc(sizeof(LinkNode));
	NewNode->data = value;
	NewNode->next = NULL;
	return NewNode;
}

//打印代码函数
void PrintChar(LinkNode* head,char* msg){
	if(head == NULL){
		return;
	}
	printf("%s\n\n",msg);
	while(head){
		printf("[%c]",head->data);
		head=head->next;
	}
	printf("\n\n");
}

//实现销毁一个结点
void DestoryNode(LinkNode* node){        
	if(node == NULL){
		return;
	}
	free(node);
}

//实现删除节点
void LinkListDestory(LinkNode** head){
	if(head == NULL){
		//非法输入
		return;
	}
	if(*head == NULL){
		//空结点
		return;
	}
	LinkNode* cur = *head;
	while(*head !=NULL){
		cur = (*head)->next;
		DestoryNode(*head);
		*head = cur;
	}
	return;
}




//尾插一个元素到链表中
void LinkListPushBack(LinkNode** head,LinkType value){
	if(head == NULL){
		return;
	}
	if(*head == NULL){
		*head = CreatNewNode(value);
		return;
	}
	LinkNode *phead = *head;
	while(phead->next){
		phead = phead->next;
	}
	phead->next = CreatNewNode(value);
	return;
}


//尾删一个元素
void LinkListPopBack(LinkNode** head){
	if(head == NULL){
		//非法输入
		return;
	}
	if(*head == NULL){
		return;
		//空链表
	}
	if((*head)->next == NULL){
		DestoryNode(*head);
		*head == NULL;
		return;
	}
	LinkNode* pre = NULL;
	LinkNode* cur = *head;
	while(cur->next != NULL){
		pre = cur;
		cur = cur->next;
	}
	pre->next = NULL;
	DestoryNode(cur);
	return;
}

//头插一个元素
void LinkListPushHead(LinkNode** head,LinkType value){
	if(head ==NULL){
		return;
	}
	LinkNode* NewNode = CreatNewNode(value);
	NewNode->next = *head;
	*head = NewNode;
	return;
}

//头删一个元素
void LinkListPopHead(LinkNode** head){
	if(head == NULL){
		//非法输入
		return;
	}
	if(*head == NULL){
		//空链表
		return;
	}
	LinkNode* cur = *head;
	*head = (*head)->next;
	DestoryNode(cur);
	return;
}

//在下标为pos后插入值
void LinkListInsert(LinkNode* pos,LinkType value){
	if(pos == NULL){
		return;
	}
	LinkNode* NewNode = CreatNewNode(value);
	NewNode->next = pos->next;
	pos->next = NewNode;
	return;
}

//在下标为pos前插入值
void LinkListInsertBef(LinkNode** head,LinkNode* pos,LinkType value){
	if(head == NULL){
		//非法输入
		return;
	}
	if(*head == NULL){
		return;
		//空链表
	}
	if(pos == NULL){
		return;
	}
	LinkNode* NewNode = CreatNewNode(value);
	NewNode->next = pos->next;
	pos->next = NewNode;
	NewNode->data = pos->data;
	pos->data = value;
	return;
}

//查找一个元素的值，返回地址
LinkNode* LinkListFind(LinkNode* head,LinkType value){
	if(head == NULL){
		return NULL;
	}
	LinkNode* cur = head;
	for(;cur != NULL;cur=cur->next){
		if(cur->data == value){
			return cur;
		}
	}
	return NULL;
}

//实现删除指定的元素
void LinkListDelVal(LinkNode** head,LinkType value){
	if(head == NULL){
		//非法输入
		return;
	}
	if(*head == NULL){
		//空指针
		return;
	}
	LinkNode* cur = *head;
	LinkNode* pos = LinkListFind(*head,value);
	for(; cur != NULL; cur = cur->next){
		break;
	}
	if(cur == NULL){
		return;
	}
	cur->next = pos->next;
	DestoryNode(pos);
}

//删除一个元素值出现的所有情况
void LinkListDelAll(LinkNode** head,LinkType value){
	if(head == NULL){
		//非法输入
		return;
	}
	if(head == NULL){
		return;
	}
	LinkNode* cur = *head;
	while(cur != NULL){
		while(cur->data == value){
			cur = cur->next;
		}
		*head = cur;
		LinkNode* pos = *head;
		cur = cur->next;
		while(cur != NULL){
			if(cur->data !=value){
				pos->next = cur;
				pos = pos->next;
			}
			cur = cur->next;
		}
		pos->next == NULL;
		pos = pos->next;
		DestoryNode(pos);
	}
	return;
}

//实现元素个数
size_t LinkListSize(LinkNode* head){
	if(head == NULL){
		return 0;
	}
	LinkNode* pos = head;
	size_t count = 0;
	while(pos != NULL){
		++count;
		pos = pos->next;
	}
	return count;
}

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
//********************测试代码************************************//
////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////
#define FUNCTION printf("--------------------%s-------------------\n",__FUNCTION__);

//初始化
void TestInit(){
	LinkNode* head;
	LinkListInit(&head);
}

//测试尾插一个元素
void TestLinkListPushBack(){
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	PrintChar(head,"****************尾插四个元素**************");
}

//测试尾删元素
void TestLinkListPopBack(){
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	PrintChar(head,"****************尾插四个元素**************");
	LinkListPopBack(&head);
	PrintChar(head,"****************尾删一个元素**************");
}

//测试头插一个元素
void TestLinkListPushHead(){
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushHead(&head,'d');
	LinkListPushHead(&head,'c');
	LinkListPushHead(&head,'b');
	LinkListPushHead(&head,'a');
	PrintChar(head,"****************头插四个元素**************");
}

//测试头删一个元素
void TestLinkListPopHead(){
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushHead(&head,'d');
	LinkListPushHead(&head,'c');
	LinkListPushHead(&head,'b');
	LinkListPushHead(&head,'a');
	PrintChar(head,"****************头插四个元素**************");
	LinkListPopHead(&head);
	PrintChar(head,"****************头删一个元素**************");
}

//测试在pos下标后插入值
void TestLinkListInsert(){
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushHead(&head,'d');
	LinkListPushHead(&head,'c');
	LinkListPushHead(&head,'b');
	LinkListPushHead(&head,'a');
	PrintChar(head,"****************头插四个元素**************");
	LinkNode* pos = head->next;
	LinkListInsert(pos,'d');
	PrintChar(head,"************插入一个元素******************");
}
	
	
//测试查找一个元素
void TestLinkListFind(){
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	PrintChar(head,"****************尾插四个元素**************");
	LinkNode* pos = LinkListFind(head,'a');
	printf("pos except %p,actual %p\n",head->next,pos);
	PrintChar(head,"****************查找元素**************");

}
	
//测试在pos下标前插入一个元素
void TestLinkListInsertBef(){
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	PrintChar(head,"****************尾插四个元素**************");
	LinkNode* pos = LinkListFind(head,'d');
	LinkListInsertBef(&head,pos,'x');
	PrintChar(head,"********************在d之前插入**********");
}

//测试在pos下标前插入一个元素
void TestLinkListDelVal(){
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'d');
	PrintChar(head,"****************尾插四个元素**************");
	LinkListDelVal(&head,'b');
	PrintChar(head,"****************删除元素c*****************");
}

//测试删除所有的a元素
void TestLinkListDelAll(){
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'c');
	PrintChar(head,"****************尾插七个元素**************");
	LinkListDelAll(&head,'a');
	PrintChar(head,"****************删除所有的a元素**************");
}

//测试代码
void TestSize(){
	LinkNode* head;
	FUNCTION;
	LinkListInit(&head);
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'a');
	LinkListPushBack(&head,'b');
	LinkListPushBack(&head,'c');
	LinkListPushBack(&head,'c');
	size_t ret = LinkListSize(head);
	printf("szie = %d\n",ret);
}

//主函数
int main(){
	TestInit();
	TestLinkListPushBack();
	TestLinkListPopBack();
	TestLinkListPushHead();
	TestLinkListPopHead();
	TestLinkListInsert();
	TestLinkListFind();
	TestLinkListInsertBef();
	TestLinkListDelVal();
	TestLinkListDelAll();
	TestSize();
	return 0;
}

