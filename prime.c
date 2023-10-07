#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
int findprime(int n)
{
    if(n==1 || n==0)
    {
        return 0;
    }
    
    {
        for(int i=2;i<n/2;i++)
        {
            if(n%i==0)
            {
                return 0;
            }
        }
    }
    return 1;
}
void main()
{
    int n;
    scanf("%d",&n);
    double time=omp_get_wtime();
//#pragma omp prallel for
 for(int i=0;i<n;i++)
    {
        if(findprime(i))
        {
            printf("1000");
        }
    }
    // double ftime=omp_get_wtime();
    
    //  printf("%lf",ftime-time);
}