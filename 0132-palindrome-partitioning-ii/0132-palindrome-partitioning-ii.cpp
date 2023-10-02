class Solution {
public:
    int d[2001][2001];
    bool check(string &s, int l, int r)
    {
        while(l <= r)
        {
            if(s[l] == s[r])
            {
                l++;
                r--;
            }
            else return false;
        }
        return true;
    }
    int dp(string &s, int l, int r)
    {
        if(l > r) return 0;
        if(check(s,l,r)) return d[l][r] = 0;
        if(d[l][r] != -1) return d[l][r];
        d[l][r] = INT_MAX;
        for(int i = l; i<=r; i++)
        {
            if(check(s,l,i))
                d[l][r] = min(d[l][r], dp(s,i+1,r) + 1);
        }
        return d[l][r];
    }
    int minCut(string s) {
        memset(d,-1,sizeof(d));
        return dp(s,0,s.size()-1);
    }
};