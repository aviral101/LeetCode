class Solution {
public:
    int d[1001][1001];
    int dp(string &s, int i, string &t, int j)
    {
        if(t.size() == j) return 1;
        if(i == s.size())
            return 0;
        if(d    [i][j] != -1) return d[i][j];
        if(s[i] == t[j])
        {
            return d[i][j] = dp(s,i+1, t , j) + dp(s,i+1, t, j+1);
        }
        else return d[i][j] = dp(s, i+1, t, j);
    }
    int numDistinct(string s, string t) {
        memset(d,-1,sizeof(d));
        return dp(s,0,t,0);
    }
};