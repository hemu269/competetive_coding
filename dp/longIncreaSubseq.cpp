#include<bits/stdc++.h>
using namespace std;
int dp[100];
int fun(int a[],int n)
{
    int maxi=1;
    for(int i=0;i<n;i++)
    {
        if(a[i]<a[n])
        {
            int x;
            if(dp[i]!=-1) x=dp[i]+1;
            else if(dp[i]==-1)
            {
                x=fun(a,i)+1;
                dp[i]=x-1;
            }
            if(x>maxi)
            maxi=x;
        }
    }
    return maxi;
}
int main()
{
    memset(&dp,-1,sizeof(dp));
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<fun(a,n-1)<<endl;
    return 0;
}