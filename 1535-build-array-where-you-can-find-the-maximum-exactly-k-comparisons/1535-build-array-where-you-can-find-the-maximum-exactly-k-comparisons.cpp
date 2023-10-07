class Solution {
public:
    int d[51][51][101];
    int dp(int i, int n, int m, int k, int ma)
    {
        if(k < 0) return 0;
        if(k == 0 && i == n) return 1;
        if(i == n) return 0;
        int x = 0;
        if(d[i][k][ma] != -1) return d[i][k][ma];
        for(int j = 1; j<=m; j++)
        {
            if(j > ma)
            {
                x = (x + dp(i+1, n, m, k-1, j))%(1000000007);
            }
            else    x = (x + dp(i+1, n, m, k, ma))%(1000000007);
        }
        return d[i][k][ma] = x;
    }
    int numOfArrays(int n, int m, int k) {
        memset(d,-1, sizeof(d));
        return dp(0,n,m,k,0);
    }
};