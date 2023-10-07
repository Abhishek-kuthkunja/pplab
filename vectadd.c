#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void main()
{
    int vect1[100],vect2[100],vect3[100];

    for(int i=0;i<100;i++)
    {
        vect1[i]=rand()%10;
        vect2[i]=rand()%10;
    }
    double start=omp_get_wtime();
    #pragma omp parallel for
    for(int i=0;i<100;i++)
    {
        vect3[i]=vect1[i]+vect2[i];
    }
    double end=omp_get_wtime();
    printf("%d",end-start);
}