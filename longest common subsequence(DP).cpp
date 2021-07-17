#include <iostream>
#include<cstring>
#include<climits>
using namespace std;
char s1[100],s2[100];
int lcs(int i,int j)
{
    //base case
    if(s1[i]==NULL||s2[j]==NULL)
    {
        return 0;
    }

    //recursove case
    if(s1[i]==s2[j])
    {
        return 1+lcs(i+1,j+1);
    }
    else
    {
        int op1,op2;
        op1=op2=INT_MIN;
        op1 = lcs(i,j+1);
        op2 = lcs(i+1,j);
        // cout<<op1<<" ";

        return max(op1,op2);

    }
}
int lcstopdown(int i,int j,int dp[][100])
{
    if(s1[i]==NULL||s2[j]==NULL)
    {
        dp[i][j]=NULL;
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    //recursove case
    if(s1[i]==s2[j])
    {
        return 1+lcs(i+1,j+1);
    }
    else
    {
        int op1,op2;
        op1=op2=INT_MIN;
        op1 = lcs(i,j+1);
        op2 = lcs(i+1,j);
        // cout<<op1<<" ";

        return dp[i][j] = max(op1,op2);

    }
}
int bottomup()
{
    int dp[100][100];
    memset(dp,0,sizeof(dp));
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(s1[i-1]==s2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }

    }
    return dp[len1][len2];
}
int main() {
    cin>>s1>>s2;
    cout<<lcs(0,0)<<endl;
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<lcstopdown(0,0,dp)<<endl;
    cout<<bottomup();
}
