/*Given an already sorted array of +ve integers disign an algorithm and implement it using program to find wheather the key is present or not also find the number
of comparsion*/
#include <stdio.h>
int bin_search(int a[],int l,int h,int key,int *c)
{
   if(l <=h) 
    {int mid=(l+h)/2;
    (*c)++;
    if(key == a[mid])
    {
        return mid;
    }
    if(key > a[mid])
        return bin_search(a,mid+1,h,key,&(*c));
    else if(key < a[mid])
        return bin_search(a,l,mid-1,key,&(*c));
 }
    return -1;
}
int bin_lsearch(int a[],int l,int h,int key,int *c)
{
    while(l <= h)
    {
        int mid=(l+h)/2;
        (*c)++;
        if(key == a[mid])
        {
            return mid;
        }
        if(key > a[mid])
            l=mid+1;
        else if(key < a[mid])
            h=mid-1;
    }
    return -1;
}
int main()
{
    int n,key,c=0;
    printf("Enter size of array :");
    scanf("%d",&n);
    int a[n];
    printf("Enter elements in array :");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter key to search :");
    scanf("%d",&key);
    int ind=bin_search(a,0,n,key,&c);
    if(ind == -1)
    {
        printf("Key not found \n");
        printf("Total number of compare %d\n",c);
    }
    else
    {
        printf("Key found at index %d\n",ind);
        printf("Total number of compare %d\n",c);
    }
    return 0;
}
