#include <iostream>
#include<climits>
using namespace std;
int minnoofcoins(int *coins,int amount,int n)
{
    //base case
    if(amount==0)
    {
        return 0;

    }
    //recursive case
    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(amount - coins[i]>=0)
        {
            int chotaamount = amount - coins[i];
            int chotaans = minnoofcoins(coins,chotaamount,n);
            if(chotaans<ans&&chotaans!=INT_MAX)
            {
                ans = chotaans +1;
            }
        }
    }
    return ans;
}
//topdown
int topdown(int *coins,int amount,int n,int *dp)
{
    //base case
    if(amount==0)
    {
        dp[amount] = 0;
        return 0;

    }
    //cal
    if(dp[amount]!=-1)
    {
        return dp[amount];
    }
    //recursive case

    int ans = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(amount - coins[i]>=0)
        {
            int chotaamount = amount - coins[i];
            int chotaans = minnoofcoins(coins,chotaamount,n);
            if(chotaans<ans&&chotaans!=INT_MAX)
            {
                ans = chotaans +1;
            }
        }
    }
    dp[amount] = ans;
    return ans;
}
int bottomup(int *coins,int amount,int n)
{
    int *dp = new int[amount +1];
    for(int i=0;i<=amount;i++)
    {
        dp[i]= INT_MAX;
    }
    dp[0] =0;

    for(int i=1;i<=amount;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i-coins[j]>=0)
            {
                int chotaamount = i-coins[j];
                dp[i] = min(dp[chotaamount]+1,dp[i]);
            }

        }

    }
    for(int i=0;i<=amount;i++)
    {
        cout<<dp[i]<<" ";
    }
    return dp[amount];
}
int main() {
    int amount;
    cin>>amount;
    int coins[] = {1,7,10};
    int n = sizeof(coins)/sizeof(int);
    int *dp = new int[amount+1];
    for(int i=0;i<=amount;i++)
    {
        dp[i] = -1;
    }

    cout<<minnoofcoins(coins,amount,n)<<endl;
    cout<<topdown(coins,amount,n,dp)<<endl;
    cout<<bottomup(coins,amount,n);

}
