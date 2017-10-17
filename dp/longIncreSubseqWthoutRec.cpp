#include<bits/stdc++.h> 
using namespace std;
int dp[1000];
int main()
{
    //memset(&dp,1,sizeof(dp));
    for(int y=0;y<1000;y++)
            dp[y]=1;
    int n;
    cin>>n;
    int a[n],ans=1;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i] && dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
        if(ans<dp[i])
            ans=dp[i];
    }
    cout<<ans<<endl;
    return 0;
}