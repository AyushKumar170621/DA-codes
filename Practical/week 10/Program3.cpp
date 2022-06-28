/*III. Given an unsorted array of elements, design an algorithm and implement it using a program to find whether majority element exists or not. Also find median of the 
array. A majority element is an element that appears more than n/2 times, where n is the size of array.  */

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i,a[n],c,j;
    for(i=0;i<n;i++)
    cin>>a[i];

    bool f=0;
    sort(a,a+n);
    for(i=0;i<n;i++)
    {
        c=1;
        j=i+1;
        while(j<n && a[j++]==a[i])
            c++;
        if(c>n/2)
        {
            cout<<"yes\n";
            f=1;
            break;
        }
        i=j-1;
    }
    if(f==0)
    cout<<"no\n";

    if(n%2!=0)
    cout<<a[n/2];
    else
    cout<<((float)a[n/2]+a[n/2-1])/2;
    return 0;
}
