class Solution {
public:
    int d[1001][1001];
    int dp(string &s, int l, int r)
    {
        if(l == r) return 1;
        if(l > r) return 0;
        if(d[l][r] != -1) return d[l][r];
        if(s[l] == s[r])
        {
              return d[l][r] = 2 + dp(s,l+1,r-1);
        }
        else
        {
            return d[l][r] = max(dp(s,l+1,r),dp(s,l,r-1));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memset(d,-1,1001 * 1001 * sizeof(int));
        return dp(s,0,n-1);

    }
};