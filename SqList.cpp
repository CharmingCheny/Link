#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
typedef struct
{
  int  *elem;     //指向数据元素的基地址
  int  length;       //线性表的当前长度                                                           
}SqList;
int InitList(SqList &L)
{
	L.elem=new int[MAXSIZE]; //开辟存储空间 
	if(!L.elem) exit(0);  //存储失败退出 
	L.length=0;  //空表长度为0 
	return OK;
 } 
int ListTailInsert(SqList &L,int i,int e)
{
	if((i<0)||(i>L.length)) return 0;  //判断插入位置是否合法 
	if(L.length==MAXSIZE) return 0;  //是否长度超过最大长度 
	L.elem[i]=e;
	L.length++;  //长度递增 
	return OK;
 } 
void PrintList(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)//循环打印每个元素 
	{
		printf("%d\t",L.elem[i]);
	}
	printf("\n");
 } 
void LengthList(SqList L)//打印长度 
{
	printf("线性表的长度为：%d\n",L.length);
}
int IsEmpty(SqList L)
{
	if(L.length==0) //为空 
		return 1;
	else return 0; //不为空 
}
int GetElem(SqList L,int i,int &e)
{
	if((i<0)||(i>L.length)) return 0;  //判断插入位置是否合法 
	e=L.elem[i-1];  //取元素 
	return OK;
 } 
int GetP(SqList L,int e) //获得元素位置 
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(e==L.elem[i])  //判断是否相等 
		{
			printf("%d元素是第%d个元素",e,i+1);
			return OK;
		}		
	}
	return 0;
 } 
int ListInsert(SqList &L,int i,int e)
{
	int j;
	if((i<0)||(i>L.length)) return 0;  //判断插入位置是否合法 
	if(L.length==MAXSIZE) return 0;  //是否长度超过最大长度 
	for(j=L.length-1;j>=i-1;j--)  //逐个移动 
	{
		L.elem[j+1]=L.elem[j];
	}
	L.elem[i-1]=e;
	L.length++;
	return OK;
}
int ListDelete(SqList &L,int i)
{
	int j;
	if((i<0)||(i>L.length)) return 0;  //判断插入位置是否合法 
	for(j=i;j<L.length;j++)  //向前移动 
		L.elem[j-1]=L.elem[j];
	L.length--;  //长度递减 
	return OK;
}
int main()
{
	int i,a,n,e;
	SqList L;
	InitList(L);  //初始化 
	a=IsEmpty(L);
	if(a==1) printf("空\n");  //判空 
	else  printf("非空\n");
	printf("请输入插入元素个数：");
	scanf("%d",&n);
	for(i=0;i<n;i++)  //尾部插入 
	{
		printf("请输入插入元素：");
		scanf("%d",&e) ;
		ListTailInsert(L,i,e);
	}
	PrintList(L); //打印 
	LengthList(L);  //长度 
	GetElem(L,3,e);  //获得元素 
	printf("%d\n",e);
	printf("请输入确定位置的元素：");
	scanf("%d",&e);
	GetP(L,e);  //获得位置 
	printf("\n");
	ListInsert(L,4,0); //插入元素 
	printf("\n");
	PrintList(L); //打印 
	printf("\n");
	ListDelete(L,5);//删除元素 
	printf("\n");
	PrintList(L); //打印 
	printf("\n");
	return 0; 
}
