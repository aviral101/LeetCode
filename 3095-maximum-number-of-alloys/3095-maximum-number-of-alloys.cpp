class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int ma = 0;
        for(int i = 0; i<k; i++)
        {
            unsigned long long co;
            long long l = 0, r = 10000000000;
            while(l<r)
            {
                long long mid = l + (r - l + 1)/2;
                co = 0;
                // cout<<l<<" "<<r<<"\n";
                // cout<<mid<<" : mid\n";
                for(int j = 0;j <n; j++)
                {
                    unsigned long long a = composition[i][j];
                    a = (unsigned long long)mid * (unsigned long long)a;
                    if(a > stock[j])
                    {
                        a = a - stock[j];
                        co += ((unsigned long long)a)*((unsigned long long)cost[j]);
                        if(co > budget)
                        {
                            break;
                        }
                    }
                    
                }
                // cout<<co<<" : cost\n";
                if(co > budget)
                {
                    r = mid - 1;
                }
                else
                {
                    l = mid;
                }
            }
            co = 0;
            l = r;
            for(int j = 0;j <n; j++)
            {
                unsigned long long a = composition[i][j];
                a = (unsigned long long)l * a;
                if(a > stock[j])
                {
                    a = a - stock[j];
                    co += ((unsigned long long)a)*((unsigned long long)cost[j]);
                    if(co > budget)
                    {
                        co = 10*budget;
                        break;
                    }
                }

            }
            // cout<<l<<" "<<r<<"\n";
            if(co <= budget && ma < l) ma = l;
        }
        return ma;
    }
};