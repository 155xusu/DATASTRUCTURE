
# include "stdio.h"
 # define LIST_INIT_SIZE  100
 typedef int ElemType;
typedef struct
{ ElemType  elem [LIST_INIT_SIZE];            //�洢����Ԫ�ص�һά����
  int length;                                   //���Ա�ĵ�ǰ����
} SqList;

int LocateElem_Sq( SqList L, ElemType e)
{  int i;
   for(i=0;i<L.length;i++)
    if(L.elem[i]==e)  return i;   // �ҵ������ж�������Ԫ��Ϊ�� i ��Ԫ��
      return -1;                  // �����Ա��в����������ж�������Ԫ��
 }

 void main()
 {   int i;
   SqList L={{7,6,8 ,9,12,34,9,5},8} ;
   i=LocateElem_Sq( L,4);
  printf("i=%d",i);
  getchar();
  }
