/*Given an already sorted array of +ve integers disign an algorithm and implement it using program to find wheather the key is present or not also find the number
of comparsion*/
#include <iostream>
using namespace std;
int bin_search(int a[],int l,int h,int key,int *c)
{
    while(l <= h)
    {
        int mid=(l+h)/2;
        ++(*c);
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
    int t;
    cin>>t;
    while(t--){
        int n,key,c=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>key;
        int ind=bin_search(a,0,n-1,key,&c);
        if(ind == -1)
        {
            cout<<"Not Present"<<endl;
        }
        else
        {
            cout<<"Present  "<<c<<endl;
        }
    }
    return 0;
}

