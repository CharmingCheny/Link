#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define OK 1
typedef struct
{
  int  *elem;     //ָ������Ԫ�صĻ���ַ
  int  length;       //���Ա�ĵ�ǰ����                                                           
}SqList;
int InitList(SqList &L)
{
	L.elem=new int[MAXSIZE]; //���ٴ洢�ռ� 
	if(!L.elem) exit(0);  //�洢ʧ���˳� 
	L.length=0;  //�ձ���Ϊ0 
	return OK;
 } 
int ListTailInsert(SqList &L,int i,int e)
{
	if((i<0)||(i>L.length)) return 0;  //�жϲ���λ���Ƿ�Ϸ� 
	if(L.length==MAXSIZE) return 0;  //�Ƿ񳤶ȳ�����󳤶� 
	L.elem[i]=e;
	L.length++;  //���ȵ��� 
	return OK;
 } 
void PrintList(SqList L)
{
	int i;
	for(i=0;i<L.length;i++)//ѭ����ӡÿ��Ԫ�� 
	{
		printf("%d\t",L.elem[i]);
	}
	printf("\n");
 } 
void LengthList(SqList L)//��ӡ���� 
{
	printf("���Ա�ĳ���Ϊ��%d\n",L.length);
}
int IsEmpty(SqList L)
{
	if(L.length==0) //Ϊ�� 
		return 1;
	else return 0; //��Ϊ�� 
}
int GetElem(SqList L,int i,int &e)
{
	if((i<0)||(i>L.length)) return 0;  //�жϲ���λ���Ƿ�Ϸ� 
	e=L.elem[i-1];  //ȡԪ�� 
	return OK;
 } 
int GetP(SqList L,int e) //���Ԫ��λ�� 
{
	int i;
	for(i=0;i<L.length;i++)
	{
		if(e==L.elem[i])  //�ж��Ƿ���� 
		{
			printf("%dԪ���ǵ�%d��Ԫ��",e,i+1);
			return OK;
		}		
	}
	return 0;
 } 
int ListInsert(SqList &L,int i,int e)
{
	int j;
	if((i<0)||(i>L.length)) return 0;  //�жϲ���λ���Ƿ�Ϸ� 
	if(L.length==MAXSIZE) return 0;  //�Ƿ񳤶ȳ�����󳤶� 
	for(j=L.length-1;j>=i-1;j--)  //����ƶ� 
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
	if((i<0)||(i>L.length)) return 0;  //�жϲ���λ���Ƿ�Ϸ� 
	for(j=i;j<L.length;j++)  //��ǰ�ƶ� 
		L.elem[j-1]=L.elem[j];
	L.length--;  //���ȵݼ� 
	return OK;
}
int main()
{
	int i,a,n,e;
	SqList L;
	InitList(L);  //��ʼ�� 
	a=IsEmpty(L);
	if(a==1) printf("��\n");  //�п� 
	else  printf("�ǿ�\n");
	printf("���������Ԫ�ظ�����");
	scanf("%d",&n);
	for(i=0;i<n;i++)  //β������ 
	{
		printf("���������Ԫ�أ�");
		scanf("%d",&e) ;
		ListTailInsert(L,i,e);
	}
	PrintList(L); //��ӡ 
	LengthList(L);  //���� 
	GetElem(L,3,e);  //���Ԫ�� 
	printf("%d\n",e);
	printf("������ȷ��λ�õ�Ԫ�أ�");
	scanf("%d",&e);
	GetP(L,e);  //���λ�� 
	printf("\n");
	ListInsert(L,4,0); //����Ԫ�� 
	printf("\n");
	PrintList(L); //��ӡ 
	printf("\n");
	ListDelete(L,5);//ɾ��Ԫ�� 
	printf("\n");
	PrintList(L); //��ӡ 
	printf("\n");
	return 0; 
}
