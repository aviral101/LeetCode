class Solution {
public:
    int dp[1000001];
    int change(int amount, vector<int>& coins) {
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        int  n = coins.size();
        
        for(int j = 0; j<n; j++ )
        {
            for(int i = 1; i<= amount; i++)    
            {
                if(i - coins[j] >= 0)
                {
                    dp[i] = dp[i] + dp[i - coins[j]];
                }
                
            }
        }
        return dp[amount];
    }
};