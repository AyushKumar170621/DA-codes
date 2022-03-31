#include <iostream>

using namespace std;
void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int partition(int arr[],int l,int h)
{
    int x=arr[l];
    int i=l;
    for(int j=l+1;j<= h;j++)
    {
        if(arr[j] <= x)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
 
    swap(arr[l],arr[i]);
    return i;
}
void quicksort(int arr[],int l,int h)
{
    if(l  < h)
    
    {
        int par=partition(arr,l,h);
        quicksort(arr,l,par-1);
        quicksort(arr,par+1,h);
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
    int n;
    cout<<"Enter Size of array:";
    cin>>n;
    int arr[n];
    readArr(arr,n);
    printArr(arr,n);
    quicksort(arr,0,n-1);
    printArr(arr,n);
    return 0;
}
