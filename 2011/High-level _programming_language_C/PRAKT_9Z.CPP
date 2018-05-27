#include <stdio.h>
#include <stdlib.h>

#define n 3

float det(float c[n][n]);

int main()
{
	float b[n][n],d[n][n],f[n];
        int k,i,j;
        float de,der[n];
        printf("Vvesti matrizu 3 x 3\n");
        for(i = 0;i < n;i++)
          for(j = 0;j < n;j++)
          scanf("%f",&b[i][j]);
        for(j = 0;j < n;j++)
          scanf("%f",&f[j]);
        for(i = 0;i < n;i++)
        {
          for(j = 0;j < n;j++)
          printf("%f",b[i][j]);
          printf("\n");
        }

        for(i = 0;i < n;i++)
        for(j = 0;j < n;j++)
          d[i][j] = b[i][j];

        de = det(b);
        printf("Det = %f\n",de);
        for (k = 0;k < n;k++)
        {
		for(i = 0;i < n;i++)
                for(j = 0;j < n;j++)
	                d[i][j] = b[i][j];
                for(i = 0;i < n;i++)
                d[k][i] = f[i];
                der[k] = det(d) / de;
                printf("X %d %f",k,der[k]);
        }
        system("pause");
        return 0;
}

float det(float c[n][n])
{
	int i,j;
	const int m = 2 * n -1;
        float p,s;
        float a[n][m];
        for (i = 0;i < n;i++)
          for(j = 0;j < n;j++)
            a[i][j] = c[i][j];

        for(i = 0;i < n;i++)
        for(j = 0;j < n -1;j++)
          a[i][j + n] = a[i][j];

        s = 0;
        for(i = 0;i < n;i++)
        {
        	p = 1;
                for(j = 0;j < n;j++)
                p *= a[j][n - 1 - j + i];
                s -= p;
	}
        return s;
}
