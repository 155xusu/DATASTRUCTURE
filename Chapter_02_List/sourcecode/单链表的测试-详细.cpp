# include "stdlib.h"
# include "iostream.h"
# include "iomanip.h"
typedef  int ElemType;
# include "LinkList.h"
  void  main()
     {
      LinkList head;
      int i,x,k,a[]={10,20,30,40,50,60,70,80,90,100};
      InitList_L(head);   //��ʼ��
       
        CreateList_L_Front(head,a,10 );          //��������
		k=ListLength_L(head);
		cout<<"��="<<k<<endl;
		if(GetElem_L(head,12,x)) 
	     cout<<"x="<<x<<endl;
		else cout<<"Ԫ�ز�����"<<endl;
      if(!ListDelete_L(head,4,x))
     {
       cout<<"����!"<<endl;
       return;
     }
	  	k=ListLength_L(head);
		cout<<"k="<<k<<endl;
	cout<<"��ɾ��Ԫ����:"<<x<<endl;
	cout<<"ɾ����ĵ�����Ϊ��"<<endl;
    ListTraverse_L(head);
    DestroyList_L(head);
  }
