class Solution {
    int isparent(int i, vector<int> &v)
    {
        while(v[i] != i)
        {
            i = v[i];
        }
        return i;
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> v(n, -1);
        for(int i = 0; i<n; i++)
        {
            v[i] = i;
        }
        vector<int> rank(n, 0);
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j <n; j++)
            {
                if(i != j && isConnected[i][j] == 1)
                {
                    int a = isparent(i,v);
                    int b = isparent(j,v);
                    // cout<<a<<" "<<b<<"\n";
                    if(rank[a] < rank[b])
                    {
                        v[a] = b;
                        rank[b]++;
                    }
                    else
                    {
                        v[b] = a;
                        rank[a]++;
                    }
                }
            }
        }
        int c = 0;
        for(int i = 0; i<n; i++)
        {
            // cout<<v[i]<<" ";
            if(v[i] == i) c++;
        }
        return  c;
    }
};