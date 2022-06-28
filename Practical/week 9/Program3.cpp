/*
II. Given a knapsack of maximum capacity w. N items are provided, each having its own value and weight. You have to Design an algorithm and implement it using a program 
to find the list of the selected items such that the final selected content has weight w and has maximum value. You can take fractions of items,i.e. the items can be 
broken into smaller pieces so that you have to carry only a fraction x, of item i, where 0 ≤x≤ 1.
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    float w,wt=0;
    float mv=0;
    cin>>n;

    int weights[n],values[n];
    vector<pair<float,int>> vpw;
    vector<pair<int,int>> iw;
    int i,j;

    for(i=0;i<n;i++)
    cin>>weights[i];

    for(i=0;i<n;i++)
    cin>>values[i];

    cin>>w;

    for(i=0;i<n;i++)
    {
        vpw.push_back({(float)values[i]/weights[i],i});
    }

    sort(vpw.begin(),vpw.end(),greater<pair<float,int>>());

    for(i=0;w>0 && i<n;i++)
    {
        j=vpw[i].second;
        if(weights[j]<=w)
        {
            mv+=values[j];
            w-=weights[j];
            iw.push_back({j+1,weights[j]});
        }
        else
        {
            mv+=vpw[i].first*w;
            iw.push_back({j+1,w});
            w=0;
        }
    }

    cout<<"Maximum value : "<<mv<<endl;

    cout<<"item - weight\n";
    for(i=0;i<iw.size();i++)
    {
        cout<<iw[i].first<<" "<<iw[i].second<<endl;
    }
    return 0;
}
