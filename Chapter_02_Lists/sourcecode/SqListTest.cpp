typedef int ElemType;      // ˳�����Ԫ������Ϊint
#include "stdlib.h"       // ���ļ�����malloc()��realloc()��free()�Ⱥ���
#include "iomanip.h"      // ���ļ�������׼���������cout��cin�����Ʒ�setw()
#include "SqList.h"       // ���ļ��а���˳������ݶ������������ز���


   
//�㷨2.1:�ϲ�����˳���B����A���棬�����ظ�Ԫ�� 

void Union(SqList &lista, SqList listb)
	{  
	   ElemType e;
	   lista.length = ListLength_Sq(lista);
	    //cout<<"a���Ա�ĳ���Ϊ"<<lista.length<<endl;
   	    //cout<<"a���Ա�Ĵ�СΪ"<<lista.listsize<<endl;
   	    //cout<<"b���Ա�ĳ���Ϊ"<<listb.length<<endl;
   	    //cout<<"b���Ա�Ĵ�СΪ"<<listb.listsize<<endl;
	   while(!ListEmpty_Sq(listb))
	   {
	   	 ListDelete_Sq(listb,0,e);
	   	 //ListTraverse_Sq(listb);  
	   	 if(LocateElem_Sq(lista,e)==-1){
	   	 ListInsert_Sq(lista,lista.length, e);
			}
	   }
	   DestroyList_Sq(listb);
   	}


//�㷨2.1����һ��ʵ�� 
void Union2(SqList &lista, SqList listb)
	{  ElemType e;
	   lista.length = ListLength_Sq(lista);
	   listb.length = ListLength_Sq(listb);
	   for(int i=0;i <= listb.length;i++)
	   {
	   	    GetElem_Sq(listb, i, e);
	   	    if(LocateElem_Sq(lista, e)== -1)
	   	       ListInsert_Sq(lista,  lista.length, e);
	   }
	    DestroyList_Sq(listb);
   } //union
 

//�㷨2.2��Purge,������ͬԪ�� 
void Purge(SqList &La, SqList Lb)//�������Ա�La��ʹ����ֻ����Lb������ֵ����ͬ�� 
	{  ElemType e;
	   InitList_Sq(La,100,50); 
	  while(!ListEmpty_Sq(Lb))
	   {
	   	 ListDelete_Sq(Lb,0,e);
	   	 if(LocateElem_Sq(La,e)==-1)
	   	 ListInsert_Sq(La,La.length,e);
	   }
	 
	    DestroyList_Sq(Lb);
   } 
 
 //�㷨2.3 ���ж���������A,B�Ƿ����
 bool isequal(SqList &La, SqList Lb) 
 {
 	//�����Ա�La��Lb����������ȣ�����������Ԫ��Ҳ��ͬ���򷵻�true
    //���򷵻�false 
    SqList Lc;
    ElemType e;
    bool found;
    La.length = ListLength_Sq(La);
    Lb.length = ListLength_Sq(Lb);
    if(La.length!=Lb.length)return false;
    else
    {
    	InitList_Sq(Lc);
    	for(int j=0;j<=La.length-1;j++)
    	{
    		 GetElem_Sq(La,j,e);
    		 ListInsert_Sq(Lc,j,e);
    	}
    	
		found = true;
    	//ListTraverse_Sq(Lc); 
		for(int k=0;k<=Lb.length-1;k++)
    	{    int i=-1;
    		 GetElem_Sq(Lb,k,e);
    		 i = LocateElem_Sq(Lc,e);
    		 if(i==-1) found = false;
    		 else ListDelete_Sq(Lc,i,e);
    	}
    	ListTraverse_Sq(Lc); 
    	if(found&&ListEmpty_Sq(Lc))return true;
    	else return false;
    	DestroyList_Sq(Lc);
    }
 }
 
//��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ����У������
//�鲢La��Lb�õ��µ����Ա�Lc,Lc������Ԫ��Ҳ��ֵ�ǵݼ�����
void MergeList(SqList La, SqList Lb, SqList &Lc)
{
   InitList_Sq(Lc);
   int i=1; int j=1; int k=0;
   int ai,bj;
   La.length = ListLength_Sq(La);
   Lb.length = ListLength_Sq(Lb);
   while((i<=La.length)&&(j<=Lb.length))//La,Lb���ǿ�
   {
   	 GetElem_Sq(La,i,ai);GetElem_Sq(Lb,j,bj);
	 if(ai<=bj) {ListInsert_Sq(Lc, ++k, ai);++i;}
	 else{ListInsert_Sq(Lc, ++k, bj); ++j;}
   }     

   while(i<=La.length)//b��a���� 
   {
   	  GetElem_Sq(La,i++,ai); ListInsert_Sq(Lc, ++k, ai);
   }
   
   while(j<=Lb.length)//a��b���� 
   {
      GetElem_Sq(Lb,j++,bj);ListInsert_Sq(Lc, ++k, bj);	
   }
}
   

int main()
 {
 	//��˳�����ɾ����i��Ԫ�ص����� 
 	/*
 	SqList mylist;
  	int i,x,a[]={6,8,16,2,34,56,7,10,22,45};
  	InitList_Sq(mylist, 50,10);           // ��ʼ��˳���mylist
  	for(i=0;i<10;i++)
  	if(!ListInsert_Sq(mylist, i, a[i]))  // ��a[i]���뵽˳����е�i+1��Ԫ��֮ǰ
     { 
	 	cout<<"����ʧ�ܣ�"<<endl;
        return 0;
     }
	cout<<"ɾ��ǰ��˳���Ϊ��";
  	ListTraverse_Sq(mylist);           // ���ñ���������ʾmylist
	if(!ListDelete_Sq(mylist,4, x))     // ɾ��˳����е�5��Ԫ��
    {  cout<<"ɾ��ʧ�ܣ�"<<endl;
       return 0;
     }
	cout<<"��ɾ��Ԫ���ǣ�"<<x<<endl;
	cout<<"ɾ�����˳���Ϊ��";
   ListTraverse_Sq(mylist);           // ���ñ���������ʾmylist
   DestroyList_Sq(mylist);            // ���ó�����������mylist���ͷſռ�
   return 0;
   
  */
  
  
  
  
    //�㷨��ʹ��: 
    SqList Lista, Listb;
    int m,n;
    
    ElemType la[] = {1,2,3,5,6};
   // ElemType lb[] = {7,0,4,9,6};
    ElemType lb[] = {4,1,2,3,6};
    InitList_Sq(Lista,100,50);   
    InitList_Sq(Listb,100,50);  
    for(m=0;m<5;m++)
  	if(!ListInsert_Sq(Lista, m, la[m]))  // ��la[i]���β���˳���Lista 
     { 
	 	cout<<"����ʧ�ܣ�"<<endl;
        return 0;
     }
          
	for(n=0;n<5;n++)
	if(!ListInsert_Sq(Listb, n, lb[n]))// ��lb[i]���β���˳���Listb
     { 
	 	cout<<"����ʧ�ܣ�"<<endl;
        return 0;
     }
     
    cout<<"����ǰ��SqLista��Ϊ��";
    ListTraverse_Sq(Lista); 
    cout<<"����ǰ��SqListb��Ϊ��";
    ListTraverse_Sq(Listb);  
     
    /*****************************/
    //Union(Lista,Listb);//�㷨2.1 
    //Union2(Lista,Listb);//�㷨2.1+ 
    //Purge(Lista,Listb);//�㷨2.2 
    //bool a = isequal(Lista,Listb);//�㷨2.3
	/****************************/
    
    cout<<"�������SqLista��Ϊ��";

	ListTraverse_Sq(Lista);  
    DestroyList_Sq(Lista);   
    
	return 0;
}
   
   


