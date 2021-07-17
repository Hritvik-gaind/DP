#include<bits/stdc++.h>
using namespace std;
int n;
int kadanes(int *arr,int p)
{
    int cs=0,ms = INT_MIN;
    for(int i=0;i<p;i++)
    {
        if(cs>=0)
        {
            cs+=arr[i];
        }

        else
        {
            cs=arr[i];
        }
        ms= max(cs,ms);
    }
    return ms;
}
int kadanesoftwo(int *arr)
{
    int *narr = new int[2*n];
    for(int i=0;i<n;i++)
    {
        narr[i] = arr[i];
    }
    for(int i=0;i<n;i++)
    {
        narr[i+n] = arr[i];
    }
    // for(int i=0;i<2*n;i++)
    // {
    //     cout<<narr[i];
    // }
    return kadanes(narr,2*n);
}
int main()
{

    cin>>n;
    int arr[n];
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int k;
    cin>>k;
    int ans;
    if(k==1)
    {
        ans = kadanes(arr,n);
    }
    else if(sum<0)
    {
        ans = kadanesoftwo(arr);
    }
    else
    {
        ans = kadanesoftwo(arr) + (k-2)*sum;
    }
    cout<<ans;
}
