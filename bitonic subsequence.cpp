#include<iostream>
#include <climits>
using namespace std;
int maxlengthsubsequence(int *arr,int *inc,int *dec,int n)
{
    for(int i=0;i<n;i++)
    {
        inc[i]=1;
        dec[i]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int k=0;k<i;k++)
        {
            if(arr[i]>arr[k])
            {
                inc[i] = max(inc[i],inc[k]+1);
            }
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        for(int k=i+1;k<n;k++)
        {
            if(arr[i]>arr[k])
            {
                dec[i] = max(dec[i],dec[k]+1);
            }
        }
    }
//    for(int i=0;i<n;i++)
//    {
//        cout<<inc[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=0;i<n;i++)
//    {
//       cout<<dec[i]<<" ";
//    }
   int ans=INT_MIN;
   for(int i=0;i<n;i++)
   {
       ans = max(ans,dec[i]+inc[i]-1);
   }
   return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int inc[n];
        int dec[n];
//         memset(inc,0,sizeof(inc));
// 		memset(dec,0,sizeof(dec));
// //        for(int i=0;i<n;i++)
//        {
//            cout<<inc[i]<<" ";
//        }
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<maxlengthsubsequence(arr,inc,dec,n)<<endl;
    }
}
