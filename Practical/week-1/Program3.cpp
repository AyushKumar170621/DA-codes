#include <iostream>
#include <cmath>
using namespace std;
int jumpSearch(int arr[], int x, int n,int *cnt)
{
    int step = sqrt(n) , next=step  ,  prev = 0;
    while (arr[next] <= x && next < n)
    {
       (*cnt)++;
        prev = next;
        next += step;
        if (next > n-1)
            next=n;
    }
    for(int i=prev;i<=next-1;i++)
    {
        if(arr[i]==x)
        {   
            (*cnt)++;
            return i;
        }
    }
    return -1;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,key,c=0,cnt=0;;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>key;
        int ind=jumpSearch(a,key,n,&cnt);
        if(ind == -1)
        {
            cout<<"Not Present"<<cnt<<endl;
        }
        else
        {
            cout<<"Present  "<<cnt<<endl;
        }
    }
    return 0;
}
