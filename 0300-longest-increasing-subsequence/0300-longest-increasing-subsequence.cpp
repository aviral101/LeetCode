class Solution {
public:
    int dp[2501][2501];
    int rec(vector<int> &nums, int i, int n, int p)
    {
        if(i >= n) return 0;
        if(dp[i][p+1] != -1) return dp[i][p+1];
        if(p == -1 || nums[i] > nums[p])
        {
            return dp[i][p+1] = max(1 + rec(nums,i + 1, n, i), rec(nums, i+1, n, p));
        }
        else return dp[i][p+1] = rec(nums, i+1, n, p);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return rec(nums, 0, nums.size(), -1);
    }
};