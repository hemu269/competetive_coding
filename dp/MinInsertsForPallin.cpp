#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
int f(string a,int i,int j)
{
    //cout<<i<<" "<<j<<endl;
    if(i==j-1)
    {
        if(a[i]==a[j])
            return 0;
        else
            return 1;
    }
    if(i>j)
        return 0;
    if(a[i]!=a[j])
    {
        if(dp[i+1][j]==-1)
            dp[i+1][j]=f(a,i+1,j);
        if(dp[i][j-1]==-1)
            dp[i][j-1]=f(a,i,j-1);
        return dp[i][j]=min(dp[i+1][j]+1,dp[i][j-1]+1);    
    }
    else
    {
        if(dp[i+1][j-1]==-1)
            dp[i+1][j-1]=f(a,i+1,j-1);     
        return dp[i][j]=dp[i+1][j-1];
    }
}
int main()
{
    for(int i=0;i<1000;i++)
        for(int j=0;j<1000;j++)
            dp[i][j]=-1;
 
    int n;
    string a;
    cin>>a;
    n=a.length();
    cout<<f(a,0,n-1);
}