#include <iostream>
using namespace std;
int nstaircase(int n,int k)
{
    //base case
    if(n==0)
    {
        return 1;
    }
    if(n<0)
    {
        return 0;
    }
    //recursive case
    int ans=0;
    for(int j=1;j<=k;j++)
    {
        ans += nstaircase(n-j,n);
    }
    return ans;
}
int topdown(int n,int k,int *dp)
{
    //base case
    if(n==0)
    {
        dp[n] =1;
        return 1;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    if(n<0)
    {
        return 0;
    }
    //recursive case
    int ans=0;
    for(int j=1;j<=k;j++)
    {
        ans += nstaircase(n-j,n);
    }
    dp[n]=ans;
    return ans;
}
int bottomup(int n,int k)
{
    int dp[1000]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        int ans=0;
        for(int j=1;j<=k;j++)
        {
            if(i-j>=0)
            {
                ans+=dp[i-j];
            }

        }
        dp[i] = ans;
    }
    return dp[n];
}
int nstaircaseoptimized(int n,int k)
{
    int dp[1000];
    dp[0]= dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(i-1-k>=0)
        {
            dp[i] = 2*dp[i-1]-dp[i-1-k];
        }
        else
        {
            dp[i] = 2*dp[i-1];
        }

    }
    return dp[n];
}

int main() {
    int n,k;
    cin>>n>>k;
    int dp[1000];
    memset(dp,-1,sizeof(dp));
    cout<<nstaircase(n,k)<<endl;
    cout<<topdown(n,k,dp)<<endl;
    cout<<bottomup(n,k)<<endl;
    cout<<nstaircaseoptimized(n,k);


}

