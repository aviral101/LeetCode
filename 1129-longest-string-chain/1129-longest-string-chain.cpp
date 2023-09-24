class Solution {
public:
    bool compareit(string a, string b)
    {
        if(b.size() == 0 && a.size() == 1) return true;
        if(a.size() > b.size() + 1 || a.size() <= b.size()) return false;
        int m = b.size();
        int n = a.size();
        int j = 0;
        int  c = 0;
        for(int i = 0; i<m; i++)
        {
            if(j >= n) break;
            if(b[i] != a[j])
            {
                j++;
                c++;
            }
            if(b[i] == a[j])
            {
                j++;
            }
        }
        // if(j == a.size() - 1 && c == 0) c = 1;
        if(j == n - 1) c++;
        // cout<<c<<"\n";
        if(c == 1) return true;
        else return false;
    }
    static bool comparator(string a, string b)
    {
        return a.size() < b.size();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),comparator);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(compareit(words[i],words[j]))
                {
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
        }
        int max = 0;
        for(int i =0; i<n; i++)
        {
            if(max < dp[i]) max = dp[i];
        }
        return max;
    }
};