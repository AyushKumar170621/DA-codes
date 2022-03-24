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
int insertionSort(int a[],int n)
{
    int cnt=0;
    for(int i=1 ;i < n ;i++)
    {
        int key = a[i];
        int j= i -1 ;
        while(j >= 0 && key < a[j] )
        {
            cnt++;
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
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
    int com = insertionSort(a,n);
    printArr(a,n);
    cout<<"Total no of Comparison is "<<com<<endl;
    return 0;
}