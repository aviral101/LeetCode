class Solution {
public:
    int dp[50001][2];
    int rec(vector<int> &prices, int n, int i, int buy, int fee)
    {
        if(i >= n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy == 1)
        {
            return dp[i][buy] = max(-1 * prices[i] - fee + rec(prices,n,i+1,0,fee), rec(prices,n,i+1,buy,fee));
        }
        else return dp[i][buy] = max(prices[i] + rec(prices,n,i+1,1,fee), rec(prices,n, i+1, buy,fee));
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return rec(prices,prices.size(),0,1,fee);
    }
};