typedef int ElemType;     
#include  "stdlib.h"      
#include  "iomanip.h"     
#include  "LinkList.h"    




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


//����ͷ���ĵ�������̶Ա��е�һֵ��5��ֻ����һ����㣬ɾ������ֵ��ͬ�Ľ�㡣
void  Choice_L(LinkList &L)
{
 ElemType e;
 LinkList p,q;
 p=L;
 int i=0;
 while(p->next)
 { 
   p = p->next;i++;
   if(p->data = 5)
   		{
         q=p->next;                               
		 p->next=q->next;                              
	     e=q->data;    free(q);
   
 }
}



int main()
{
 LinkList linklist,p;
 InitList_L(linklist);
 ElemType a[]={1,2,3,4,5,5,6};
 CreateList_L_Rear(linklist,a,7);
 
 cout<<"֮ǰ��"<<endl;
 ListTraverse_L(linklist);
 p=linklist->next->next;
 
 //Reverse_L(linklist,p);
 Choice_L(linklist);
 
 cout<<"֮��"<<endl;
 ListTraverse_L(linklist);
 
 
 
}

