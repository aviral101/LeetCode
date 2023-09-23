class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ma,mi;
        ma = mi = prices[0];
        int s = 0;

        for(int i = 0; i<n; i++)
        {
            if(prices[i] < ma)
            {
                s += ma - mi;
                ma = prices[i];
                mi = prices[i];
            }
            if(prices[i] > ma)
            {
                ma = prices[i];
            }
            if(prices[i] < mi)  mi = prices[i];
        }
        s += ma - mi;
        return s;
    }
};