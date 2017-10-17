#include<bits/stdc++.h>
using namespace std;
int dp[1000][2];
int main()
{
    //memset(&dp,1,sizeof(dp));
    for(int i=0;i<1000;i++)
        {dp[i][0]=1; dp[i][1]=1;}
    int n;
    cin>>n;
    int a[n],ans=1;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i] && dp[i][0]<dp[j][1]+1)
                dp[i][0]=dp[j][1]+1;
            if(a[j]>a[i] && dp[i][1]<dp[j][0]+1)
                dp[i][1]=dp[j][0]+1;
        }
        if(ans<max(dp[i][0],dp[i][1]))
            ans=max(dp[i][0],dp[i][1]);
    }
    cout<<ans<<endl;
    return 0;
}