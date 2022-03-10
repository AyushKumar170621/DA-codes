/*1) Given a sorted array of +ve integers containing few duplicate elements design a algo and implement it using a programm  to 
find whether the given key is present in the array or not.
if it  is present find total no of copies of the given key ....*/
#include <iostream>

using namespace std;

int main()
{
    int n,key;
    cout<<"Enter size of array :";
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Enter key :";
    cin>>key;
    int count = -1;
    for(int i=0;i<n;i++)
    {
        if(key == a[i])
            ++count;
    }
    if(count == -1)
        cout<<"Key is not present in array"<<endl;
    else
        cout<<"Key is present and number of occurence is "<<count+1<<endl;
    return 0;
}