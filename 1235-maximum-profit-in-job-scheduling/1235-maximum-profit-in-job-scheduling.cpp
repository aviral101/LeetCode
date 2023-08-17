class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int dp[50001];
        vector<vector<int>> v;
        int n = startTime.size();
        for(int i = 0; i < n; i++)
        {
            v.push_back({endTime[i], startTime[i], profit[i]});
        }
        sort(v.begin(), v.end());
        dp[0] = v[0][2];
        for(int i = 1; i<n; i++)
        {
            int l = 0;
            int s = v[i][1];
            int r = i-1;
            //cout<<s<<" "<<l<<" "<<r<<"\n";
            if(l > r) l = r;
            while(l < r)
            {
                int mid = l + (r-l + 1)/2;
                if(s < v[mid][0])
                {
                    r = mid - 1;
                }
                else
                    l = mid;
            }
            //cout<<l<<" "<<r<<"\n";
            if(r == 0 && v[r][0] > s)
            {
                dp[i] = max(v[i][2], dp[i-1]);
            }
            else
                dp[i] = max(dp[i-1],dp[l] + v[i][2]);
        }
        return dp[n-1];

    }
};