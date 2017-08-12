typedef int ElemType;      // ˳�����Ԫ������Ϊint
#include "stdlib.h"       // ���ļ�����malloc()��realloc()��free()�Ⱥ���
#include "iomanip.h"      // ���ļ�������׼���������cout��cin�����Ʒ�setw()
#include "LinkList.h"       // ���ļ��а����������ݶ������������ز���
#include "SqList.h"       // ���ļ��а����������ݶ������������ز���


//��֪�ǿյ������һ�������headָ������дһ�㷨������p��ָ���������һ������������е�λ��
void Reverse(LinkList &L, LinkList p)
{
 LinkList q,r;
 q = L;
 r = p->next;
 while(q->next!=NULL&&q->next->data!=p->data)
 q = q->next;    //����qָ����p֮ǰ��һ���ڵ�
  
 if(r)
	{
	  q->next = p->next;
	  p->next = r->next;
	  r->next = p;
	     
	} 
 
}

//ϰ��2.1
//˳���L���������������Ԫ��x���뵽L��ĳλ�ã��Ա��������� 
void SLOrderInsert(SqList &L, ElemType e)
{   
    int i;
    L.length = ListLength_Sq(L);
	if(e<L.elem[0]) {ListInsert_Sq(L,0,e);}
	else
	{
		for(i=0; i<=L.length-1; i++)
    	{	 
    		 if(e <=L.elem[i])
    		 {
			 ListInsert_Sq(L,i,e);
    		 break;
			 }
    	}
	}
  	
}

//ϰ��2.2
//˳�������� 
void Converse_Sq(SqList &L)
{
   int mid, i;
   ElemType x;
   mid=L.length/2;
   for(i=0;i<mid;i++)
   {
      x=L.elem[i];
      L.elem[i]=L.elem[L.length-1-i];
      L.elem[L.length-1-i]=x;
   }
}


//ϰ��2.3
//����ǰ�����λ��� 
void Converse2_Sq(ElemType a[],int low, int high)
 { 
   int n,i;
   ElemType x;
   n=(high-low+1)/2;
   for(i=0;i<n;i++)
   {
     x=a[low+i];
     a[low+i]=a[high-i];
     a[high-i]=x;
    }
  }

void Exchange_Sq(ElemType a[],int m,int n)
 {
    Converse2_Sq(a,0,m+n-1); //������a���� 
    Converse2_Sq(a,0,n-1);   //������aǰ�� 
    Converse2_Sq(a,n,n+m-1); //������a��� 
 }


 
//ϰ��2.4
//ɾ��˳���ֵ��(s,t)��Χ�ڵ�����Ԫ�� 
void Delete_Section(SqList &L,ElemType s,ElemType t)
{
   ElemType e;
   int i,k;
   for(i=0;i<L.length;i++)
    if(L.elem[i]>=s&&L.elem[i]<=t)
      ListDelete_Sq(L,i,e);
 }


//ϰ��2.5
//����������� 
void Inverse_L(LinkList &L)
 { 
   LinkList p, q;
   p=L->next;    
   L->next=NULL;//��ͷ���� 
 
   while(p)    //��p��ֵ 
   {
     q=p;
     p=p->next;
     q->next=L->next;
	 L->next=q;
   }
 }
 
 
 void Inverse_L2(LinkList &L)
 {
    LinkList p, q, k;
    p = L->next;
    L->next=NULL;   //��ͷ���� 
    k = p->next;
    p->next = NULL; //����β�ڵ�

    while (k)  //k�൱��ʼ������pһ��  
	{          
 	  q = p;
 	  p = k;
 	  k = k->next;
      p->next = q;//��ÿ����ͷ����  
	}
	L->next = p;
 }


