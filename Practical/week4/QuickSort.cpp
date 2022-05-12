/*2. Given an unsorted array of integers, design an algorithm and implement it using a program to sort an array of elements by partitioning the array into two subarrays based on a pivot element such that one of the sub array holds values smaller than the pivot element while another sub array holds values greater than the pivot element. Pivot element should be selected randomly from the array. Your program should also find number of comparisons and swaps required for sorting the array.
Source code : -*/
#include <iostream>

using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int partition(int arr[],int l,int h,int *sp,int *cp)
{
    int pivot = arr[h];
    int i = (l - 1); 
    for (int j = l; j <= h - 1; j++)
    {
        (*cp)++;
        if (arr[j] < pivot)
        {
            i++; 
            (*sp)++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    (*sp)++;
    return (i + 1);
    
}
void quicksort(int arr[],int l,int h,int *sp,int *cp)
{
    if(l  < h)
    
    {
        int par=partition(arr,l,h,&(*sp),&(*cp));
        quicksort(arr,l,par-1,&(*sp),&(*cp));
        quicksort(arr,par+1,h,&(*sp),&(*cp));
    }
}
void readArr(int a[],int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }
}
void printArr(int a[],int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,cmp=0,sw=0;
        cout<<"Enter Size of array:";
        cin>>n;
        int arr[n];
        readArr(arr,n);
        quicksort(arr,0,n-1,&sw,&cmp);
        printArr(arr,n);
        cout<<"Comparison :- "<<cmp<<endl;
        cout<<"Swap :- "<<sw<<endl;

    }
    return 0;
}
