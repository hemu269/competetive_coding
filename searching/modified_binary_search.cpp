// what is lower bound 

// if element exists atleast once then the lower bound is index of starting element else the index of element next larger

// what is upper bound

// the index of the element that is next larger whether the element exists or not 

//we can do all the below if the array is sorted

#include<bits/stdc++.h>
using namespace std;
#define long long int ll;

int* binary_search(int *start,int *end,int find)
{
	int *mid,*last=end;
	int count;
	while(start<end)
	{
		count=end-start;
		mid=start+count/2;
		if(*mid==find)
		{
			return mid;
		}
		else if(*mid<find)
		{
			start = mid+1;
		}
		else
		{
			end = mid;
		}
	}
	return last;
}

int* lower__bound(int *start,int *end,int find)
{
	if(*start==find)
	{
		return start;
	}
	int *mid,*last=end;
	int count;
	while(start<end)
	{
		count=end-start;
		mid=start+count/2;
		if(*mid==find)
		{
			if(*(mid-1)==find)
			{
				end = mid;
			}
			else
			{
				return mid;
			}
		}
		else if(*mid<find)
		{
			start = mid+1;
		}
		else
		{
			end = mid;
		}
	}
	return end;
}

int* upper__bound(int *start,int *end,int find)
{
	if(*(end-1)<=find)
	{
		return end;
	}
	int *mid,*last=end;
	int count;
	while(start<end)
	{
		count=end-start;
		mid=start+count/2;
		if(*mid==find)
		{
			if(*(mid+1)==find)
			{
				start = mid+1;
			}
			else
			{
				return mid+1;
			}
		}
		else if(*mid<find)
		{
			start = mid+1;
		}
		else
		{
			end = mid;
		}
	}
	return end;
}

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

	sort(array,array+n);     // sorts the given array . we can do binary search iff the array is sorted

	int queries;

	//cout<<"enter count of queries\n";
	cin>>queries;    //  no.of queries

	while(queries--)
	{
		int i,j;
		//cout<<"enter 0 for search and 1 for lower bound and 2 for upper bound\n";
		cin>>i;

		//cout<<"enter element \n";

		if(i==0)          // whether the element is present in the array or not
		{
			cin>>j;
			int is_found = binary_search(array,array+n,j)-array;    // here array is pointer for 1st element
			if(is_found==n)
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

			int lower = lower__bound(array,array+n,j)-array;

			if( lower == n)
			{
				cout<<"number doesn't exist and every element in the array is less than given number and lower bound is "<<lower<<endl;
			}
			else if( lower==0 && array[lower]!=j)
			{
				cout<<"number doesn't exist and every element in the array is greater than given number and lower bound is 0\n";
			}
			else if(array[lower]!=j)
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

			int upper = upper__bound(array,array+n,j)-array;

			if( upper == 0 )
			{
				cout<<"number doesn't exist and every element in the array is greater than given number and upper bound is 0\n";
			}
			else if(upper==n &&array[upper-1]!=j)
			{
				cout<<"number doesn't exist and every element in the array is less than given number and upper bound is "<<upper<<endl;
			}
			else if(array[upper-1]!=j)
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
