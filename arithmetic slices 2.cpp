#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int n;
    cin>>n;
    ll arr[n];
    int ans =0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<unordered_map<int,int> > freq(n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
          ll cd = arr[i] - arr[j];
          if(cd>INT_MAX || cd<=INT_MIN)
          {
              continue;
          }
          int diff = arr[i] - arr[j];
          ans += freq[j][diff];
          freq[i][diff] +=1 + freq[j][diff];
        }

    }
    cout<<ans;
}
