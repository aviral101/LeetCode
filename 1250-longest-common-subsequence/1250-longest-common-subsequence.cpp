class Solution {
public:
    int d[1001][1001];
    int dp(string &s1, int i, int n, string &s2, int j, int m)
    {
        if(i < 0 || j < 0)
        {
            return 0;
        }
        if(d[i][j] != -1) return d[i][j];
        if(s1[i] == s2[j])
        {
            return d[i][j] = 1 + dp(s1,i-1,n,s2,j-1,m);
        }
        else
        {
            return d[i][j] = max(dp(s1,i-1,n,s2,j,m), dp(s1,i,n,s2,j-1,m));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        for(int i = 0; i<= text1.size(); i++)
        {
            for(int j = 0; j<= text2.size(); j++)
            {
                d[i][j] = -1;
            }
        }
        return dp(text1,text1.size()-1,text1.size(),text2, text2.size()-1 , text2.size());
    }
};