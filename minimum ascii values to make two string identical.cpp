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
                dp[i][j] = dp[i][j+1] + int(s2[j]);
            }
            else if(j==m)
            {
                dp[i][j] = dp[i+1][j] + int(s1[i]);
            }
            else
            {
                if(s1[i] == s2[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else
                {
                    dp[i][j] = min(int(s1[i])+dp[i+1][j],int(s2[j])+dp[i][j+1]);
                }
            }
        }
    }
    cout<<dp[0][0];
}
