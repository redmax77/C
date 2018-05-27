#include <conio.h>
#include <iostream>
#define N 3
using namespace std;
main(){
struct List
{int data;
struct List *next;
};
struct List *top,*bottom,*q,*p;
int i;

//clrscr();
bottom=NULL;
top=NULL;
for(i=0; i<N; i++){
         q=new List;
         cin>> q->data;
         if (bottom!=NULL){
                           q->next=bottom->next;
                           bottom->next=q;
                           bottom=q;
                           }
         else {
              top=q;
              bottom=q;
              q->next=q;
              }
}
///vivod
q=top;
do
{
       cout<<q->data<<" ";
       q=q->next;
       }
while (q!=top);
cout<<"\n";
///ydalenie
q=top;
if(top!=NULL){
              top=top->next;
              delete q;
              }
q=bottom;
q->next=top;
///dobavlenie
q=new List;
cin>> q->data;
if (bottom!=NULL){
                  q->next=bottom->next;
                  bottom->next=q;
                  }
else q->next=q;
///vivod
q=top;
do
{
       cout<<q->data<<" ";
       q=q->next;
       }
while (q!=top);
getch();
}
