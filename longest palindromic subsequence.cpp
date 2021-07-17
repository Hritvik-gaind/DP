class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n =s.length();

        int dp[1000][1000]  = {0};
        for(int g=0;g<n;g++)
        {
            for(int i=0,j=g;j<n;i++,j++)
            {
                if(g==0)
                {
                    dp[i][j] =1;
                }
                else if(g==1)
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j]=2;
                    }
                    else
                    {
                        dp[i][j] = 1;
                    }
                }
                else
                {
                    if(s[i]==s[j])
                    {
                        dp[i][j] = 2 + dp[i+1][j-1];
                    }
                    else
                    {
                        dp[i][j] = max(dp[i][j-1],dp[i+1][j]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};
