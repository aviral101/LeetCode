class Solution {
public:
    static bool compare(vector<int> a, vector<int> b)
    {
        if(a[1] < b[1]) return true;
        return false;
    }
    int maximizeTheProfit(int h, vector<vector<int>>& offers) {
        sort(offers.begin(), offers.end(), compare);
        int n = offers.size();
        int dp[100000 + 1];
        dp[0] = offers[0][2];
        for(int i = 1; i<n; i++)
        {
            int l = 0, r = i - 1;
            if(r < l) r = l;
            while(l < r)
            {
                int mid = l + (r-l)/2;
                if(offers[i][0] <= offers[mid][1])
                {
                    r = mid;
                }
                else
                {
                    l = mid+1;
                }
            }
            if(l == i-1)
            {
                if(offers[l][1] >= offers[i][0])    l--;
            }
            else
            {
                l--;
            }
            if(l < 0)
            {
                dp[i] = max(offers[i][2], dp[i-1]);
            }
            else
            {
                dp[i] = max(offers[i][2] + dp[l], dp[i-1]);
            }
        }
        return dp[n-1];
        
    }
};