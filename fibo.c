#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int findfin(int n)
{
    int a,b;
    if(n==1){
        return 0;
    }
    if(n==2 || n==3)
    {
        return 1;
    }
    else
    {
        #pragma omp task shared(a)
         a=findfin(n-1);
        #pragma omp task shared(b)
        b=findfin(n-2);
        
        return a+b;
    }
    
}
int main()
{
    int n=10;

    for(int i=1;i<=n;i++)
    {
        printf("%d",findfin(i));
    }

    return 0;
}