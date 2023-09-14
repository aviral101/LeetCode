class Solution {
public:
    int climbStairs(int n) {
        ios_base::sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> v(n+1);
        v[1] = 1;
        v[0] = 1;
        for(int i = 2; i<=n; i++)
        {
          v[i] = v[i-1] + v[i-2];
        }
        return v[n];
    }
};