#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s1;
    cin>>s1;

    int n = s1.length();
    int dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {

               if(s1[i-1]== s1[j-1]&&i-1!=j-1)
               {
                dp[i][j] = 1+dp[i-1][j-1];
               }

            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout<<dp[n][n];
}
