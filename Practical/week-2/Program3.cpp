/*3.Given an array of nonnegative integers, design an algorithm and a program to count the number of pairs of integers such that their difference is equal to a given key, K.
Source code:-*/
#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,key,c=0;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        cin>>key;
        int i,j,k,f=0;
        for(i=0;i<n-1;i++)
        {
            for(j=i+1 ;j < n ;j++)
            {
                if(abs(a[i] - a[j])==key)
                {    
                    c++;
                    f=1;
                }
            }
        }
        if(f != 0)
            cout<<c<<endl;
        else
            cout<<"No such Pair Exist"<<endl;
    }
    
    return 0;
}
