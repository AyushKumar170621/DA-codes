/*2.Given a sorted array of positive integers, design an algorithm and implement it using a program to find three indices i, j, k such that arr[i] + arr[j] = arr[k].
Source code :-*/
#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int i,j,k,f=0;
        for(i=0;i<n-2;i++)
        {
            for(j=i+1 ;j < n-1 ;j++)
            {
                for(k=j+1 ; k<n ;k++)
                {
                    if(a[i]+a[j] == a[k]){
                        cout<<i+1<<" "<<j+1<<" "<<k+1<<endl;
                        f=1;
                    }
                }
            }
        }
        if(f==0)
            cout<<"No Sequence Found"<<endl;
    }
    return 0;
}
