/*III. Given an array of elements. Assume arr[i] represents the size of file i. Write an algorithm and a program to merge all these files into single file with minimum 
computation. For given two files A and B with sizes m and n, computation cost of merging them is O(m+n). (Hint: use greedy approach)
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i,a[n];
    for(i=0;i<n;i++)
    cin>>a[i];

    sort(a,a+n);

    int minc=0,c=a[0];
    for(i=1;i<n;i++)
    {
        c=a[i]+c;
        cout<<c<<" "; 
        minc+=c;
    }

    cout<<endl<<minc;

    return 0;
}
