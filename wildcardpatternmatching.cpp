#include<iostream>
using namespace std;
int main()
{
    string s1,s2;
    cin>>s2>>s1;
    int n = s1.length();
    int m =s2.length();
    bool dp[n+1][m+1] = {false};
    for(int  i=n;i>=0;i--)
    {
        for(int j=m;j>=0;j--)
        {
            if(i==n && j==m)
            {
                dp[i][j] =true;
            }
            else if(i==n)
            {
                dp[i][j] = false;
            }
            else if(j==m)
            {
                if(s1[i]=='*')
                {
                    dp[i][j] = dp[i+1][j];
                }
                else
                {
                    dp[i][j] =false;
                }
            }
            else
            {
                if(s1[i]=='?'||s1[i]==s2[j])
                {
                    dp[i][j] = dp[i+1][j+1];
                }
                else if(s1[i]=='*')
                {
                    dp[i][j] = dp[i][j+1]||dp[i+1][j];
                }
                else
                {
                    dp[i][j] = false;
                }
            }

        }
    }
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=m;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;

    // }
    cout<<boolalpha<<dp[0][0];

}
