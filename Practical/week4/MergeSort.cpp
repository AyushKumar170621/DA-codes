#include <iostream>

using namespace std;
int merge(int arr[], int l, int m, int h,int *cmp)
{
    int n1=m-l+1,n2=h-m,inv=0;
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
        (*cmp)++;
        if(a1[i] < a2[j])
        {
            arr[k]=a1[i];
            i++;
        }
        else
        {
            inv += n1 - i;
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
    return inv;
}
int mergesort(int arr[],int l,int h,int *cmp)
{
    int inv=0;
    if(l < h)
    {
        int mid=(l+h)/2;
        inv+=mergesort(arr,l,mid,&(*cmp));
        inv+=mergesort(arr,mid+1,h,&(*cmp));
        inv+=merge(arr,l,mid,h,&(*cmp));
    }
    return inv;
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
        int n,inver,cmp=0;
        cin>>n;
        int arr[n];
        readArr(arr,n);
        inver=mergesort(arr,0,n-1,&cmp);
        printArr(arr,n);
        cout<<"Inversion :- "<<inver<<endl;
        cout<<"Comparison :- "<<cmp<<endl;
    }
    return 0;
}
