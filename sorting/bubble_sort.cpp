#include<bits/stdc++.h>
using namespace std;
#define long long int ll;

int main()
{
	int n;

	//cout<<"enter size of array\n";
	cin>>n;   // size of input array

	int array[n];

	//cout<<"enter elements\n";

	for (int i = 0; i < n; i++)
	{
		cin>>array[i];
	}
	int count,i,j;
	for(i=0;i<n-1;i++)
	{
		count=0;
		for(j=0;j<n-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				swap(array[j],array[j+1]);
				count++;
			}
		}
		if(count==0)
		{
			break;       // reduces best case complexity to O(n)
		}
	}

	cout<<"sorted array is\n";

	for(i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}

	return 0;
}