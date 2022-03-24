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
int selectionSort(int a[],int n)
{
    int cnt=0;
    for(int i=0 ;i < n-1 ;i++)
    {
        int pos=i,min=a[i];
        for(int j=i+1;j<n;j++)
        {
            if(a[j] < min)
            {
                cnt++;
                min=a[j];
                pos=j;
            }
        }
        if(i != pos)
        {
            a[pos] = a[i];
            a[i]=min;
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
    int com = selectionSort(a,n);
    printArr(a,n);
    cout<<"Total no of Comparison is "<<com<<endl;
    return 0;
}