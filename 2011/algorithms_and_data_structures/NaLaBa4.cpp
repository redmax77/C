#include <conio.h>
#include <iostream.h>
#define N 3
main(){
struct List
{int data;
struct List *next,*prev;
};
struct List *top,*bottom,*q,*p;
int i,x;
x=0;
bottom=NULL;
top=NULL;
//clrscr();
///inichilizachiya
top=new List;
top->next=top;
top->prev=top;
cin>>top->data;
bottom=top;
for(i=0;i<N;i++){
                 q=new List;
                 q->next=bottom->next;
                 q->prev=bottom;
                 cin>>q->data;
                 bottom->next->prev=q;
                 bottom->next=q;
                 bottom=q;
                 }
///modul
q=top;
do
{
       x=q->data;
       x=abs(x);
       q->data=x;
       q=q->next;
       }
while (q!=top);
///vivod
 cout<<"\n";
q=top;
do
{
       cout<<q->data<<" ";
       q=q->next;
       }
while (q!=top);
getch();
}
                 
