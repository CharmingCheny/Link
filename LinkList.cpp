#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
typedef struct LNode{
     int data;       //数据域
     struct LNode  *next;   //指针域
}LNode,*LinkList;  
int InitList(LinkList &L)
{
	L=new LNode;  //生成新节点作为头结点 
	L->next=NULL;  //指针域置空 
	return OK;
}
void CreatList_H(LinkList &L,int n) //逆着输入元素 
{
	LNode *p;
	L=new LNode;  //建立空链表 
	L->next=NULL;
	for(int i=0;i<n;i++)
	{
		p=new LNode;  //生成新节点 
		printf("请输入元素:");
		scanf("%d",&(p->data));
		p->next=L->next;
		L->next=p; 
	}
}
int ListLength(LinkList L)
{
	LNode *p;
	p=L->next;
	int i=0;  //计数 
	while(p)  //遍历链表 
	{
		i++;
		p=p->next;
	}
	printf("表长为:%d",i);
	return OK;
}
int ListEmpty(LinkList &L)
{
	if(L->next) return 0;  //判空 
	else return 1;
 } 
int GetElem(LinkList L,int i,int &e)
{
	LNode *p;
	p=L->next;  //初始化 
	int j=1;
	while(p&&i<i) //向后扫描 
	{
		p=p->next;
		j++;  //计数器+1 
	}
	if(!p||j>i) return 0;  //判断i是否合法 
	e=p->data;
	return OK;
}
void *LocateElem(LinkList L,int e)
{
	LNode *p;
	int i=0;
	p=L->next;
	while(p&&p->data!=e)  //判断是否为说找元素 
	{
		p=p->next;
		i++;
	}
	printf("%d元素是第%d个元素",e,i+1);
 } 
int ListInsert(LinkList &L,int i,int e)
{
	LNode *p,*s;
	p=L;
	int j=0;
	while(p&&(j<i-1)) 
	{
		p=p->next;//查找i-1个节点 
		j++;
	}
	if(!p||j>i-1) return 0;  //判错 
	s=new LNode;  //生成新节点 
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;	
}
int PrintList(LinkList L) //打印链表 
{
	LNode *p; 
	p=L->next;
	if(p==NULL)
	{
		printf("空表");
		return 0;
		}
		while(p!=NULL)  //遍历链表 
		{
			printf("%d\t",p->data); //逐个打印 
			p=p->next;
			}
			printf("\n");	
		return OK;
}
int ListDelete(LinkList &L,int i) //删除 
{
	LNode *p,*q;
	p=L;
	int j=0;
	while((p->next)&&(j<i-1)) //这个遍历 
	{
		p=p->next;
		j++;
	}
	if(!(p->next)||(j>i-1)) return 0;//判断合法性 
	q=p->next;  
	p->next=q->next;
	delete q;
	return OK;
}
int main()
{
	int i,a,e;
	LinkList L;
	InitList(L);  //初始化 
	CreatList_H(L,5);  //头插法 
	PrintList(L);//输出 
		printf("\n");
	ListLength(L); //表

	a=ListEmpty(L);
	if(a==1) printf("空\n");  //判空 
	else  printf("非空\n");
	GetElem(L,3,e); //获得元素 
	printf("%d\n",e);
	LocateElem(L,24);//元素位置 
		printf("\n");
	ListInsert(L,4,0); //插入
		printf("\n");
	PrintList(L);//输出 
		printf("\n");
	ListDelete(L,5); //删除 
		printf("\n");
	PrintList(L);//输出 
		printf("\n");
	return 0; 
 } 
 
