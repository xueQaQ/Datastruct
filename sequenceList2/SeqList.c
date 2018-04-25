#include"SeqList.h"

//实现顺序表的初始化
void SeqListInit(SeqList *seq){
	if(seq == NULL){           //非法输入
		return;                  
	}
	seq->size=0;             //初始化给赋值为0
}

//实现顺序表打印
void SeqListPrint(SeqList *seq,char* ch){
	if(seq == NULL){
		return;              //非法输入
	}
	printf("%s\n",ch);
	int i=0;
	for(;i<seq->size;++i){
		printf("下表元素[%d]的值是[%c]\n",i,seq->SeqListArr[i]);
	}
	printf("size=%ld\n\n",seq->size);
}

//实现尾插
void SeqListPushEnd(SeqList *seq,SeqListType value){
	if(seq == NULL){           //非法输入
		return;
	}
	if(seq->size >= SeqListMaxNum){
		printf("顺序表已满，无法插入\n\n");
		return;
	}
	else{
		seq->SeqListArr[seq->size]=value;
		++seq->size;
	}
}

//实现尾删
void SeqListPopEnd(SeqList* seq){
	if(seq==NULL){             //非法输入
		return;
	}
	--seq->size;
}

//实现头插一个元素
void SeqListPushStart(SeqList* seq,SeqListType value){
	if(seq==NULL){
		return;
	}
	int i=0;
	for(;i<seq->size;++i){
		seq->SeqListArr[i]=seq->SeqListArr[i+1];
	}
	seq->SeqListArr[seq->size]=value;
	++seq->size;
}

//实现头删
void SeqListPopStart(SeqList* seq){
	if(seq==NULL){
		return;
	}
	int i=0;
	for(;i<seq->size-1;++i){
		seq->SeqListArr[i+1]=seq->SeqListArr[i];
	}
	--seq->size;
}

//实现取顺序表中任意位置的元素即查找下标为pos的元素
SeqListType SeqListGet(SeqList* seq,size_t pos){
	if(seq==NULL){
		//非法输入
		return;
	}
	//if(seq->size>SeqListMaxNum){
	//	return;
	//}
	if(pos>=seq->size){
		printf("非法坐标");
		return -1;
	}
	return seq->SeqListArr[pos];
}

//交换函数
//void SeqListSwap(SeqListType* a,SeqListType* b){
//	size_t temp;
//	*a=temp;
//	*b=*a;
//	temp=*b;
//}

//实现冒泡排序
//void SeqListBubbleSortEx(SeqList* seq){
//	if(seq==NULL){
//		//非法输入
//		return;
//	}
//	size_t i=0;
//	for(;i<seq->size-1;++i){
//		size_t j=0;
//		for(;j<seq->size-i-1;++j){
//			if(seq->SeqListArr[i]>seq->SeqListArr[i+1]){
//				SeqListSwap(seq->SeqListArr[i],seq->SeqListArr[i+1]);
//			}
//		}
//	}
//}

	
//实现在指定位置的下标插入
void SeqListPushPosition(SeqList* seq,size_t pos,SeqListType value){
	if(seq==NULL){
		//非法输入；
		return;
	}
	if(pos>=seq->size){
		printf("输入位置出错");
	}
	else{
	int i = seq->size-1;
	for(;i>=pos;--i){
		seq->SeqListArr[pos+1]=seq->SeqListArr[pos];
	}
	seq->SeqListArr[pos]=value;
	++seq->size;
	}
}


//在顺序表的指定下删除元素
void SeqListPosPosition(SeqList* seq,size_t pos){
	if(seq==NULL){
		//非法输入；
		return;
	}
	if(pos>=seq->size){
		printf("输入位置越界");
	}else{
	int i=seq->size-1;
	for(;i>=pos;--i){
		seq->SeqListArr[i+1]=seq->SeqListArr[i];
	}
	--seq->size;
	}
}




/////////////////////////////////////////////////////////////
//******测试代码********************************************
//**********************************************************
////////////////////////////////////////////////////////////

//测试尾插
void TestSeqListPushEnd(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq,'a');
	SeqListPushEnd(&seq,'b');
	SeqListPushEnd(&seq,'c');
	SeqListPushEnd(&seq,'d');
	SeqListPrint(&seq,"*****************尾插一个元素**************");
}

//测试尾删

void TestSeqListPopEnd(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq,'a');
	SeqListPushEnd(&seq,'b');
	SeqListPushEnd(&seq,'c');
	SeqListPushEnd(&seq,'d');
	SeqListPopEnd(&seq);
	SeqListPrint(&seq,"*****************尾删一个元素**************");
}

//测试头插
void TestSeqListPushStart(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq,'a');
	SeqListPushEnd(&seq,'b');
	SeqListPushEnd(&seq,'c');
	SeqListPushEnd(&seq,'d');
	SeqListPushStart(&seq,'x');
	SeqListPrint(&seq,"*****************头插一个元素**************");
}

//测试头删
void TestSeqListPopStart(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq,'a');
	SeqListPushEnd(&seq,'b');
	SeqListPushEnd(&seq,'c');
	SeqListPushEnd(&seq,'d');
	SeqListPopStart(&seq);
	SeqListPrint(&seq,"*****************头删一个元素**************");
}

//测试查找下标为pos的元素值
void TestSeqListGet(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq,'a');
	SeqListPushEnd(&seq,'b');
	SeqListPushEnd(&seq,'c');
	SeqListPushEnd(&seq,'d');
	//SeqListGet(&seq,1);
	SeqListPrint(&seq,"*****************查找一个元素**************");
	size_t pos=SeqListGet(&seq,'b');
	printf("元素1的下标是ld%\n",pos);
}

//测试冒泡排序
//void TestSeqListBubbleSortEx(){
//	SeqList seq;
//	SeqListInit(&seq);
//	SeqListPushEnd(&seq,'a');
//	SeqListPushEnd(&seq,'b');
//	SeqListPushEnd(&seq,'c');
//	SeqListPushEnd(&seq,'d');
//	SeqListPrint(&seq,"*****************冒泡*****************");
//}


//测试在指定下标插入元素
void TestSeqListPushPosition(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq,'a');
	SeqListPushEnd(&seq,'b');
	SeqListPushEnd(&seq,'c');
	SeqListPushEnd(&seq,'d');
	SeqListPushPosition(&seq,2,'x');
	SeqListPrint(&seq,"*****************查找下表为2的元素**************");
}

//测试在指定下标删除元素
void TestSeqListPosPosition(){
	SeqList seq;
	SeqListInit(&seq);
	SeqListPushEnd(&seq,'a');
	SeqListPushEnd(&seq,'b');
	SeqListPushEnd(&seq,'c');
	SeqListPushEnd(&seq,'d');
	SeqListPosPosition(&seq,2);
	SeqListPrint(&seq,"*****************删除下表为2的元素**************");
}


int main(){
	TestSeqListPushEnd();
	TestSeqListPopEnd();
	TestSeqListPushStart();
	TestSeqListPopStart();
	TestSeqListGet();
	TestSeqListPushPosition();
	TestSeqListPosPosition();
//	TestSeqListBubbleSortEx();
	return 0;
}
