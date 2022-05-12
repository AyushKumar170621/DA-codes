1.Given an unsorted array of integers, design an algorithm and a program to sort the array using insertion sort. Your program should be able to find number of comparisons and shifts ( shifts total number of times the array elements are shifted from their place) required for sorting the array. Source code:-
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
int insertionSort(int a[],int n,int *s)
{
    int cnt=0;
    for(int i=1 ;i < n ;i++)
    {
        int key = a[i];
        int j= i -1 ;
        (*s)++;
        while(j >= 0 && key < a[j] )
        {
            cnt++;
            (*s)++;
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
    return cnt;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,sh=0;
        cin >> n;
        int a[n];
        readArr(a,n);
        int com = insertionSort(a,n,&sh);
        printArr(a,n);
        cout<<"Comparison "<<com<<endl;
        cout<<"Shift "<<sh<<endl;
}
    return 0;
}
