#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
using namespace std;
typedef int ElemType;
#include "SqQueue.h"

void wait_in_line(SqQueue &Q){
    cout<<"�����벡���ţ�";
    ElemType i;
    cin>>i;
    EnQueue_Sq(Q,i);
}

void see_a_doctor(SqQueue &Q){
    ElemType e;
    DeQueue_Sq(Q,e);
    cout<<e<<"�Ų��˾��"<<endl;;
}

void see_queue(SqQueue &Q){
    for(int i=Q.front;i!=Q.rear;i=(i+Q.queuesize+1)%Q.queuesize){
        cout<<setw(5)<<Q.queue[i];
    }
    cout<<endl;
}

void exit_line(SqQueue &Q){
    while(!QueueEmpty_Sq(Q)){
        ElemType e;
        DeQueue_Sq(Q,e);
        cout<<setw(5)<<e;
    }
    cout<<endl;
    exit(0);
}

void get_off_work(){
    exit(0);
}

int main()
{
    SqQueue myqueue;
    InitQueue_Sq(myqueue);
    bool working=true;
    while(working){
        cout<<"\n**********************************************************"<<endl;
        cout<<"*    ��ӭ��������������ѡ�������\n";
        cout<<"*    1���Ŷ�"<<endl;
        cout<<"*    2������"<<endl;
        cout<<"*    3���鿴�Ŷ�"<<endl;
        cout<<"*    4�������Ŷ�"<<endl;
        cout<<"*    5���°�"<<endl;
        cout<<"*    ��ѡ�����Ĳ�����"<<endl;
        int iOperator;
        cin>>iOperator;
        switch(iOperator){
            case 1:wait_in_line(myqueue);break;
            case 2:see_a_doctor(myqueue);break;
            case 3:see_queue(myqueue);break;
            case 4:exit_line(myqueue);break;
            case 5:get_off_work();break;
            default:cout<<"����";break;
        }
    }
    return 0;
}
