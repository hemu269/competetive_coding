// what is lower bound 

// if element exists atleast once then the lower bound is index of starting element else the index of element next larger

// what is upper bound

// the index of the element that is next larger whether the element exists or not 


//we can do all the below if the array is sorted

#include<bits/stdc++.h>
using namespace std;
#define long long int ll;

int binary_search()
{


}

int lower__bound()
{


}

int upper__bound()
{


}

int main()
{
	int n;
	cin>>n;   // size of input array

	int array[n];

	for (int i = 0; i < n; i++)
	{
		cin>>array[i];
	}

	sort(a,a+n);     // sorts the given array . we can do binary search iff the array is sorted

	int queries;
	cin>>queries;    //  no.of queries

	while(queries--)
	{
		int i,j;
		cin>>i;

		if(i==0)          // whether the element is present in the array or not
		{
			cin>>j;
			int is_found = binary_search(a,a+n,j);    // here a is pointer for 1st element
			if(is_found==-1)
			{
				cout<<"element not found\n";
			}
			else
			{
				cout<<"element found at position " << is_found << endl;
			}
		}
		else if(i==1)     //  for lower bound of the element 
		{
			cin>>j;

			int lower = lower__bound(a,a+n,j);

			if( lower == n)
			{
				cout<<"number doesn't exist and every element in the array is less than given number and lower bound is "<<lower<<endl;
			}
			else if( lower==0 && a[lower]!=j)
			{
				cout<<"number doesn't exist and every element in the array is greater than given number and lower bound is 0\n";
			}
			else if(a[lower]!=j)
			{
				cout<<"number doesn't exist but lower bound is "<<lower<<endl;
			}
			else
			{
				cout<<"number exists and lower bound is "<<lower<<endl;
			}
		}
		else if(i==2)      // for upper bound of the element 
		{
			cin>>j;

			int upper = upper__bound(a,a+n,j);

			if( upper == 0 )
			{
				cout<<"number doesn't exist and every element in the array is greater than given number and upper bound is 0\n";
			}
			else if(upper==n &&a[upper-1]!=j)
			{
				cout<<"number doesn't exist and every element in the array is less than given number and upper bound is "<<upper<<endl;
			}
			else if(a[upper-1]!=j)
			{
				cout<<"number doesn't exist but upper bound is "<<upper<<endl;
			}
			else
			{
				cout<<"number exists and upper bound is "<<upper<<endl;
			}
		}
	} 

	return 0;
}

