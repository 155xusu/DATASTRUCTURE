typedef int ElemType;       // ��������Ԫ������Ϊint
# include "stdlib.h"        // ���ļ�����malloc()��realloc()��free()�Ⱥ���
# include "iomanip.h"        // ���ļ�������׼���������cout��cin�����Ʒ�setw()
# include "LinkList.h"      // ���ļ��а������������ݶ������������ز���

int  main()
     {
      LinkList head;
      int i,x,k,a[]={6,8,16,2,34,56,7,10,22,45};



///////�㷨2.12
      InitList_L(head);                       // ��ʼ��������
      for(i=1;i<=9;i++)
        if(!ListInsert_L(head,i,a[i-1]))     // ��a[i]���뵽�������е�i��Ԫ��֮ǰ
        { cout<<"����ʧ�ܣ�"<<endl;
          return 0;
        }
      

///////�㷨2.13
	cout<<endl<<endl<<"������Ϊ��" <<ListLength_L(head)<<endl;
	cout<<"������ʾ��"<<endl;
	ListTraverse_L(head); 



///////�㷨2.14
    cout<<endl<<endl<<"Ԫ��10����λ��Ϊ��";
    LNode *p2 = LocateElem_L(head,10);
	cout<<p2->next<<endl;
	



///////�㷨2.15
    cout<<endl<<endl<<"�����ڵ�����Ԫ��16֮ǰ����Ԫ��15"<<endl;
    ListInsert_L(head,3,15);
    cout<<"�����ĵ�����Ϊ��"<<endl; 
	ListTraverse_L(head); 
    cout<<"�����ĵ�������Ϊ"<<ListLength_L(head)<<endl; 


///////�㷨2.16
	cout<<endl<<endl<<"����ɾ���ڰ˸�Ԫ��"<<endl;
      if(!ListDelete_L(head,8,x))                
       { cout<<"ɾ��ʧ�ܣ�"<<endl;
       }
    cout<<"��ɾ��Ԫ���ǣ�"<<x<<endl;
    cout<<"ɾ����ĵ�������ʾ��"<<endl;
      ListTraverse_L(head);
      

///////�㷨2.17
    cout<<endl<<endl<<"��ʱ�����Ԫ���ǣ�";
 	if(GetElem_L(head,5,x)) 
	     cout<<x<<endl;
 	else cout<<"Ԫ�ز�����"<<endl;
  DestroyList_L(head);


///////�㷨2.18  
      LinkList head2;
      int b[]={10,20,30,40,50};
      InitList_L(head2);      
	  CreateList_L_Front(head2,b,5);
      cout<<"���ڽ����ڶ�������ͷ�壩";
      ListTraverse_L(head2);
      DestroyList_L(head2);


///////�㷨2.19
      LinkList head3;
      int c[]={10,20,30,40,50};
      InitList_L(head3);      
	  CreateList_L_Rear(head3,c,5);
      cout<<"���ڽ�������������β�壩";
      
///////�㷨2.20
      ListTraverse_L(head3);
      
///////�㷨2.21
      DestroyList_L(head3);    
    

 
}
