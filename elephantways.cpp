#include <iostream>
using namespace std;
int elephantways(int i,int j)
{
    //base case
    if(i==0&&j==0)
    {
        return 1;
    }
    //recursive case
    int ans=0;
    //column
    for(int k=0;k<i;k++)
    {
        ans += elephantways(k,j);
    }
    for(int k=0;k<j;k++)
    {
        ans+=elephantways(i,k);
    }
    return ans;

}
int topdown(int i,int j,int dp[][100])
{
    //base case
    if(i==0&&j==0)
    {
        dp[i][j]=1;
        return 1;
    }
    //recursive case
    //cal se phele check
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans =0;
    for(int k=0;k<i;k++)
    {
        ans+= topdown(k,j,dp);
    }
    for(int k=0;k<j;k++)
    {
        ans+= topdown(i,k,dp);
    }
    dp[i][j] =ans;
    return ans;
}
int bottomup(int n,int m)
{
    int dp[100][100] ={0};


    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            int ans =0;
            if(i==0&&j==0)
            {
              dp[i][j] = 1;
            }
            else{
             for(int k=0;k<n;k++)
             {
                 ans += dp[k][j];
             }
             for(int k=0;k<m;k++)
             {
                 ans += dp[i][k];
             }
             dp[i][j]=ans;
            }

        }

    }

    return dp[n][m];
}
int main() {
    int i=3,j=3;
    cout<<elephantways(i,j)<<endl;
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<topdown(i,j,dp)<<endl;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<bottomup(i,j)<<endl;

}
