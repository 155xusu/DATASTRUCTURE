typedef int ElemType;   
# include "stdlib.h"
# include "iostream.h"
# include "iomanip.h"
# include "SqList.h"

void main()
 {
 SqList mylist;
  int i,x,k,j;
  InitList_Sq(mylist, 50,10);
  for(i=0;i<10;i++)
  if(!ListInsert_Sq(mylist, i, i+1))
     {
       cout<<"����!"<<endl;
       return;
     }
     k=ListLength_Sq(mylist);
     cout<<"��Ϊ��"<<k<<endl;
	 j=LocateElem_Sq(mylist, 6);
	 if(j!=-1) cout<<"���ҵ�Ԫ��Ϊ��"<<mylist.elem[j]<<endl;
	 cout<<"Ԫ�ز�����."<<endl;
	 if(GetElem_Sq(mylist,15,x))  cout<<"��5��Ԫ����:"<<x<<endl;
	  else cout<<"����"<<endl;
	if(!ListDelete_Sq(mylist,4, x))
    {
      cout<<"����!"<<endl;
       return;
     }
	cout<<"��ɾ��Ԫ����:"<<x<<endl;
	cout<<"ɾ�����˳���Ϊ��"<<endl;
   ListTraverse_Sq(mylist);
   DestroyList_Sq(mylist);
  }