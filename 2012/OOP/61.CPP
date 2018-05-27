#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
using namespace std;
//class NOV;
class GEOM
{
public:
double x;
double res;
void print(){
cout<<"\nres = "<<res;}
GEOM(double i){
 x=i;
 }
void calc(){
res=pow(x,1.0/3);
}
GEOM operator--();
};
GEOM GEOM :: operator--(){
 res=res/1000;
 return *this;
 };

int main()
{
system("cls");
GEOM cu(27);
cu.calc();
cu.print();
--cu.res;
cu.print();
--cu;
cu.print();
getch();
return 0;
}
