class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio();
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = nums.size();
        int c = 0;
        for(int i =0; i<nums.size(); i++)
        {
            c = c ^ nums[i];
        }
        return c;
    }
};