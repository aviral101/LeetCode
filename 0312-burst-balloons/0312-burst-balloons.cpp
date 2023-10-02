class Solution {
public:
    int d[1000][1000];
    int dp(vector<int> &nums, int l, int r)
    {
        if(l > r) return 0;
        if(d[l][r] != -1) return d[l][r];
        d[l][r] = 0;
        for(int i = l; i<=r; i++)
        {
            int a,b;
            if(l-1>=0)
            {
                a = nums[l-1];
            }
            else    a = 1;
            if(r+1 < nums.size()) b = nums[r+1];
            else b = 1;
            d[l][r] = max(d[l][r], dp(nums,l,i-1) + dp(nums, i+1, r) + nums[i] * a * b);
        }
        return d[l][r];
    }
    int maxCoins(vector<int>& nums) {
        memset(d,-1,sizeof(d));
        int n = nums.size();
        return dp(nums,0,n-1);
    }
};