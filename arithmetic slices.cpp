#include<bits/stdc++.h>
using namespace std;
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        int ans = 0;
        memset(dp,0,sizeof(dp));
        for(int i=2;i<n;i++)
        {
            if(nums[i] - nums[i-1] == nums[i-1] - nums[i-2])
            {
                dp[i] = dp[i-1] + 1;
                ans +=dp[i];
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     cout<<dp[i]<<" ";
        // }
        // cout<<endl;
        return ans;
    }
    int main()
    {
        int n;
        cin>>n;
        vector<int> nums;
        for(int i=0;i<n;i++)
        {
            int no;
            cin>>no;
            nums.push_back(no);
        }
        cout<<numberOfArithmeticSlices(nums);
    }
