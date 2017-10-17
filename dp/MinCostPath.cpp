#include<bits/stdc++.h> 
using namespace std;
int dp[1000][1000];
#define n1 3
#define n2 3
    //const int n1=3;
      //  const int n2=3;
int a[n1][n2];
int func(int n,int m)
{
    if(n==0 && m==0)
    {        
        dp[0][0]=a[0][0];
        return dp[0][0];
    }
    if(n==0)
    {
        if(dp[0][m-1]==-1)
            dp[0][m-1]=func(0,m-1);
        dp[0][m]=dp[0][m-1]+a[0][m];
        return dp[0][m];
    }
    if(m==0)
    {
        if(dp[n-1][0]==-1)
            dp[n-1][0]=func(n-1,0);
        dp[n][0]=dp[n-1][0]+a[n][0];
        return dp[n][0];
    }
    if(dp[n-1][m-1]==-1)
        dp[n-1][m-1]=func(n-1,m-1);
    if(dp[n][m-1]==-1)
        dp[n][m-1]=func(n,m-1);
    if(dp[n-1][m]==-1)
        dp[n-1][m]=func(n-1,m);
    dp[n][m]=min(min(dp[n][m-1]+a[n][m],dp[n-1][m]+a[n][m]),dp[n-1][m-1]+a[n][m]);
    return dp[n][m];
}


int main()
{
    //memset(dp,1,1000000*sizeof(int));
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
            {dp[i][j]=-1;}
    //cin>>n1>>n2;
    //int a[n1+1][n2+1];
    for(int i=0;i<n1;i++)
        for(int j=0;j<n2;j++)
            cin>>a[i][j];
    cout<<func(n1-1,n2-1)<<" "<<endl;
    return 0;
}