//ϰ��2.6
//������ĵ������� 
 void LinkListSort(LinkList &L)
{
  LinkList curr,pre,p,q;
  p=L->next;
  L->next=NULL;
  
  while(p)
  {
    curr=L->next;
    pre=L;
    while(curr&&curr->data<=p->data)
    {//�������� 
      pre=curr;
      curr=curr->next;
    }
    q=p;
    p=p->next;
    q->next=pre->next;
    pre->next=q;
  }
}

// �㷨2.7
// ����ͷ�����������ɾ��
bool NListInsert_L( LinkList &L, int i, ElemType e) 
{    //�ڲ�����ͷ���ĵ�����L�еĵ�i�����֮ǰ����Ԫ��e
  LinkList p,newElem;
  int j=0;
  p=L;  
  while(p->next&&j<i-1)  { p=p->next; j++; }  // Ѱ�ҵ�i-1�����,����pָ��˽��
  if(j!=i-1&&i!=1)   return false;         // i��λ�ò�����
  if((newElem=(LNode *)malloc(sizeof(LNode)))==NULL) exit(1); // �洢����ʧ��
  newElem->data=e;  
  if(i==1)                                 // �����ڱ�ͷ
  {
    newElem->next=L;
    L=newElem;
  }
  else
  {  newElem->next=p->next;  p->next=newElem;   }     // �����½��
    return true;
 }


bool NListDelete_L( LinkList &L, int i) 
{    // ɾ��������ͷ���ĵ�����L�еĵ�i����㣬����e������ֵ
  ElemType e;
  LinkList p,q;
  int j;
  p=L;  j=0;
  while(p->next&&p->next->next&&j<i-1){ p=p->next; j++; }  
  // Ѱ�ҵ�i-1�����,����pָ��˽��
  if(j!=i-1&&i!=1)   return false;         // i��λ�ò�����
  if(i==1)                                 // ɾ����ͷ���
   {
     q=p;
     L=L->next;
   }
   else
   {
    q=p->next;                            // qָ������
    p->next=q->next;                      // ɾ��q��ָ���
    e=q->data;    free(q);
   }
   return true;
 }

//�㷨2.8
//˫�������������Ԫ�ز�����ȡ����Ԫ�ز���

typedef struct DuNode  {
 ElemType data;
struct  DuNode *prior;
struct  DuNode *next;
}DuLNode,*DuLinkList;
int ListLength_DuL(DuLinkList &L)
{   // ͳ�ƴ�ͷ����˫��ѭ������L
  DuLinkList p=L->next;
  int num=0;
  while(p!=L)
  {
	  num++;
	  p=p->next;
  }
  return num;
}

bool ListGet_DuL(DuLinkList &L, int i, ElemType &e)
{   // �ڴ���ͷ����˫��ѭ������L�е�ȡ��i����㣬����e������ֵ
  DuLinkList p;
  int j;
  p=L->next;  j=1;
  while(p->next!=L&&j<i){ p=p->next; j++; }
// Ѱ�ҵ�i�����,����pָ��˽��
   if(j!=i)   return false;                  // i��λ�ò�����
   e=p->data;                                // ��ȡԪ�ص�ֵ����e
  return true;
 }

 
//�㷨2.9
//�жϵ�����Lb�Ƿ����La 
 bool IsSubSet(LinkList La, LinkList Lb)
{
  bool  ok1,ok2;
  LinkList p1,p2;
  ok1=true;
  p1=La->next;
  while(ok1&&p1)
  {
    ok2=false;
    p2=Lb->next;
    while(!ok2&& p2)
	   {
      if(p2->data==p1->data)   ok2=true;
      else  p2=p2->next;
    }
    ok1=ok2;
    p1=p1->next;
    }
    return   ok1;
}

