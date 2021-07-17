#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));
    for(int i=n;i>=0;i--)
    {
        for(int j=m;j>=0;j--)
        {
            if(i==n&&j==m)
            {
                dp[i][j] = 0;
            }
            else if(i==n)
            {
                dp[i][j] =1+ dp[i][j+1];
            }
            else if(j==m)
            {
                dp[i][j] = 1+  dp[i+1][j] ;
            }
            else
            {
                if(s1[i]==s2[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else
                {
                  dp[i][j] = min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]))+1;
                }
            }
        }
    }
    cout<<dp[0][0];
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
