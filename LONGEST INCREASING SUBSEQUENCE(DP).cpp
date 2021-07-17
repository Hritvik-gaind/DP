#include <iostream>
using namespace std;
int lis(int *arr,int n)
{
    int dp[100];
    for(int i=0;i<=n;i++)
    {
        dp[i]=1;
    }
    for(int i=01;i<=n;i++)
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
    for(int i=0;i<n;i++)
    {
        if(ans<arr[i])
        {
            ans = dp[i];
        }

    }
    return ans;

}
int main() {
    int arr[]={1,3,2,6,4,7,3,8};
    int n = sizeof(arr)/sizeof(int);
    cout<<lis(arr,n);
}
