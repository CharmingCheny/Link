#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
typedef struct LNode{
     int data;       //������
     struct LNode  *next;   //ָ����
}LNode,*LinkList;  
int InitList(LinkList &L)
{
	L=new LNode;  //�����½ڵ���Ϊͷ��� 
	L->next=NULL;  //ָ�����ÿ� 
	return OK;
}
void CreatList_H(LinkList &L,int n) //��������Ԫ�� 
{
	LNode *p;
	L=new LNode;  //���������� 
	L->next=NULL;
	for(int i=0;i<n;i++)
	{
		p=new LNode;  //�����½ڵ� 
		printf("������Ԫ��:");
		scanf("%d",&(p->data));
		p->next=L->next;
		L->next=p; 
	}
}
int ListLength(LinkList L)
{
	LNode *p;
	p=L->next;
	int i=0;  //���� 
	while(p)  //�������� 
	{
		i++;
		p=p->next;
	}
	printf("��Ϊ:%d",i);
	return OK;
}
int ListEmpty(LinkList &L)
{
	if(L->next) return 0;  //�п� 
	else return 1;
 } 
int GetElem(LinkList L,int i,int &e)
{
	LNode *p;
	p=L->next;  //��ʼ�� 
	int j=1;
	while(p&&i<i) //���ɨ�� 
	{
		p=p->next;
		j++;  //������+1 
	}
	if(!p||j>i) return 0;  //�ж�i�Ƿ�Ϸ� 
	e=p->data;
	return OK;
}
void *LocateElem(LinkList L,int e)
{
	LNode *p;
	int i=0;
	p=L->next;
	while(p&&p->data!=e)  //�ж��Ƿ�Ϊ˵��Ԫ�� 
	{
		p=p->next;
		i++;
	}
	printf("%dԪ���ǵ�%d��Ԫ��",e,i+1);
 } 
int ListInsert(LinkList &L,int i,int e)
{
	LNode *p,*s;
	p=L;
	int j=0;
	while(p&&(j<i-1)) 
	{
		p=p->next;//����i-1���ڵ� 
		j++;
	}
	if(!p||j>i-1) return 0;  //�д� 
	s=new LNode;  //�����½ڵ� 
	s->data=e;
	s->next=p->next;
	p->next=s;
	return OK;	
}
int PrintList(LinkList L) //��ӡ���� 
{
	LNode *p; 
	p=L->next;
	if(p==NULL)
	{
		printf("�ձ�");
		return 0;
		}
		while(p!=NULL)  //�������� 
		{
			printf("%d\t",p->data); //�����ӡ 
			p=p->next;
			}
			printf("\n");	
		return OK;
}
int ListDelete(LinkList &L,int i) //ɾ�� 
{
	LNode *p,*q;
	p=L;
	int j=0;
	while((p->next)&&(j<i-1)) //������� 
	{
		p=p->next;
		j++;
	}
	if(!(p->next)||(j>i-1)) return 0;//�жϺϷ��� 
	q=p->next;  
	p->next=q->next;
	delete q;
	return OK;
}
int main()
{
	int i,a,e;
	LinkList L;
	InitList(L);  //��ʼ�� 
	CreatList_H(L,5);  //ͷ�巨 
	PrintList(L);//��� 
		printf("\n");
	ListLength(L); //��

	a=ListEmpty(L);
	if(a==1) printf("��\n");  //�п� 
	else  printf("�ǿ�\n");
	GetElem(L,3,e); //���Ԫ�� 
	printf("%d\n",e);
	LocateElem(L,24);//Ԫ��λ�� 
		printf("\n");
	ListInsert(L,4,0); //����
		printf("\n");
	PrintList(L);//��� 
		printf("\n");
	ListDelete(L,5); //ɾ�� 
		printf("\n");
	PrintList(L);//��� 
		printf("\n");
	return 0; 
 } 
 
