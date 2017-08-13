# include "stdio.h"
# include "stdlib.h"
typedef int ElemType;
typedef struct DuNode  {
 ElemType data;
struct  DuNode *prior;
struct  DuNode *next;
}DuLNode,*DuLinkList;

void InitList_DuL(DuLinkList &L)
    {  
L=(DuLNode *)malloc(sizeof(DuLNode));    // ������һ�������������Ҫ�����ڿռ�
if(!L)   exit(1);                        // �洢����ʧ��
L->next=L;                               // ��ͷ�����Ϊ��ͷ���ĺ��
L->prior=L;                              // ��ͷ�����Ϊ��ͷ����ǰ��
    }

bool ListInsert_DuL(DuLinkList &L,int i,ElemType e) 
    {
       // �ڴ�ͷ����˫������L�е�i�����֮ǰ����Ԫ��e
  DuLinkList p,s;
   int j;
   p=L->next;  j=1;
   while(p!=L&&j<i)  { p=p->next; j++; }   // Ѱ�ҵ�i�����,����pָ��˽��
   if(j!=i)   return false;                   // i��λ�ò�����
   s=(DuLNode *)malloc(sizeof(DuLNode));
if(!s)   exit(1);                          // �洢����ʧ��
   s->data=e;  
s->prior=p->prior;                                  // �޸�ָ��
p->prior->next=s;      
s->next=p;
p->prior=s;
return true;
}

bool ListDelete_DuL(DuLinkList &L, int i, ElemType &e)
{
           // ɾ������ͷ����˫������L�еĵ�i����㣬����e������ֵ
DuLinkList p;
  int j;
  p=L;  j=0;
 while(p->next!=L&&j<i){ p=p->next; j++; }      // Ѱ�ҵ�i�����,����pָ��˽��
   if(j!=i)   return false;                    // i��λ�ò�����
  e=p->data;                                  // ��ȡԪ�ص�ֵ����e
    p->prior->next=p->next;                     // �޸�ָ��
    p->next->prior=p->prior;
free(p);                                    // �ͷŽ��p�Ŀռ�
  return true;
 }

    void main()
     {int a,e;
      DuLinkList head,p,q;
      p=q=head=(DuLNode*)malloc(sizeof(DuLNode));
      scanf("%d",&a);
      while(a!=0)
       {p=(DuLNode*)malloc(sizeof(DuLNode));
        p->data=a;
        p->prior=q;
        q->next=p;
        q=p;
        scanf("%d",&a);}
        q->next=head;
		head->prior=q;
        printf("����֮ǰ��˫��������:");
        p=head->next;
        while(p!=head)
        {printf("%3d,",p->data);
         p=p->next;}
         printf("\n");
        if(ListInsert_DuL(head,1,7))
		{
			printf("����ɹ�\n");
			printf("����֮���˫��������:");
            p=head->next;
            while(p!=head)
			{printf("%3d,",p->data);
            p=p->next;}
            printf("\n");
		}  
		else printf("����ʧ��\n");
        
        if(ListDelete_DuL(head,1,e))
		{	
			printf("ɾ���ɹ�\n");
            printf("��ɾ����Ԫ���ǣ�%d\n",e);
           printf("ɾ��֮���˫��������:");
           p=head->next;
          while(p!=head)
		  {printf("%3d,",p->data);
           p=p->next;}
           printf("\n");
		}
        else printf("ɾ��ʧ��\n");
       }