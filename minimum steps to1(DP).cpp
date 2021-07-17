#include<iostream>
#include<climits>
using namespace std;
int topdown(int n,int *dp)
{
    //base case
    if(n==1)
    {
        dp[n] = 0;
        return 0;
    }
    //recursive case
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    int op1 ,op2,op3;
    op1=op2=op3=INT_MAX;
    op1 = topdown(n-1,dp);
    if(n%3==0)
    {
        op2 = topdown(n/3,dp);
    }
    if(n%2==0)
    {
        op3 = topdown(n/2,dp);
    }
    dp[n] = min(op1,min(op2,op3))+1;
    return min(op1,min(op2,op3))+1;
}
int minstepsto1(int n)
{
    //recursive case
    if(n==1)
    {
        return 0;
    }
    //base case
    int op1,op2,op3;
    op1=op2=op3= INT_MAX;
    op1 = minstepsto1(n-1);
    if(n%3==0)
    {
        op2 = minstepsto1(n/3);
    }
    if(n%2==0)
    {
        op3 = minstepsto1(n/2);
    }

    return min(op1,min(op2,op3))+1;
}
int bottomup(int n)
{
    int *dp = new int [n+1];
    //initialization
    dp[1] = 0;
    int op1,op2,op3;
    int ans ;
    for(int i=2;i<=n;i++)
    {
        ans=0;
        op1 = op2=op3 =INT_MAX;
        op1 = dp[i-1];
        if(i%2==0)
        {
            op2 = dp[i/2];
        }
        if(i%3==0)
        {
            op3 = dp[i/3];
        }

        ans  = min(op1,min(op2,op3))+1;

        dp[i] =ans;

    }
    for(int i=1;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<minstepsto1(n)<<endl;
    int *dp = new int[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i] = -1;
    }
    // memset(dp,-1,sizeof(dp));
    cout<<topdown(n,dp)<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl<<bottomup(n);

    return 0;
}
