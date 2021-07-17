#include <iostream>
#include<climits>
using namespace std;
int bottomup(int *price,int n)
{
    int dp[100][100] = {0};
    //initialization
    //diagonals
    for(int i=0;i<n;i++)
    {
        dp[i][i] = n*price[i];
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int j=0;j<n;j++)
        {

            int day = n -(j-i);
            if(i<j)
            {

                dp[i][j] = max(price[i]*day+dp[i+1][j],price[j]*day+dp[i][j-1]);


            }

        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return dp[0][n-1];
}
int topdown(int l,int r,int *price,int day,int dp[][100])
{
    //base case
    if(l>r)
    {
        dp[l][r] = 0;
        return 0;
    }
    //cal se pehle check
    if(dp[l][r]!=-1)
    {
        return dp[l][r];
    }

    //recursive case
    int op1,op2;
    op1=op2=INT_MIN;
    op1 = price[l]*day + topdown(l+1,r,price,day+1,dp);
    op2 = price[r]*day + topdown(l,r-1,price,day+1,dp);
    dp[l][r] = max(op1,op2);
    return max(op1,op2);

}
int winemaxprofit(int l,int r,int *price,int day)
{
    //base case
    if(l>r)
    {
        return 0;
    }
    //recursive case
    int op1,op2;
    op1=op2=INT_MIN;
    op1 = price[l]*day + winemaxprofit(l+1,r,price,day+1);
    op2 = price[r]*day + winemaxprofit(l,r-1,price,day+1);
    return max(op1,op2);

}
int main() {
    int price[] = {2,3,5,1,4};
    int n = sizeof(price)/sizeof(int);
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<winemaxprofit(0,n-1,price,1)<<endl;
    cout<<topdown(0,n-1,price,1,dp)<<endl;
    cout<<bottomup(price,n);
}
