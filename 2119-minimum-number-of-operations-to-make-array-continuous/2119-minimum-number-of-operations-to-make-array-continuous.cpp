class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int,int> m;
        int l = 0;
        int ma = 0;
        for(int i = 0; i<n; i++)
        {
            // cout<<l<<" "<<i<<"\n";
            if(nums[i] < nums[l] + n && m.find(nums[i]) == m.end())
            {
                m[nums[i]]++;
                ma = (ma < m.size())? m.size() : ma;
            }
            else if(nums[i] >= nums[l] + n)
            {
                auto it = m.find(nums[l]);
                if(it != m.end())
                    m.erase(it);
                l++;
                i--;
            }
        }
        return n - ma;
    }
};