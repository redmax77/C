#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define N 30

int array[N];
int sorted_array[N];

extern void quick_sort(int array[],int n);
extern void generate_array(int n);

int main()
{
  time_t t;
  clrscr();
  srand(time(&t));
  generate_array(N);
  for(int i = 0;i < N;i++)
     printf("%d\t",array[i]);
  quick_sort(array,N);
  printf("=======Sorted array=========\n");
  for(i = 0;i < N;i++)
     printf("%d\t",array[i]);
  return 0;
}

void quick_sort(int array[],int n)
{
  int* stackl = new int[n];
  int* stackr = new int[n];
  int sp = 0;
  float middle,temp;
  int i,j,left,right;

  sp = 1;
  stackl[1] = 0;
  stackr[1] = n - 1;
  while(sp > 0)
  {
  	left = stackl[sp];
        right = stackr[sp];
        sp--;
        while(left < right)
        {
          i = left;
          j = right;
          middle = array[(left + right) / 2];
          while(i < j)
          {
             while(array[i] < middle) i++;
             while(middle < array[j]) j--;
             if ( i <= j)
             {
             	temp = array[i];
                array[i] = array[j];
                array[j] = temp;
                i++;
                j--;
             }
           }
	  if (i < right)
          {
            sp++;
            stackl[sp] = i;
            stackr[sp] = right;
	  }
          right = j;
        }
  }
}

void generate_array(int n)
{
  for(int i = 0;i < n;i++)
  {
    array[i] = rand() % 100;
  }
}