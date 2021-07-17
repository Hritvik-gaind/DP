#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    int dp[n+1][m+1];
    int maxx = INT_MIN;
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                if(dp[i][j]>maxx)
                {
                    maxx = dp[i][j];
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
   cout<<maxx;
}
