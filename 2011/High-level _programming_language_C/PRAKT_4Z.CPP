#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 30

int array[SIZE];

int main()
{
  time_t t;
  srand(time(&t));
  clrscr();

  for(int i = 0;i < SIZE;i++)
    array[i] = rand() % 100;
  for(i = 0;i < SIZE;i++)
    printf("%d\t",array[i]);
  // SORTING
  int j,left,right;
  int temp;
  float middle;
  int *stackl = new int[SIZE],*stackr = new int[SIZE],sp;
  stackl[1] = 0;
  stackr[1] = SIZE - 1;
  sp = 1;
  while(sp > 0)
  {
    left = stackl[sp];
    right = stackr[sp];
    sp--;
    while(left < right)
    {
      i = left; j = right;
      middle = array[(left + right) / 2];
      while(i < j)
      {
        while(array[i] < middle) i++;
        while(array[j] > middle) j--;
        if (i <= j)
        {
           temp = array[i];
           array[i] = array[j];
	   array[j] = temp;
           i++;j--;
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
  printf("============SORTED==============\n");
  for (i = 0;i < SIZE;i++)
    printf("%d\t",array[i]);
  return 0;
}