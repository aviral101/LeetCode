class Solution {
public:
    int d[1000][1000];
    int ans(vector<int> &arr, int l, int r)
    {
        int m = 0;
        for(int i = l; i<=r; i++)
        {
            m = max(m,arr[i]); 
        }
        return m * (r - l + 1);
    }
    int dp(vector<int> &arr, int k, int l, int r)
    {
        if(r - l + 1 <= k)
        {
            return ans(arr,l,r);
        }
        if(d[l][r] != -1) return d[l][r];
        d[l][r] = 0;
        for(int i = l; i<=l + k - 1 ; i++)
        {
            d[l][r] = max(d[l][r], dp(arr,k,l,i) + dp(arr,k,i+1,r));
        }
        return d[l][r];
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(d,-1,sizeof(d));
        return dp(arr,k,0,arr.size()-1);
    }
};