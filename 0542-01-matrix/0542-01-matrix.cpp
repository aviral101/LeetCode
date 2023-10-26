class Solution {
public:
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int,pair<int,int>>> q;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({0,{i,j}});
                }
                else
                {
                    mat[i][j] = -1;
                }
            }
        }
        while(!q.empty())
        {
            pair<int,pair<int,int>> p = q.front();
            q.pop();
            int i = p.second.first;
            int j = p.second.second;
            int w = p.first;
            if(i-1 >= 0 && mat[i-1][j] == -1)
            {
                mat[i-1][j] = w+1;
                q.push({w+1,{i-1,j}});
            }
            if(i + 1 < m && mat[i+1][j] == -1)
            {
                mat[i+1][j] = w+1;
                q.push({w+1,{i+1,j}});
            }
            if(j - 1 >=0 && mat[i][j-1] == -1)
            {
                mat[i][j-1] = w+1;
                q.push({w+1,{i,j-1}});
            }
            if(j+1 < n && mat[i][j+1] == -1)
            {
                mat[i][j+1] = w+1;
                q.push({w+1,{i,j+1}});
            }
        }
        return mat;
    }
};