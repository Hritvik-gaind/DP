#include<iostream>
#include<climits>
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

    int dp[1000][1000] = {0};
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int min;
    for(int g=0;g<n;g++)
    {
        for(int i=0,j=g;j<n;i++,j++)
        {

            if(g==0)
            {
                dp[i][j] = 0;
            }
            else if(g==1)
            {
                dp[i][j] = arr[i]*arr[j]*arr[j+1];
            }
            else
            {
              min = INT_MAX;
                for(int k=i;k<j;k++)
                {
                    int lc = dp[i][k];
                    int rc = dp[k+1][j];
                    int mc = arr[j+1]*arr[i]*arr[k+1];
                    int x = lc + rc + mc;
                    if(x<min)
                    {
                        min = x;
                    }
                }
                dp[i][j] = min;
            }

        }
    }
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[0][n-2];
}
