class Solution {
public:
    bool compareit(vector<int> &nums, int n, vector<int> &map, int i, int j)
    {
        while(j != -1)
        {
            if(nums[i] % nums[j] != 0) return false;
            j = map[j];
        }
        return true;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> dp(n,1);
        vector<int> map(n,-1);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(compareit(nums,n,map,i,j))
                {
                    if(1 + dp[j] > dp[i])
                    {
                        dp[i] = 1 + dp[j];
                        map[i] = j;
                    }
                }
            }
        }
        int m = 0,id;
        for(int i = 0; i<n; i++)
        {
            if(m < dp[i])
            {
                m = dp[i];
                id = i;
            }
        }
        vector<int> v;
        while(id != -1)
        {
            v.push_back(nums[id]);
            id = map[id];
        }
        reverse(v.begin(),v.end());
        return v;
    }
};