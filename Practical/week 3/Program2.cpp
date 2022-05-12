2. Given an unsorted array of integers, design an algorithm and implement a program to sort this array using selection sort. Your program should also find number of comparisons and number of swaps required. Source code :-
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
int selectionSort(int a[],int n,int *swp)
{
    int cnt=0;
    for(int i=0 ;i < n-1 ;i++)
    {
        int pos=i,min=a[i];
        for(int j=i+1;j<n;j++)
        {
            cnt++;
            if(a[j] < min)
            {
                min=a[j];
                pos=j;
            }
        }
        
            (*swp)++;
            a[pos] = a[i];
            a[i]=min;
        
    }
    return cnt;
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,sw=0;
        cin >> n;
        int a[n];
        readArr(a,n);
        int com = selectionSort(a,n,&sw);
        printArr(a,n);
        cout<<"Comparison "<<com<<endl;
        cout<<"Swap "<<sw<<endl;
    }
    return 0;
}
