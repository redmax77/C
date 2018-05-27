#include <conio.h>
#include <iostream.h>
#define N 3
void main(){
int i,j;
float x;
float a[N];
cout <<"\n";
for (i=0; i<N; i++){
cout <<"input a["<<i<<"]=";
cin >>a[i];
}
for (i=N-1; i>0; i--){
x=a[i-1];
j=i;
while (x>a[j] && j<N){
a[j-1]=a[j];
j++;
}
a[j-1]=x;
}
for (i=0; i<N; i++)
cout<<"\n"<<a[i];
getch();
}