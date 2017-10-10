typedef int ElemType;     
# include "stdlib.h"     
# include "iomanip.h"    
# include "DSqString"   
# include "SLinkString"



//ϰ��4.1��˳��S1�е�����ֵΪch1���ַ�����ch2���ַ���ch1��ch2��Ϊ�ַ��ͣ� 

void Trans_Sq(DSqString &S,char ch1,char ch2)
{
  int i;
  for(i=0;i<S.length;i++)
    if(S.str[i]==ch1)
    S.str[i]=ch2;
}

//ϰ��4.2��˳��ɾ����ֵΪch�������ַ�
void Delall_Sq(DSqString &S,char ch)
{
  int i=0,j=0,k;
  k=S.length;
  while(i<k)
  {
    if(S.str[i]==ch) 
         for(j=i;j<k;j++)
           {
                  S.str[j]=S.str[j++];
            }
    i++;
  }
  S.length=j;
}

��

void Delall_Sq(DSqString &S,char ch)
{
  int i=0,j=0,k;
  k=S.length;
  while(i<k)
  {
    if(S.str[i]!=ch) 
         S.str[j++]=S.str[i];
    i++;
  }
  S.length=j;
}
 
 
//ϰ��4.3����������ͬ������
void Delall_L(SLinkString &S,char ch)
{
  SLinkString p,q;
  p=S;
  while(p->next)
  {
    if(p->next->str==ch)
	{
		 q=p->next;
	     p->next=q->next;
	     free(q);
	    }
	    else p=p->next;
  }
}
 

//ϰ��4.4��S��һ���������ĵ�ֵ�Ӵ� ���Ӵ��и����ַ�����ͬ�ҳ��ȴ���1�� 

bool Equalsubstr(DSqString S,DSqString &sub)
{
   int i=0,j,k,head,max,count;
   head=0;                   //headָ��ǰ���ֵ����ֵ�Ӵ��Ĵ�ͷ
   max=1;                    //max��¼�Ӵ��ĳ���
   for(i=0,j=1; i<S.length&&j<S.length; i=j, j++)
   {
	    count=1;
	    while(S.str[i]==S.str[j]) // ͳ�Ƶ�ǰ��ֵ�Ӵ��ĳ���
	    {
		   j++;
		   count++;
	    }
	    if(count>max)              //�����µ����ֵ�Ӵ�������head��max
	    {
		   head=i;
		   max=count;
	    }
   }
   if(max>1)         //����õ���Ӵ�����sub
   {
	   if(!(sub.str=(char *)malloc(i*sizeof(char))))  // ����sub����ռ� 
			return false;                
	   for(k=0;k<max;k++)
		   sub.str[k]=S.str[k+head];
	   sub.length=max;
	   return true;
   }
   else return false;
}



//ϰ��4.5 ˳���е�i���ַ�����j���ַ�֮����ַ���˳��T���� 

bool Replacestr_Sq(DSqString &S,int i,int j,DSqString T)
{
   int k,disc;  //disk��ʾ��i��j�ĳ���
   
   if(i<0||i>S.length||j<0||j>S.length||i==j)  return false;
   
   disc=j-i-1;
   if(T.length<disc)//���T����disc
     {
         for(k=j;k<S.length;k++)
	   S.str[k-disc+T.length] = S.str[k]; //j�����Ԫ������ǰ��
      }
   else  if(T.length>disc)//���T����disc
	      {
    if(!(S.str=(char )realloc(S.str,(S.length+T.length-disc)*sizeof(char))))
			    return false;       
             for(k=S.length-1;k>=j;k--)
	          S.str[k+T.length-disc]=S.str[k]; //k�����Ԫ���������
		  }

    for(k=0;k<T.length;k++)
	   S.str[i+k+1]=T.str[k];//T���롣
	S.length=S.length+T.length-disc;
    return true;
}


//ϰ��4.6 �����������⡣

bool Replacestr_L(SLinkString &S,int i,int j,SLinkString T)
{
   int k;
   SLinkString p,q,r,h;
   if(i<0||j<0||i==j)  return false;
   q=p=S;
   k=0;                        
   while(p->next&&k<i)          // Ѱ�ҵ�i����� 
   { 
   p=p->next; 
	    k++; 
   }   
   if(k!=i)   return false;  
   k=0;
   while(q->next&&k<j)         // Ѱ�ҵ�j����� 
   { 
	    q=q->next; 
	    k++; 
   }  
   if(k!=j)   return false;  
  
   r=T->next;
   while(r->next)             // rָ��T�ı�β
     r=r->next;
   h=p->next;
   p->next=T->next;           // ɾ����i����j�����,�����봮T 
   free(T);
   r->next=q;
   while(h!=q&&h->next!=q)    // �ͷſռ�
   {
	     r=h;
      h=h->next;
      free(r);  
   }
   return true;
}



//4.7ͨ����� ˳��
bool pattern_index(DSqString S,DSqString T,int &pos)
{  
   int i=0,j=0;                       // i��j�ֱ�ɨ������S���Ӵ�T
   while(i<S.length&&j<T.length)      
   { 

if(S.str[i]==T.str[j]||T.str[j]=='?')// ��Ӧ�ַ���ͬ�������Ƚ���һ���ַ�
    { i++;    j++;}

    else                           // ����ָ��������¿�ʼ��һ��ƥ��
    { i=i-j+1;
      j=0;
    }
   }
   if(j==T.length)  { pos=i-T.length; return true;  }
   else return false;
}// Index_Sq

4.14 ˳�����Ӵ�S��ɾ��

//4.13
void Creat(LinkList &head )
{
  SqQueue Q[10];
  LinkList p,q;
  int i,j,n,a,x;
  for(i=0;i<10;i++)
	 InitQueue_Sq(Q[i]);
  cout<<"���������ݵĸ�����";
  cin>>n;
  cout<<"������"<<n<<"��10���ڵ�������";
  for(i=0;i<n;i++)
  {
	  cin>>a;
    for(j=0;j<10;j++)
	  if(a==j) EnQueue_Sq(Q[j],a);
  }
  head=(LinkList)malloc(sizeof(LNode));    
  q=head;   
  for(i=0;i<10;i++)
    while(!QueueEmpty_Sq(Q[i]))
	   {
       DeQueue_Sq(Q[i],x);
       p=(LinkList)malloc(sizeof(LNode)); 
       p->data=x;  
       q->next=p;  
       q=p;     
} 
  q->next=NULL; 
}

void Print(LinkList head)
{
 LinkList p=head->next;
 while(p)
  {  cout<<setw(6)<<p->data;
     p=p->next;
  }
cout<<endl;
}



void main()
{ int num,dec;              // num���ʮ��������dec��Ž���
  cout<<"����һ��ʮ��������";
  cin>>num;
  cout<<"����Ҫת���Ľ��ƣ�";
cin>>dec;  
cout<<"ת�����"<<dec<<"������Ϊ��"; 
  TransFrom(num,dec);                 // ��������ת������
}	