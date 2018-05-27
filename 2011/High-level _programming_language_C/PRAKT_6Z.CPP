//POISK LOKALNYH EKSTREMUMOV
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COLS 10
#define NUM_ROWS 10

float array[NUM_ROWS][NUM_COLS];

extern void generate_matrix();
extern void print_matrix();
extern int find_loc_extr();

int main()
{
  int loc_extr;
  clrscr();
  generate_matrix();
  print_matrix();
  getch();
  loc_extr = find_loc_extr();
  printf("localnyh extremumov = %d",loc_extr);
  getch();
  return 0;
}

void generate_matrix()
{
  time_t t;
  srand(time(&t));
  for (int i = 0;i < NUM_ROWS;i++)
    for(int j = 0;j < NUM_COLS;j++)
      array[i][j] = rand() % 100;
}

void print_matrix()
{
  for(int i = 0;i < NUM_ROWS;i++)
  {
    printf("\n");
    for(int j = 0;j < NUM_COLS;j++)
      printf("%.2f\t",array[i][j]);
  }
}

int find_loc_extr()
{
  int k = 0;
  int s = 0;
  for (int i = 1; i < NUM_ROWS;i++)
    for(int j = 1; j < NUM_COLS;j++)
    {
	k = array[i][j];
        if (k < array[i-1][j-1] && k < array[i-1][j] && k < array[i-1][j+1] &&
	    k < array[i][j-1] && k < array[i][j+1] && k < array[i+1][j-1] &&
	    k < array[i+1][j] && k < array[i+1][j+1])
            {
            	s++;
                printf("a[%d][%d]=%f\n",i+1,j+1,array[i][j]);
	    }
    }
  return s;
}