//�㷨2.10
//La,Lb����������ϲ�La,Lb��Lc��Lc�ݼ�������ͬ��ֵֻ����һ�� 
void merge_L(LinkList La, LinkList Lb,  LinkList &Lc)
{
  LinkList pa,qa,pb,qb;
  Lc=La; pa=La->next; Lc->next=NULL;
  pb=Lb->next; free(Lb);
  while(pa&&pb)
  {
    if(pa->data<pb->data)
    {
      qa=pa;
      pa=pa->next;
	      qa->next=Lc->next;
      Lc->next=qa;
}
    else 
	   if(pa->data>pb->data)
	   {
        qb=pb;
        pb=pb->next;
        qb->next=Lc->next;
        Lc->next=qb;
	   }
	   else 
	   {
       qa=pa;
	      qb=pb;
       pa=pa->next;
	      pb=pb->next;
	      qa->next=Lc->next;
       Lc->next=qa;
	      free(qb);
	   }
   }
   while(pa)
   {
     qa=pa;
     pa=pa->next;
     qa->next=Lc->next;
     Lc->next=qa;
   }
   while(pb)
   {
     qb=pb;
     pb=pb->next;
     qb->next=Lc->next;
     Lc->next=qb;
   }
}
 
//�㷨2.11
//������������Ľ���
void Interaction(LinkList La,LinkList Lb,LinkList &Lc)
 {
   LinkList pa,pb,pc;
   LinkListSort(La);
   LinkListSort(Lb);    //���õ�6���������
   pa=La->next;
   pb=Lb->next;
   Lc=(LinkList)malloc(sizeof(LNode));
   Lc->next=NULL;
   while(pa && pb)
    if(pa->data < pb->data)
      pa = pa->next;
    else  if(pa->data>pb->data)
            pb=pb->next;
          else
          {
            pc=(LinkList)malloc(sizeof(LNode));
            pc->data=pa->data;
            pc->next=Lc->next;
            Lc->next=pc;
            pa=pa->next;
            pb=pb->next;
          }
}

void Interaction2(LinkList La,LinkList Lb,LinkList &Lc)
{//��ʼ���������Ϊ�գ���������1��������2�в�������ÿһԪ��
 //�������2��Ҳ�����Ԫ�أ��򽫸�Ԫ�ز��뵽��������С�
  LinkList pa,pb,pc1,pc2;
  pa=La->next;
  pb=Lb->next;
  pc2 = Lc; //pc2ʼ��ָ��β�ڵ㣬��β�巨 
  while(pa->data)  
    {  
        while(pb->data)
		{
		  if(pa->data == pb->data)//����ҵ���ͬԪ�� 
		  pc1=(LinkList)malloc(sizeof(LNode));//����һ��pc1 
		  pc1->data = pa->data; 
		  pc2->next= pc1; 
		  pc2 = pc1;
		  pb = pb->next;
		}    
        pa = pa->next;  
    }  
}
//�㷨2.12
//L��������ͷ��㣬ÿ���ڵ�洢һ���ַ���Ӣ�ġ����ֻ����ģ�
//��������������ֱ��ʾÿ���ַ�
void  Decompose(LinkList L,LinkList &ha,LinkList &hb,LinkList &hc)
 {
   LinkList p,q;
   p=L;
   ha=(LNode *)malloc(sizeof(LNode));
   hb=(LNode *)malloc(sizeof(LNode));
   hc=(LNode *)malloc(sizeof(LNode));
   ha->next=ha;
   hb->next=hb;
   hc->next=hc;
   while(p)
   {
     if('A'<=p->data && p->data<='Z'||'a'<=p->data && p->data<='z')
     {
       q=p; p=p->next;
       q->next=ha->next;
       ha->next=q;
     }
     else if('0'<=p->data && p->data<='9')
     {
       q=p; p=p->next;
       q->next=hb->next;
       hb->next=q;
     }
     else
     {
       q=p; p=p->next;
       q->next=hc->next;
       hc->next=q;
     }
    }
 }

