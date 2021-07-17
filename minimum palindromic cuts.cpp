#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
int main()
{
    string s;
    cin>>s;
    bool dp[1000][1000] = {false};
    int n = s.length();
    for(int g=0;g<n;g++)
    {
        for(int i=0,j=g;j<n;i++,j++)
        {
            if(g==0)
            {
                dp[i][j] = true;
            }
            else if(g==1)
            {
                if(s[i]==s[j])
                {
                dp[i][j] = true;
                }
            }
            else
            {
                if(s[i]==s[j]&& dp[i+1][j-1]==true)
                {
                    dp[i][j] = true;
                }
            }
        }
    }
    int a[1000];
    a[0] = 0;

    for(int j=1;j<n;j++)
    {
        if(dp[0][j]==true)
       {
         a[j]=0;

       }
       else
       {
        int min = INT_MAX;
        for(int i=j;i>=1;i--)
        {
            if(dp[i][j]==true)
            {
               if(a[i-1]<min)
               {
                   min = a[i-1];
               }
            }
        }
        a[j] = min+1;
        }

    }
    cout<<a[n-1];
}
