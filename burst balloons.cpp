#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    for(int g=0;g<n;g++)
    {
        for(int i=0,j=g;j<n;i++,j++)
        {
            int max = INT_MIN;
            for(int k=i;k<=j;k++)
            {


                    int left = k==i?0:dp[i][k-1];
                    int right = k==j?0:dp[k+1][j];
                    int val = (i==0?1:arr[i-1])*(j==n-1?1:arr[j+1])*arr[k];
                    int ans = left + right + val;
                    if(ans>max)
                    {
                        max = ans;
                    }

                dp[i][j] = max;
            }

        }
    }
    // }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[0][n-1];
}
