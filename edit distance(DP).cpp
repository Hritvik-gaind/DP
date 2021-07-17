#include <iostream>
#include<climits>
#include<cstring>
using namespace std;
char s1[100],s2[100];
int editdistance(int i,int j)
{
    //base case
    if(i==0)
    {
        return j;
    }
    if(j==0)
    {
        return i;
    }
    //recursive case
    if(s1[i-1]==s2[j-1])
    {
        return editdistance(i-1,j-1);
    }
    else
    {
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        op1 = 1+editdistance(i-1,j-1);//replace
        op2 = 1+editdistance(i,j-1);//insert
        op3 = 1+editdistance(i-1,j);
        return min(op1,min(op2,op3));

    }
}
int topdown(int i,int j,int dp[][100])
{
    {
    //base case
    if(i==0)
    {

        return dp[i][j]= j;
    }
    if(j==0)
    {
        return dp[i][j]= i;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    //recursive case
    if(s1[i-1]==s2[j-1])
    {
        return editdistance(i-1,j-1);
    }
    else
    {
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        op1 = 1+editdistance(i-1,j-1);//replace
        op2 = 1+editdistance(i,j-1);//insert
        op3 = 1+editdistance(i-1,j);
        return  dp[i][j]= min(op1,min(op2,op3));

    }
}
}
int bottomup(int n,int m)
{
    int dp[100][100] ={0};
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0&&j==0)
            {
                dp[i][j]=0;
            }
            else if(i==0)
            {
                dp[i][j] = j;
            }
            else if(j==0)
            {
                dp[i][j]=i;
            }
            else{
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j] =  dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
    }
    return dp[n][m];

}
int main() {
    cin>>s1>>s2;
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    cout<<editdistance(len1,len2)<<endl;
    int dp[100][100];
    memset(dp,-1,sizeof(dp));
    cout<<topdown(len1,len2,dp)<<endl;
    cout<<bottomup(len1,len2)<<endl;

}
