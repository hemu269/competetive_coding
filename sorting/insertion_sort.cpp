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

	int i,j;

	cin>>array[0];

	for (i = 1; i < n; i++)
	{
		cin>>array[i];
		j=i;
		while(j>0)
		{
			if(array[j]<array[j-1])
			{
				swap(array[j],array[j-1]);
				j--;
			}
			else
			{
				break;
			}
		}
	}

	cout<<"sorted array is\n";

	for(i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}

	return 0;
}