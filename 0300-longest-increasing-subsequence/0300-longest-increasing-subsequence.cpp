class Solution {
public:
    int dp[2501][2501];
    int rec(vector<int> &nums, int i, int n, int p)
    {
        if(i >= n) return 0;
        if(dp[i][p+1] != -1) return dp[i][p+1];
        int a = -1000000,b = -100000;
        if(p == -1 || nums[i] > nums[p])
        {
            a = 1 + rec(nums,i + 1, n, i);
        }
        b = rec(nums, i+1, n, p);
        // cout<<a<<" "<<b<<"\n";
        return dp[i][p+1] = max(a,b);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(nums, 0, nums.size(), -1);
    }
};