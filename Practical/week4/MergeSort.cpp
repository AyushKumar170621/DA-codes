#include <iostream>

using namespace std;
void merge(int arr[], int l, int m, int h)
{
    int n1=m-l+1,n2=h-m;
    int a1[n1];
    int a2[n2];
    for(int i=l,j=0;i<=m;i++,j++)
    {
        a1[j]=arr[i];
    }
    for(int i=m+1,j=0;i<=h;i++,j++)
    {
        a2[j]=arr[i];
    }
    int i=0,j=0,k=l;
    while(i < n1 && j < n2)
    {
        if(a1[i] < a2[j])
        {
            arr[k]=a1[i];
            i++;
        }
        else
        {
            arr[k]=a2[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k]=a1[i];
        i++;
        k++;  
    }
    while(j < n2)
    {
        arr[k]=a2[j];
        j++;
        k++;  
    }
}
void mergesort(int arr[],int l,int h)
{
    if(l==h)
        return;
    else
    {
        int mid=(l+h)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,h);
        merge(arr,l,mid,h);
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
    mergesort(arr,0,n-1);
    printArr(arr,n);
    return 0;
}
