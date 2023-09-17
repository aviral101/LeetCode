class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ma = 0;
        int l =0, r = INT_MAX-1;
        while(l < r)
        {
            int mid = l + (r - l + 1)/2;
            int flag = -1;
            for(int  i = 0; i<k; i++)
            {
                unsigned long long c = 0;
                
                for(int j = 0; j<n; j++)
                {
                    unsigned long long a = composition[i][j];
                    a = a * (unsigned long long)mid;
                    if(a > stock[j])
                    {
                        a = a - stock[j];
                        c += a * (unsigned long long)cost[j];
                    }
                    if(c > budget)
                    {
                        break;
                    }
                }
                if(c <= budget)
                {
                    flag = 1;
                    break;
                }
            } 
            if(flag == 1)
            {
                l = mid;
            }
            else
            {
                r = mid-1;
            }
        }
        return l;
    }
};