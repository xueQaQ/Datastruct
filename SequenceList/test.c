#include"SeqList.h"
#include<stdio.h>

/****************************///////
/////////////测试代码///////////////
/****************************///////

//测试初始化顺序表
void TestSeqListInit(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPrint(&seq,"**********初始化顺序表********");
}

//测试尾插一个元素
void TestSeqListPushEnd(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPrint(&seq,"*********尾插元素**********");
}
