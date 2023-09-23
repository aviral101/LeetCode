class Solution {
public:
    int dp[5001][2];
    int rec(vector<int> &prices, int n, int i, int buy)
    {
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy == 1)
        {
            return dp[i][buy] = max(-1 * prices[i] + rec(prices,n,i+1,0), rec(prices,n,i+1,buy));
        }
        else return dp[i][buy] = max(prices[i] + rec(prices,n,i+2,1), rec(prices,n, i+1, buy));
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return rec(prices,prices.size(),0,1);
    }
};