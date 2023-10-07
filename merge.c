#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void merge(int l,int mid,int h,int arr[])
{
    int n1=mid-l+1;
    int n2=h-mid;
    int arr1[n1],arr2[n2];
    for(int i=0;i<n1;i++)
    {
        arr1[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        arr2[i]=arr[mid+1+i];
    }
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(arr1[i]<=arr2[j])
        {
            arr[k++]=arr1[i++];
        }
        else
        {
            arr[k++]=arr2[j++];
        }
    }
    while(i<n1)
    {
        arr[k++]=arr1[i++];
    }
    while(j<n2)
    {
        arr[k++]=arr2[j++];
    }

}
void mergesort(int l,int arr[],int h)
{
   // int mid;
    if(l<h)
    {
        int mid=(l+h)/2;

// #pragma omp parallel sections
//     {
//         #pragma omp section
//         mergesort(l,arr,mid);

//         #pragma omp section
//         mergesort(mid+1,arr,h);
//     }
    #pragma omp parallel sections
        {
            #pragma omp section
            mergesort(l,arr,mid);
            
            #pragma omp section
            mergesort(mid+1,arr,h);
        }
     merge(l,mid,h,arr);
    }
   
}
void main()
{
    int arr[]={1,2,7,3};

    mergesort(0,arr,3);

    for(int i=0;i<4;i++)
    {
        printf("%d",arr[i]);
    }
}