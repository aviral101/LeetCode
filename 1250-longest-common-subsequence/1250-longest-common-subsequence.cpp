class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        ios_base :: sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = text1.size();
        int m = text2.size();
        int d[n+1][m+1];
        memset(d,0,sizeof(d));
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                d[i][j] = (text1[i-1] == text2[j-1])? 1+d[i-1][j-1] : max(d[i-1][j],d[i][j-1]);
            }
        }
        // dp(text1,n-1,text2, m-1);
        return d[n][m];
    }
};