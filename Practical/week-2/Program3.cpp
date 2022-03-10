/*2)Given a sorted array of positive integers design a algo and implement it using a programm to find three indexes 
i,j,k such that arr[i]+arr[j]=arr[k];*/
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array :";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int i,j,k;
    for(i=0;i<n-2;i++)
    {
        for(j=i+1 ;j < n-1 ;j++)
        {
            for(k=j+1 ; k<n ;k++)
            {
                if(a[i]+a[j] == a[k])
                    cout<<i<<" "<<j<<" "<<k<<endl;
                if(a[i]+a[j] > a[k])
                    break;
            }
        }
    }
    return 0;
}