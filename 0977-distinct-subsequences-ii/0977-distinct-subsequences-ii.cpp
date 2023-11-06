class Solution {
public:
    int distinctSubseqII(string s) {
        vector<long long> v(26);
        long long mod = (long long)1e9 + 7;
        int n = s.size();
        for(int i = 0; i<n; i++)
        {
            v[s[i] - 'a'] = accumulate(v.begin(), v.end(), 1LL)%mod;
        }
        return accumulate(v.begin(), v.end(), 0LL)%mod;
    }
};