//�㷨2.13
//ɾ����ͷ��㵥����L��ֵ��ͬ�Ķ���ڵ�(trim) 
//����������ÿһ�������е�Ԫ�أ�������������Ԫ���Ƿ��������
//�����ȣ���ɾ����Ԫ�ء� 
 void Trim_L(LinkList L)
{  
  LinkList p,q,s;
  p=L->next;
  while(p->next&&p->next->next)  
   {
     q=p;
     while(q->next)
      { 
	     if(p->data==q->next->data)
           { //ɾ���ڵ� 
             s=q->next;
             q->next=s->next;
             free(s);
           }
         else  q=q->next; //��p��һ 
      } 
	  p=p->next;
   }
}

//�㷨2.14
//ͳ�ƴ�ͷ��㵥��������ͬ�ڵ����
int CountNode(LinkList head,ElemType x)
{
  int sum=0;
  LinkList p=head->next;
  while(p)
  {  
    if(p->data==x) 
    sum++;
    p=p->next;
  }
  return sum;
}


//�㷨2.15
//��ͷ��㵥����L�����(La��Lb)���ֱ�װ������ż�� 
void RetNode(LinkList L, LinkList &La, LinkList &Lb)
{
   LinkList p,pa,pb;
   p=L->next;
   pa=La=(LNode *)malloc(sizeof(LNode));
   pb=Lb=(LNode *)malloc(sizeof(LNode));
   while(p)
   {
     if(p->data%2) 
     {
       pa->next=p; p=p->next;
       pa=pa->next;
     }
     else 
    {
       pb->next=p; p=p->next;
       pb=pb->next;
     }
    }
    pa->next=NULL;
	pb->next=NULL;
}

 
int main()
 {
 	ElemType la[] = {2,3,1,9,3,6};
    ElemType lb[] = {2,4,5,6,8};
    int m,n;
    //˳���Ĵ��� 
    SqList sqlistA, sqlistB;
    InitList_Sq(sqlistA,100,50);   
    for(m=0;m<5;m++)
  	ListInsert_Sq(sqlistA, m, la[m]);
    
	InitList_Sq(sqlistB,100,50);   
    for(n=0;n<5;n++)
  	ListInsert_Sq(sqlistB, n, la[n]);
   
    //cout<<"����ǰ��sqlistAΪ��";
    //ListTraverse_Sq(sqlistA); 

    
    //����Ĵ��� 
    LinkList linklistA, linklistB,linklistC;
    InitList_L(linklistA);
    InitList_L(linklistB);
    CreateList_L_Rear(linklistA, la, 6);
    CreateList_L_Rear(linklistB, lb, 5);
    
    cout<<"����ǰ��linklistAΪ��";
    ListTraverse_L(linklistA); 
    cout<<"����ǰ��linklistBΪ��";
    ListTraverse_L(linklistB); 
 

    /*****************************/
    //SLOrderInsert(Lista,4);      		//ϰ��2.1����
    //Converse_Sq(Lista);         		 //ϰ��2.2����
    //Exchange_Sq(la,5,5); for(int i=0;i<10;i++) cout<<setw(6)<<la[i];//ϰ��2.3���� 
    //Delete_Section(Lista,2,5);  		 //ϰ��2.4���� 
    //Inverse_L(linklistA);        		//ϰ��2.5����
	//Inverse_L2(linklistA);      		 //ϰ��2.5�ڶ����㷨
    //LinkListSort(linklistA);    		 //ϰ��2.6����
	//NListInsert_L(linklistA,3, 15); 		//ϰ��2.7����
	//NListDelete_L(linklistA,4); 		//ϰ��2.7����
	//NListDelete_L(linklistA,4); 		//ϰ��2.7����
	//Interaction(linklistA,linklistB,linklistC);//ϰ��2.11����
	//Interaction2(linklistA,linklistB,linklistC);//ϰ��2.11�ڶ����㷨 
	//Trim_L(linklistA);//ϰ��2.13����

	/****************************/
    cout<<"�������linklistA��Ϊ��"<<endl;
    //ListTraverse_L(linklistA); 
    ListTraverse_L(linklistA); 
	return 0;
}
