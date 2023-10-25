class Solution {
public:
    int dp[1000][101][2];
    int dfs(vector<int> &piles, int m, int n, int l, int turn)
    {
        if(l >= n) return 0;
        int s = 0;
        if(dp[m][l][turn] != -1) return dp[m][l][turn];
        int ma = 0;
        int mi = 1000000000;
        int idx;
        // cout<<turn<<" "<<l<<" "<<m<<"\n";
        for(int i = l; i<l + 2*m && i < n; i++)
        {
            s += piles[i];
            int a = dfs(piles, max(m,i - l + 1), n, i+1, (turn == 0)?1:0);
            ma = max(ma, s+a);
            mi = min(mi,a);
        }
        // cout<<turn<<" "<<l<<" "<<m<<" "<<ma<<"\n";
        if(turn == 0) return dp[m][l][turn] = ma;
        else return dp[m][l][turn] = mi;
    }
    int stoneGameII(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return dfs(piles, 1, piles.size(), 0, 0);
    }
};