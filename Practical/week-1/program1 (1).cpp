/*Given an array of non -ve integer design a linear search algorithm and implement it using a program to find whether the given key element is present in the array or not 
also find the Total number of comparison */
#include <iostream>

using namespace std;
int search(int a[],int n,int key)
{
    int rs=-1;
    for(int i=0;i<n;i++)
    {
        if(key==a[i])
        {
            rs=i;
        }
    }
    return rs;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,key;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>key;
        int ind=search(a,n,key);
        if(ind == -1)
        {
            cout<<"Not Present "<<n<<endl;
        }
        else
        {
            cout<<"Present "<<ind + 1<<endl;
        }
    }
        return 0;
}
