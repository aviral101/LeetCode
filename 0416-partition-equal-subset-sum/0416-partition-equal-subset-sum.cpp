class Solution {
public:
    bool dp[400001];
    bool canPartition(vector<int>& arr) {
        int k = 0;
        int n = arr.size();
        for(int i = 0; i<n; i++)
        {
            k += arr[i];
        }
        if(k%2 == 1) return false;
        k = k/2;
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        memset(dp,false,sizeof(dp));
        dp[0] = true;
        for(int i = 0; i<n; i++)
        {
            for(int j = k; j-arr[i]>=0; j--)
            {
                dp[j] = dp[j] | dp[j-arr[i]];
            }
        } 
        return dp[k];
    }
};