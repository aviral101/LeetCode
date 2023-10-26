class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i<m; i++)
        {
            if(board[i][0] == 'O') q.push({i,0}), board[i][0] = 'Z';
            if(board[i][n-1] == 'O') q.push({i,n-1}), board[i][n-1] = 'Z';

        }
        for(int i = 0; i<n; i++)
        {
            if(board[0][i] == 'O') q.push({0,i}), board[0][i] = 'Z';
            if(board[m-1][i] == 'O') q.push({m-1,i}), board[m-1][i] = 'Z';
        }

        while(!q.empty())
        {
            pair<int,int> p = q.front();
            int i = p.first;
            int j = p.second;
            q.pop();

            if(i-1>=0 && board[i-1][j] == 'O')
            {
                q.push({i-1,j});
                board[i-1][j] = 'Z';
            }
            if(i+1 < m && board[i+1][j] == 'O')
            {
                q.push({i+1,j});
                board[i+1][j] = 'Z';
            }
            if(j-1>=0 && board[i][j-1] == 'O')
            {
                q.push({i,j-1});
                board[i][j-1] = 'Z';
            }
            if(j+1 < n && board[i][j+1] == 'O')

            {
                q.push({i,j+1});

                board[i][j+1] = 'Z';
            }
        }

        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if(board[i][j] == 'O') board[i][j] = 'X';
                else if(board[i][j] == 'Z') board[i][j] = 'O';
                // cout<<board[i][j]<<" ";
            }
            // cout<<"\n";
        }

        return;
    }
};