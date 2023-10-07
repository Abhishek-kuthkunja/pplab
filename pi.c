#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

void main()
{
    float pi=0;

    int num_steps=10000;

    for(int i=0;i<num_steps;i++)
    {
        pi+=pow(-1,i)/(2*i+1);
    }
    pi=4*pi;
    printf("%f\n",pi);

    pi=0;
    float thred[9];
    #pragma omp parallel for num_threads(8)
    for(int i=0;i<num_steps;i++)
    {
        int a=omp_get_thread_num();
        thred[a]+=pow(-1,i)/(2*i+1);
    }
    for(int i=1;i<=8;i++)
    {
         //printf("%f",thred[i]);
        pi+=thred[i];
    }
    
    pi=4*pi;
    printf("%f",pi);


}