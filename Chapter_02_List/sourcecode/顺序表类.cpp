
typedef int ElemType;             // ˳���������Ԫ��Ϊint
# include "stdlib.h"              // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"      // ���ļ�������׼���������cout��cin�����Ʒ�setw()
class  SeqList {                                   // ˳�����
    private:
       ElemType  *list;                            // �洢���ݵ�ָ��
       int maxsize;                                // ˳�����������
       int length;                                 // ��ǰԪ�صĸ���
     public:
       SeqList(int max=0);                          // ���캯��,���ڳ�ʼ��˳���
       ~ SeqList(void);                             // ��������,�����ͷŷ���Ŀռ�
	   bool ListEmpty(void);                        // �ж�˳����Ƿ�Ϊ��
       int ListLength(void) ;                       // ���
	   void ListTraverse(void);                     // ������Ա�
	   int LocateElem(int i,ElemType e);            // ����Ԫ��
       void  ListInsert(ElemType &item,int i);      // ����Ԫ��
       ElemType  ListDelete(int i);                 // ɾ��Ԫ��
       ElemType  GetElem(int i);                    // ȡ����ĳ��Ԫ��ֵ
     };

  SeqList::SeqList(int max)
   {
      maxsize=max;
      length=0;
      list=new  ElemType[maxsize];
    }
  
  SeqList:: ~SeqList(void)
    {
       delete []list;
    }

 bool SeqList::ListEmpty(void)
 {
	if(length==0)return true;
	else return false;
 }

 int SeqList::ListLength(void)
 {
	 return length;
 }

 void SeqList::ListTraverse(void)
 {
	 if(!ListEmpty()) 
	 for(int i=0;i<length;i++)
  	    cout<<setw(4)<<list[i];
	cout<<endl;
 }

 void SeqList::ListInsert(ElemType &item,int i)
 {
 if(length==maxsize)
  {
    cout<<"˳��������޷����룡"<<endl;
   exit(0);
  }
 if(i<0||i>length)
  { 
   cout<<" ����iԽ�����"<<endl;
   exit(0);
  }
 for(int j=length;j>i;j--)  
  list[j]=list[j-1];
  list[i]=item;
  length++;
}

ElemType SeqList::ListDelete(int i)
 {
 if(length==0)
  {
    cout<<"˳����ѿ��޷�ɾ����"<<endl;
   exit(0);
  }
 if(i<0||i>length-1)
 { 
  cout<<" ����iԽ�����"<<endl;
  exit(0);
 }
ElemType x=list[i];
for(int j=i;j<length-1;j++)  
  list[j]=list[j+1];
length--;
return x; 
}

ElemType SeqList::GetElem(int i)
{
  if(i<0||i>length-1)
 { 
  cout<<" ����iԽ�����"<<endl;
  exit(0);
 }
return list[i];
}

void main()
 {
  SeqList mylist(100);
  int i,a[]={6,8,16,2,34,56,7,10,22,45};
  for(i=0;i<10;i++)
   mylist.ListInsert(a[i],i);          // ����10��Ԫ��
  cout<<"ɾ��ǰ��˳���";
  mylist.ListTraverse();               // ���˳���
  mylist.ListDelete(4);                // ɾ���� 5��Ԫ��
  cout<<"ɾ�����˳���";
  mylist.ListTraverse();               // ���˳���
}
   
