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
    int k;
    cin>>k;

    int ans = INT_MIN;
    int cs = arr[0];
    int maxsum[n];
    maxsum[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        if(cs>0)
        {
            cs+=arr[i];
        }
        else
        {
            cs = arr[i];
        }
        maxsum[i] = cs;
    }
    int exactk =0;
    for(int i=0;i<k;i++)
    {
        exactk +=arr[i];
    }
    if(exactk>ans)
    {
        ans = exactk;
    }
    for(int i=k;i<n;i++)
    {
        exactk = exactk + arr[i] - arr[i-k];
        if(exactk>ans)
        {
            ans = exactk;
        }
        int atleastk = exactk + maxsum[i-k];
        if(atleastk>ans)
        {
            ans = atleastk;
        }

    }
    cout<<ans;
    // for(int i=0;i<n;i++)
    // {
    //     cout<<maxsum[i]<<" ";
    // }

}
