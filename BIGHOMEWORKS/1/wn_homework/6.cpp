#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <iostream>
using namespace std;
typedef struct{
    short x;
    short y;
}ElemType;
#include "SqStack.h"

void TraveseMap(int map[][10]){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            if(map[i][j]==0){
                cout<<"##";
            }else if(map[i][j]==1){
                cout<<"  ";
            }else if(map[i][j]==4){
                cout<<"  ";
            }else if(map[i][j]==3){
                cout<<"��";
            }
        }
        cout<<endl;
    }

}

int look_around(int map[][10],ElemType &e){
    //����0��ʾ��·���ߣ�1��ʾ�ҵ�·
    if(map[e.x-1][e.y]==1){
        e.x=e.x-1;
        return 1;
    }else if(map[e.x+1][e.y]==1){
        e.x=e.x+1;
        return 1;
    }else if(map[e.x][e.y-1]==1){
        e.y=e.y-1;
        return 1;
    }else if(map[e.x][e.y+1]==1){
        e.y=e.y+1;
        return 1;
    }else {
        return 0;
    }

}

void findroad(int map[][10],ElemType start,ElemType end){
    SqStack mystack;
    InitStack_Sq(mystack);
    ElemType temp=start;
    map[start.x][start.y]=3;
    Push_Sq(mystack,temp);
    int counts=1;
    while(true){
        //cout<<counts++<<endl;
        int result=look_around(map,temp);
        if(result==1){
            if(temp.x==end.x&&temp.y==end.y){
                Push_Sq(mystack,end);
                break;
            }
            map[temp.x][temp.y]=3;
            Push_Sq(mystack,temp);
        }else if(result==0){
            Pop_Sq(mystack,temp);
            GetTop_Sq(mystack,temp);
        }
        TraveseMap(map);
    }

    while(!StackEmpty_Sq(mystack)){
        Pop_Sq(mystack,temp);
        map[temp.x][temp.y]=4;
    }
}


int main()
{
    int Map[10][10] =
{  {0,0,0,0,0,0,0,0,0,0}, //0��
   {0,1,1,0,1,1,1,0,1,0}, //1��
   {0,1,1,0,1,1,1,0,1,0}, //2��
   {0,1,1,1,1,0,0,1,1,0}, //3��
   {0,1,0,0,0,1,1,1,1,0}, //4��
   {0,1,1,1,0,1,1,1,1,0}, //5��
   {0,1,0,1,1,1,0,1,1,0}, //6��
   {0,1,0,0,0,1,0,0,1,0}, //7��
   {0,0,1,1,1,1,1,1,1,0}, //8��
   {0,0,0,0,0,0,0,0,0,0}  //9 ��
};
    ElemType start={1,1};
    ElemType end={8,8};
    //SqStack mystack;
    //InitStack_Sq(mystack);
    //Push_Sq(mystack,start);

    findroad(Map,start,end);
    TraveseMap(Map);
    return 0;
}
