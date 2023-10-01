class Solution {
public:
    int d[1000][1000];
    int dp(vector<int> &cuts, int l, int r, int i, int j)
    {
        if(i == j && (cuts[i] == l || cuts[i] == r)) return 0;
        if(i > j) return 0;
        if(d[i][j] != -1) return d[i][j];
        d[i][j] = INT_MAX;
        for(int k = i; k<= j; k++)
        {
            d[i][j] = min(d[i][j], dp(cuts,l,cuts[k],i,k - 1) + dp(cuts, cuts[k],r,k+1,j) + r - l);
            // cout<<l<<" "<<r<<" "<<i<<" "<<j<<" "<<d[i][j]<<"\n";
        }
        return d[i][j];
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(),cuts.end());
        memset(d,-1,sizeof(d));
        int m = cuts.size();
        return dp(cuts, 0, n, 0, m - 1);
    }
};