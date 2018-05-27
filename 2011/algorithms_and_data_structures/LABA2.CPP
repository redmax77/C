#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream.h>
#define N 16
#define M 4
void main(){
int i,result,l,r,k,s;
float x;
float a[N]={10,12,18,19,21,25,29,33,38,42,47,50,57,62,65,71};
float kind[M]={10,21,38,57};
float pind[M]={0,4,8,12};
printf("Vvedite argument x\n");
scanf("%f",&x);
i=0;
k=0;
s=0;
while (i<M && x>=kind[i])
{
i++;
k++;
}
if (i<M) k++;
if (i==0) l=0;
else l=pind[i-1];
if (i==M) r=N;
else r=pind[i];
while (l<r && x!=a[l])
{
l++;
k++;
}
if (l==r) result=-1;
else
{
k++;
result=l;
}
printf("\n");
printf("res=  %i\n",result);
printf("obrasheniya=  %i\n",k);
printf("\n");
printf("\n");
getch();
}
