3. Given an unsorted array of positive integers, design an algorithm and implement it using a program to find whether there are any duplicate elements in the array or not.
Source code :-
#include <iostream>

using namespace std;
void readArr(int a[],int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }
}
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
void mergeSort(int arr[],int l,int h)
{
    if(l==h)
        return;
    else
    {
        int mid=(l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,f=0;
        cin >> n;
        int a[n];
        readArr(a,n);
        mergeSort(a,0,n-1);
        for(int i=0;i<n;i++)
        {
            if(a[i]==a[i-1])
            {
                f=1;
                cout<<"Yes"<<endl;
                break;
            }
        }
        if(f==0)
            cout<<"No"<<endl;
    }
    return 0;
}
