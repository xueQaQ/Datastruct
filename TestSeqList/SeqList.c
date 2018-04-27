#include "SeqList.h"
#include<stdio.h>
#include<assert.h>

//初始化顺序表
void SeqListInit(SeqList* seq){
	assert(seq);           //对指针操作时必须先判断是否为空
	seq->size=0;           //->也相当于解引用
}

//打印顺序表
void SeqListPrint(SeqList* seq,char* ch){
	assert(seq);
	int i=0;
	printf("%s\n",ch);
	for( ;i<seq->size;i++){
		printf("下表元素%d的元素是:[%c]\n",i,seq->SeqListArr[i]);
	}
	printf("size=%ld\n\n",seq->size);
}

//尾插一个元素
void SeqListPushEnd(SeqList* seq,SeqListType value){    //参数 往哪个元素中插  要插入的元素
	assert(seq);
	if(seq->size >= SeqListMaxNum){
		printf("顺序表已满，无法插入！\n\n");
		return;
	}
	else{
		seq->SeqListArr[seq->size]=value;
		seq->size++;
	}
}

//尾删一个元素
void SeqListPopEnd(SeqList* seq){
	assert(seq);
	if(seq->size==0){
		printf("顺序表为空表，无法删除！\n\n");
		return;
	}
	else{
		seq->size--;
	}
}

//头插一个元素
void SeqListPushStart(SeqList *seq,SeqListType value){
	assert(seq);
	if(seq->size >= SeqListMaxNum){
		printf("顺序表已满，无法插入！\n\n");
		return;
	}
	else{
		int i=seq->size-1;
		for( ;i>=0;i--){
			seq->SeqListArr[i+1]=seq->SeqListArr[i];
		}
		seq->SeqListArr[0]=value;
		seq->size++;
	}
}

//头删一个元素
void SeqListPopStart(SeqList* seq){
	assert(seq);
	if(seq->size ==0){
		printf("顺序表为空，无法删除!\n\n");
		return;
	}
	else{
		int i=0;
		for( ;i<seq->size-1;i++){
			seq->SeqListArr[i]=seq->SeqListArr[i+1];
		}
		seq->size--;
	}
}

//在下标为pos处插入元素
void SeqListPushPosition(SeqList* seq,size_t pos,SeqListType value){
	assert(seq);
	if(seq->size >SeqListMaxNum){
		printf("顺序表已满，无法插入！\n\n");
		return;
	}
	else if(pos >= seq->size){
		printf("非法坐标！\n\n");
		return;
	}
	else{
		int i=seq->size-1;
		for( ;i>=pos;i--){
			seq->SeqListArr[i+1]=seq->SeqListArr[i];   //将pos元素后都后移，留出空间
		}
		seq->SeqListArr[pos]=value;
		seq->size++;
	}
}

//删除下标为pos的元素
void SeqListPopPosition(SeqList* seq, size_t pos)
{
		assert(seq);
		if (seq->size == 0){
			printf("顺序表为空表，无法删除！\n\n");
			return;
		}
		else if (pos >= seq->size){
			printf("非法坐标！\n\n");
			return;
		}
	else{
		int i = pos;
		for (; i < seq->size - 1; i++){
			seq->SeqListArr[i] = seq->SeqListArr[i + 1];
		}
		seq->size--;
	}
}

//修改下标为pos的元素
void SeqListSetList(SeqList* seq,size_t pos,SeqListType value){
	assert(seq);
	if(pos>=seq->size){
		printf("非法坐标!\n\n");
		return;
	}
	else{
		seq->SeqListArr[pos]=value;
	}
}

//读下标为pos的元素
SeqListType SeqListGetList(SeqList* seq,size_t pos){
	assert(seq);
	if(pos>=seq->size){
		printf("非法坐标!\n\n");
		return -1;
	}
	else{
		return seq->SeqListArr[pos];
	}
}

//查找value元素值的下标
size_t SeqListGetpos(SeqList* seq,SeqListType value){
	assert(seq);
	int i=0;
	for( ;i<seq->size;i++){
		if(seq->SeqListArr[i]==value){
			return i;
		}
	}
	return -1;
}

//****************************///////
/////////////测试代码///////////////
//****************************///////

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

//测试尾删一个元素
void TestSeqListPopEnd(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPopEnd(&seq);
	SeqListPrint(&seq,"***********在顺序表中尾删一个元素*******");
	printf("空表情况：\n");
	SeqListInit(&seq);
	SeqListPopEnd(&seq);
}

//测试头插一个元素
void TestSeqListPushStart(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPushStart(&seq,'e');
	SeqListPrint(&seq,"******头插一个元素至顺序表******");
}

//测试头删一个元素
void TestSeqListPopStart(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPopStart(&seq);
	SeqListPrint(&seq,"********在顺序表头删一个元素*******");
	printf("空表情况：\n");
	SeqListInit(&seq);
	SeqListPopStart(&seq);
}

//测试在pos处插入一个元素
void TestSeqListPushPosition(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPushPosition(&seq,2,'s');
	SeqListPrint(&seq,"****在顺序表指定位置插入元素*****");
	printf("非法坐标情况：\n");
	SeqListPushPosition(&seq,21,'r');
}
//测试删除下标为pos的元素
void TestSeqListPopPosition(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListPopPosition(&seq, 2);
	SeqListPrint(&seq, "*****在顺序表中指定位置删除一个元素*****");
	printf("非法坐标情况(删除下标为8的元素)：\n");
	SeqListPopPosition(&seq, 8);
}

//测试修改下标为pos的元素
void TestSeqListSetList(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'a');
	SeqListPushEnd(&seq, 'b');
	SeqListPushEnd(&seq, 'c');
	SeqListPushEnd(&seq, 'd');
	SeqListSetList(&seq, 1, 'o');
	SeqListPrint(&seq, "*****在顺序表中修改指定位置的元素*****");
	printf("非法坐标情况(修改下标为10的元素)：\n");
	SeqListSetList(&seq, 10, 'k');
}

void TestSeqListGetList(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'f');
	SeqListPushEnd(&seq, 'g');
	SeqListPushEnd(&seq, 'h');
	SeqListPrint(&seq,"*********在顺序表中读取指定位置元素******");
	char ch =SeqListGetList(&seq,1);
	printf("下标为1的元素为%c\n", ch);
	printf("非法坐标情况(读取下标为6的元素)：\n");
	SeqListGetList(&seq, 6);
}
	
//测试查找value元素值的下标
void TestSeqListGetpos()
{
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq, 'e');
	SeqListPushEnd(&seq, 'f');
	SeqListPushEnd(&seq, 'g');
	SeqListPushEnd(&seq, 'h');
	SeqListPrint(&seq, "*****在顺序表中读取指定位置元素下标*****");
	size_t pos = SeqListGetpos(&seq, 'h');
	printf("h元素的下标为%ld\n", pos);
	printf("非法情况(读取元素W的下标)：\n");
	size_t pos1 = SeqListGetpos(&seq, 'W');
	printf("W元素的下标为%ld，坐标非法！\n\n", pos1);
}


int main(){
	TestSeqListInit();
	TestSeqListPushEnd();
	TestSeqListPopEnd();
	TestSeqListPushStart();
	TestSeqListPopStart();
	TestSeqListPushPosition();
	TestSeqListPopPosition();
	TestSeqListSetList();
	TestSeqListGetList();
	TestSeqListGetpos();
	return 0;
}
