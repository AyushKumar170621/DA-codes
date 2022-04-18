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
        printf("Enter size of array :");
        scanf("%d",&n);
        int a[n];
        printf("Enter elements in array :");
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        printf("Enter key to search :");
        scanf("%d",&key);
        int ind=search(a,n,key);
        if(ind == -1)
        {
            cout<<"Not Present"<<endl;
        }
        else
        {
            cout<<"Present "<<ind<<endl;
        }
    }
        return 0;
}
