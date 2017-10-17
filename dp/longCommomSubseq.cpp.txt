#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];

int fun(string a,string b,int n,int m)
{
    if(n==0 || m==0)
        return 0;
    if(a[n]==b[m])
    {
        if(dp[n-1][m-1]==-1)
            dp[n-1][m-1]=fun(a,b,n-1,m-1);
        dp[n][m]=1+dp[n-1][m-1];
        return dp[n][m];     
    }
    else
    {
        if(dp[n-1][m]==-1)
            dp[n-1][m]=fun(a,b,n-1,m);
        if(dp[n][m-1]==-1)
            dp[n][m-1]=fun(a,b,n,m-1);
        dp[n][m]=max(dp[n-1][m],dp[n][m-1]);
        return dp[n][m];
    }
}


int main()
{
    //memset(dp,1,1000000*sizeof(int));
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
            {dp[i][j]=-1;}
    int n1,n2;
    string a,b;
    cin>>a>>b;
    n1=a.length();
    n2=b.length();
    cout<<fun(a,b,n1,n2)<<endl;
    return 0;
}