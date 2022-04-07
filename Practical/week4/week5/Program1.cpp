/*Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and
implement it using a program to find which alphabet has maximum number of occurrences and
print it. (Time Complexity = O(n)) */
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	{
		
    		int n;
    		cout<<"Enter size of array :";
    		cin>>n;
    		char ch[n];
    		for(int i=0;i<n ;i++)
    		{
     		   cin>>ch[i];
    		}
    		vector <int> arr(26) ;
    		for(int i=0;i<n;i++)
    		{
     		   arr[int(ch[i])-97]++;
    		}
    		int max=arr[0],pos=0;
    		for(int i=1;i<n;i++)
    		{
        		if(arr[i]>max)
        		{
            		max=arr[i];
            		pos=i;
        		}
    		}
    		cout<<(char)(97 + pos)<<" - "<<max<<endl;
	}
    return 0;
}
