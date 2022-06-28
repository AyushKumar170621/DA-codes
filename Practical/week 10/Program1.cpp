/*I. Given a list of activities with their starting time and finishing time. Your goal is to selectmaximum number of activities that can be performed by a single person 
such that selected activities must be non-conflicting. Any activity is said to be non-conflicting if starting time of anactivity is greater than or equal to the 
finishing time of the other activity. Assume that a person can only work on a single activity at a time.*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int i,s[n],f[n];

    for(i=0;i<n;i++)
    cin>>s[i];

    for(i=0;i<n;i++)
    cin>>f[i];

    vector<vector<int>> a;
    vector<int> act;
    for(i=0;i<n;i++)
    a.push_back({f[i],s[i],i+1});

    sort(a.begin(),a.end());

    int e=INT_MIN,c=0;
    for(i=0;i<n;i++)
    {
        if(a[i][1]>=e)
        {
            e=a[i][0];
            c++;
            act.push_back(a[i][2]);
        }
    }

    cout<<"No. of non-conflicting activities : "<<c<<endl;
    cout<<"List of selected activities : ";
    for(i=0;i<act.size();i++)
    cout<<act[i]<<",";
    return 0;
}
