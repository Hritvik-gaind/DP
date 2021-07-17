#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,k;
    cin>>n>>k;
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            if(i==1)
            {
                dp[i][j] = j;
            }
            else if(j==1)
            {
                dp[i][j] = 1;
            }
            else
            {
                int ans = INT_MAX;
                for(int mj=j-1,pj=0;mj>=0;mj--,pj++)
                {
                    int prevx = dp[i-1][pj];
                    int thisx = dp[i][mj];
                    int maxx = max(prevx,thisx);
                    ans = min(maxx,ans);
                }
                dp[i][j] = ans+1;
            }
        }
    }
    cout<<dp[n][k];
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=k;j++)

    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
