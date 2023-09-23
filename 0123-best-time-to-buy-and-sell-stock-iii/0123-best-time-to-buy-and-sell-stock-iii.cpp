class Solution {
public:
    // int profit = 0;
    // int b = 2;
    int d[100001][3][2];
    int dp(vector<int> &prices,int i, int n, int b, int buy, int bought)
    {
        if(i == n) return 0;
        if(b == 0 && buy == 1) return 0;
        if(d[i][b][buy] != -1) return d[i][b][buy];
        if(b != 0 && buy == 1)
        {
            return d[i][b][buy] =  max(-1 * prices[i] + dp(prices,i+1,n,b-1,0,prices[i]),dp(prices,i+1,n,b,buy,bought));
        }
        else if(buy == 0)
        {
            return d[i][b][buy] = max( prices[i] + dp(prices, i+1, n, b,1,bought), dp(prices,i+1, n, b, buy, bought));
        }
        return 0;
    }
    int maxProfit(vector<int>& prices) {
        memset(d,-1,sizeof(d));
        return dp(prices,0,prices.size(),2,1,0);
    }
};