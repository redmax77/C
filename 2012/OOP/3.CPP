#include <iostream>
#include <conio.h>
#include <math.h>
class DOP;
class GEOM{
 private:
 double x;
 public:
 double res;
 GEOM(double i){
				  x=i;
				  }
 void calc(){
  res=pow(x,1.0/3);
  }
 friend void calc_sum(DOP obj);
 };

class DOP{
 private:
 double x,y;
 public:
 double res;
 DOP(double i, double j){
 x=i;
 y=j;
 }
 void calc(){
  res=(pow(x,1.0/3))/y;
  }
 friend void calc_sum(DOP obj);
 };

int main(){
//clrscr();
GEOM Pony(27);
DOP Cube(27,2);
Pony.calc();
Cube.calc();
std::cout <<"\n calc ="<<Pony.res;
std::cout <<"\n calc / 2 ="<<Cube.res;
getch();
}

