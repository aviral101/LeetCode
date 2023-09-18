class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        ios_base :: sync_with_stdio(0);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int n = text1.size();
        int m = text2.size();
        int d[n+1][m+1];
        memset(d,0,sizeof(d));
        for(int i = 1; i<=n; i++)
        {
            for(int j = 1; j<=m; j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    d[i][j] = 1 + d[i-1][j-1];
                }
                else
                {
                    d[i][j] = max(d[i-1][j],d[i][j-1]);
                }
            }
        }
        int l = m, r = n;
        vector<pair<int,int>> v;
        while(l> 0 && r>0)
        {
            if(text1[r-1] == text2[l-1])
            {
                v.push_back(make_pair(r-1,l-1));
                l--;
                r--;
            }
            else
            {
                int a = d[r][l-1];
                int b = d[r-1][l];
                if(a > b)
                {
                    l--;
                }
                else
                {
                    r--;
                }
            }
        }
        reverse(v.begin(),v.end());
        l = 0; r = 0;
        int k = v.size();
        string str = "";
        int x = 0, y = 0;
        for(int i = 0; i<k; i++)
        {
            int a,b;
            a = v[i].first;
            b = v[i].second;
            for(int j = x; j<a; j++)
            {
                str += text1[j];
            }
            for(int j = y; j<b; j++)
            {
                str += text2[j];
            }
            str += text1[a];
            x = a+1;
            y = b+1;
        }
        for(int i = x; i<n; i++)
        {
            str += text1[i];
        }
        for(int i = y; i<m; i++)
        {
            str += text2[i];
        }
        return str;
    }
};