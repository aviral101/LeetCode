class Solution {
public:
    int numEnclaves(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i<m; i++)
        {
            if(board[i][0] == 1) q.push({i,0}), board[i][0] = 2;
            if(board[i][n-1] == 1) q.push({i,n-1}), board[i][n-1] = 2;

        }
        for(int i = 0; i<n; i++)
        {
            if(board[0][i] == 1) q.push({0,i}), board[0][i] = 2;
            if(board[m-1][i] == 1) q.push({m-1,i}), board[m-1][i] = 2;
        }

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            int i = p.first;
            int j = p.second;
            q.pop();

            if(i-1>=0 && board[i-1][j] == 1)
            {
                q.push({i-1,j});
                board[i-1][j] = 2;
            }
            if(i+1 < m && board[i+1][j] == 1)
            {
                q.push({i+1,j});
                board[i+1][j] = 2;
            }
            if(j-1>=0 && board[i][j-1] == 1)
            {
                q.push({i,j-1});
                board[i][j-1] = 2;
            }
            if(j+1 < n && board[i][j+1] == 1)

            {
                q.push({i,j+1});

                board[i][j+1] = 2;
            }
        }
        int c = 0;
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(board[i][j] == 1) c++;
                // cout<<board[i][j]<<" ";
            }
            // cout<<"\n";
        }

        return c;
    }
};