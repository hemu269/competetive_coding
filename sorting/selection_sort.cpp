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
	int index,i,j;             // index stores the index of maximum element


	for(i=0;i<n-1;i++)
	{
		index=0;
		for(j=1;j<n-i;j++)
		{
			if(array[j]>array[index])
			{
				index = j;
			}
		}
		swap(array[index],array[n-i-1]);
	}

	cout<<"sorted array is\n";

	for(i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}

	return 0;
}