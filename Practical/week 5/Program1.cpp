/*1. Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and implement it using a program to find which alphabet has maximum number of occurrences and print it.

Source Code :-*/
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
	{
    	int n;
    	cin>>n;
    	char ch[n];
    	for(int i=0;i<n ;i++)
    	{
     	   cin>>ch[i];
    	}
    	vector <int> arr(26) ;
    	for(int i=0;i<n;i++)
    	{
     	   arr[int(ch[i])-97]++;
    	}
    	int max=arr[0],pos=0;
    	for(int i=1;i<n;i++)
    	{
        	if(arr[i]>max)
        	{
        		max=arr[i];
        		pos=i;
        	}
    	}
    	if(max > 1)
    	    cout<<(char)(97 + pos)<<" - "<<max<<endl;
    	else
    	    cout<<"No Dublicates Present"<<endl;
	}
    return 0;
}
INPUT :-

 

OUTPUT :-
 









2. Given an unsorted array of integers, design an algorithm and implement it using a program to find whether two elements exist such that their sum is equal to the given key element.
Source code :-
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
    cin>>n;
    int arr [n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);
    int i=0,j=n-1,target;
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
