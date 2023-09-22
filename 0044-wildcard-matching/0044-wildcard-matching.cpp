class Solution {
public:
    int d[2001][2001];
    int dp(string &s, int i, string &p, int j)
    {
        if(i == s.size())
        {
            for(int k = j; k<p.size(); k++)
            {
                if(p[k] != '*') return d[i][j] = 0;
            }
            return d[i][j] = 1;
        }
        if(i == s.size() && j == p.size()) return 1;
        else if(i == s.size() || j == p.size()) return 0;
        if(d[i][j] != -1) return d[i][j];
        if(p[j] != '*' && p[j] != '?')
        {
            if(s[i] == p[j]) return d[i][j] = dp(s, i+1, p, j+1);
            else
            {
                return d[i][j] = 0;
            }
        }
        if(p[j] == '?' || s[i] == p[j])
        {
            return d[i][j] = (dp(s, i+1, p, j+1));
        }
        if(p[j] == '*')
        {
            return d[i][j] = (dp(s,i,p,j+1) | dp(s,i+1,p,j));
        }
        return d[i][j] = 0;
    }
    bool isMatch(string s, string p) {
        memset(d,-1,sizeof(d));
        return dp(s, 0, p , 0);
    }
};