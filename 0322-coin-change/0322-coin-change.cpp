class Solution {
public:
    int dp[1000001];
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        dp[0] = 0;
        int  n = coins.size();
        for(int i = 1; i<= amount; i++)
        {
            int c = 100000001;
            for(int j = 0; j<n; j++ )
            {
                if(i - coins[j] >= 0 && dp[i-coins[j]] != -1)
                {
                    c = min(c,dp[i-coins[j]] + 1);
                    dp[i] = c;
                }
                
            }
        }
        return dp[amount];
    }
};