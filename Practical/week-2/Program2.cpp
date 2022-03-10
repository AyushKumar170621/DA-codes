/*3) Given a array of non negitive integers design a algo and implement it using a prog to count the no of pairs of 
integers such that their differences is equal to the given key */
#include <iostream>

using namespace std;

int main()
{
    int n,key,c=0;
    cout<<"Enter size of array :";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter key :";
    cin>>key;
    int i,j,k;
    for(i=0;i<n-1;i++)
    {
        for(j=i+1 ;j < n ;j++)
        {
            if(abs(a[i] - a[j])==key)
                c++;
        }
    }
    cout<<"Number of pair having difference equal to "<<key<<"are "<<c<<endl;
    return 0;
}