class Solution {
public:
    int rob(vector<int>& nums) {
        int n  = nums.size();
        if(n == 1) return nums[n-1];
        vector<int> a(n+1);
        int x = 0;
        a[0] = 0;
        a[1] = nums[0];
        for(int i = 2; i<n; i++)
        {
            a[i] = max(a[i-1],a[i-2] + nums[i-1]);
        }
        x = a[n-1];
        a[1] = 0;
        if(n > 1)
            a[2] = nums[1];
            
        for(int i = 3; i<=n; i++)
        {
            a[i] = max(a[i-1], a[i-2] + nums[i-1]);
        }
        return max(x,a[n]);
    }
};