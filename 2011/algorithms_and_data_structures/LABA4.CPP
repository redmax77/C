#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#define N 4
void main(){
struct List
{int data;
struct List *next;
};
struct List *root,*q,*p;
int i;
clrscr();
root=NULL;
for(i=0;i<N;i++){
q=new List;
q->next=root;
cin >> q->data;
root=q;
}
q=root;
for(i=N-1;i>=0;i--){
  q=root;
  for (j=0;j<i;j++)
    q=q->next;
  cout<< q->data;
}
getch();
}  

