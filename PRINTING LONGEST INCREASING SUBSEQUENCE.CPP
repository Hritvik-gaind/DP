#include <iostream>
#include<vector>
using namespace std;
int lis(int *arr,int n)
{
    int dp[100];
    for(int i=0;i<=n;i++)
    {
        dp[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i]>arr[j])
            {
                dp[i] = max(dp[i],dp[j]+1);

            }

        }
    }
    int ans=0;
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(ans<arr[i])
        {
            ans = dp[i];
            j=i;
        }

    }
    vector<int> v;
    int len = ans;
    v.push_back(arr[j]);
    len--;
    for(int i=j-1;i>=0;i--)
    {
        if(dp[i]==len&&v[v.size()-1]>arr[i])
        {
            v.push_back(arr[i]);
            len--;
        }
    }
    for(int i=v.size()-1;i>=0;i--)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return ans;

}
int main() {
    int arr[]={1,3,2,6,4,7,3,8};
    int n = sizeof(arr)/sizeof(int);
    cout<<lis(arr,n);
}
