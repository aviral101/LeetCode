class Solution {
public:
    int dp[40][40][2];
    int dfs(vector<int> &nums, int n, int l, int r, int turn)
    {
        if(l > r) return 0;
        if(dp[l][r][turn] != -1) return dp[l][r][turn];
        if(turn == 0)
        {
            int ma = max(dfs(nums,n,l+1,r,1) + nums[l] , nums[r] + dfs(nums,n,l,r-1,1));
            return dp[l][r][turn] = ma;
        }
        else if(turn == 1)
        {
            int mi = min(dfs(nums,n,l+1,r,0), dfs(nums,n,l,r-1,0));
            return dp[l][r][turn] = mi;
        }
        return 0;
    }
    bool predictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        int a = dfs(nums,n,0,n-1,0);
        int s = 0;
        for(int i = 0; i<n; i++)
        {
            s += nums[i];
        }
        if(a >= s-a) return true;
        return false;

    }
};