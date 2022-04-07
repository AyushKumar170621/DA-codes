/*Given an unsorted array of integers, design an algorithm and implement it using a program to
find whether two elements exist such that their sum is equal to the given key element. (Time
Complexity = O(n log n))*/
#include <iostream>
using namespace std;
#include <vector>
void merge(int arr[],int l,int m,int h)
{
    int n1=m-l+1,n2=h-m;
    int a[n1],b[n2];
    for(int i=l,j=0;i<=m;i++,j++)
        a[j]=arr[i];
    for(int i=m+1,j=0;i<=h;i++,j++)
        b[j]=arr[i];
    int i=0,j=0,k=l;
    while(i<n1 && j < n2)
    {
        if(a[i] < b[j])
        {
            arr[k]=a[i];
            i++;
            k++;
        }
        else
        {
            arr[k]=b[j];
            k++;
            j++;
        }
    }
    while(i < n1)
    {
        arr[k]=a[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k]=b[j];
        k++;
        j++;
    }
}
void mergeSort(int arr[],int l,int h)
{
    if(l<h)
    {
        int mid=(l+h)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid, h);
    }
    return;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cout<<"Enter size of array :";
    cin>>n;
    int arr [n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    int i=0,j=n-1,target;
    cout<<"enter tareget :";
    cin>>target;
    vector<vector<int>> res;
    while(i<j)
    {
        if(arr[i] + arr[j] == target)
        {
            vector<int> v;
            v.push_back(arr[i]);
            v.push_back(arr[j]);
            res.push_back(v);
            i++;
            j--;
        }
        else if(arr[i] + arr[j] < target)
            i++;
        else 
            j--;
    }
    if(res.empty())
    {
        cout<<"No Such Elements Exist"<<endl;
    }
    else
    {
        for(int i=0;i<res.size();i++)
        {
            cout<<"[";
            for(int j=0;j<res[i].size();j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"]"<<" ";
        }
    }
    cout<<endl;
    }
    return 0;
}
