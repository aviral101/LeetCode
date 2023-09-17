class Solution {
public:
    int d[1001][1001];
    int dp(string s1, int i, string s2, int j)
    {
        if(i < 0 || j < 0)
        {
            return 0;
        }
        if(d[i][j] != -1) return d[i][j];
        if(s1[i] == s2[j])
        {
            return d[i][j] = 1 + dp(s1,i-1,s2,j-1);
        }
        else
        {
            return d[i][j] = max(dp(s1,i-1,s2,j), dp(s1,i,s2,j-1));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        ios_base :: sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = text1.size();
        int m = text2.size();
        for(int i = 0; i<1001; i++)
        {
            for(int j = 0; j<1001; j++)
            {
                d[i][j] = 0;
            }
        }
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    d[i][j] = 1 + d[i-1][j-1];
                }
                else
                {
                    d[i][j] = max(d[i-1][j],d[i][j-1]);
                }
            }
        }
        // dp(text1,n-1,text2, m-1);
        return d[n][m];
    }
};