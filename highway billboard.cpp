#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main()
{
    int m,n;
    cin>>m>>n;
    int position[n];
    int revenue[n];
    int dp[m+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++)
    {
        cin>>position[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>revenue[i];
    }
    int t;
    cin>>t;
    map<int,int> mn;
    for(int i=0;i<n;i++)
    {
        mn.insert({position[i],revenue[i]});
    }
    // for(auto x:mn)
    // {
    //     cout<<x.first<<" "<<x.second<<" "<<endl;
    // }
    dp[0] = 0;
    for(int i=1;i<=m;i++)
    {
        if(mn.find(i) == mn.end())
        {
            dp[i]= dp[i-1];
        }
        else
        {
            int boardnotinstalled = dp[i-1];
            int boardinstalled = mn[i];
            if(i>=t+1)
            {
                boardinstalled +=dp[i-t-1];
            }
            dp[i] = max(boardnotinstalled,boardinstalled);
        }

    }
    // for(int i=1;i<=m;i++)
    // {
    //     cout<<mn[i]<<" ";
    // }cout<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<dp[i];
    // }
    cout<<dp[m];




    // int ans=0;
    // for(int i=1;i<n;i++)
    // {
    //     for(int j=0;j<i;j++)
    //     {
    //         if(position[i]-position[j]>t)
    //         {
    //             dp[i] = max(dp[i],revenue[i] + dp[j]);
    //         }
    //         else
    //         {
    //             dp[i] = max(dp[i],revenue[i]);
    //         }
    //     }
    //     ans = max(ans,dp[i]);
    // }

    // for(int i=0;i<n;i++)
    // {
    //     ans = max(ans,dp[i]);
    // }
    // cout<<ans;
}
