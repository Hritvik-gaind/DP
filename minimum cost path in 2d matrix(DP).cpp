#include <iostream>
#include<climits>
using namespace std;
int topdownapproach(int cost[][4],int i,int j,int dp[][100])
{
    //base case
    if(i==0&&j==0)
    {
        dp[i][j] = cost[i][j];
        return cost[i][j];
    }
    if(i<0||j<0)
    {
        dp[i][j] = INT_MAX;
        return INT_MAX;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }


    //recursive case
    int op1,op2;
    op1 = op2 = INT_MAX;
    op1 = topdownapproach(cost,i-1,j,dp);
    op2 = topdownapproach(cost,i,j-1,dp);
    return dp[i][j] =  min(op1,op2) + cost[i][j];

}


int topdown(int cost[][4],int i,int j)
{
    //base case
    if(i==0&&j==0)
    {
        return cost[i][j];
    }
    if(i<0||j<0)
    {
        return INT_MAX;
    }


    //recursive case
    int op1,op2;
    op1 = op2 = INT_MAX;
    op1 = topdown(cost,i-1,j);
    op2 = topdown(cost,i,j-1);
    return min(op1,op2) + cost[i][j];

}
int bottomup(int cost[][4],int i,int j)
{
    int dp[100][100];

    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(i==0&&j==0)
            {
             dp[i][j] = cost[i][j];
            }
            else if(i==0)
            {
                dp[i][j] = dp[i][j-1] + cost[i][j];
            }
            else if(j==0)
            {
                dp[i][j] = dp[i-1][j] + cost[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i][j-1],dp[i-1][j])+cost[i][j];
            }
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return dp[i][j];
}
int main() {
   int cost[][4] = {
       {2,1,3,4},
       {3,1,1,10},
       {1,6,1,1},
       {2,7,4,3}
   };
   int dp[100][100]= {0};
   memset(dp,-1,sizeof(dp));
   int i=2,j=3;
   cout<<topdown(cost,i,j)<<endl;
   cout<<topdownapproach(cost,i,j,dp)<<endl;
   cout<<bottomup(cost,i,j);
}
