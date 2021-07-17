#include<iostream>
using namespace std;
int minimumpages(int *arr,int n)
{
    int dp[n]={0};
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        dp[i] =1;
        if(arr[i]>arr[i-1])
        {
            dp[i] = dp[i-1]+1;
        }
        else if(arr[i]>arr[i+1]&&i!=n-1)
        {
            dp[i]=2;
        }
    }
    int cnt =0;
    cout<<"[";
    for(int i=0;i<n-1;i++)
    {
        cout<<dp[i]<<",";
    }
    cout<<dp[n-1]<<"]";
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cnt+=dp[i];
    }

    return cnt;

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<minimumpages(arr,n);
}
