#include <iostream>

using namespace std;
void readArr(int a[],int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cin>>a[i];
    }
}
void printArr(int a[],int n)
{
    for(int i = 0 ; i < n ; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int bubbleSort(int a[],int n)
{
    int cnt=0;
    for(int i=0 ;i < n-1 ;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(a[j] > a[j+1])
            {
                cnt++;
                a[j]=a[j]^a[j+1];
                a[j+1]=a[j]^a[j+1];
                a[j] =a[j] ^ a[j+1];
            }
        }
    }
    return cnt;
}
int main()
{
    int n;
    cout<<"Enter no of element of array :";
    cin >> n;
    int a[n];
    readArr(a,n);
    int com = bubbleSort(a,n);
    printArr(a,n);
    cout<<"Total no of Comparison is "<<com<<endl;
    return 0;
}