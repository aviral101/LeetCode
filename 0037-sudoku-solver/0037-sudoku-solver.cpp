class Solution {
public:
    int flag = 0;
    void solve(vector<vector<char>> &board, vector<vector<int>> &r, vector<vector<int>> &c, vector<vector<int>> &b, int i, int j)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        if(flag == 1) return ;
        if(j == 9) i++, j = 0;
        if(i == 9){
            flag = 1;
            return;
        }
        if(board[i][j] == '.'){
            for(int k = 1; k<=9; k++){
                if(r[i][k] == 0 && c[j][k] == 0 && b[(i/3) * 3 + j/3][k] == 0){
                    r[i][k]++;
                    c[j][k]++;
                    b[(i/3) * 3 + j/3][k]++;
                    board[i][j] = k + '0';
                    solve(board,r,c,b,i,j+1);
                    if(flag == 0)   board[i][j] = '.' , r[i][k]--  , c[j][k]-- , b[(i/3) * 3 + j/3][k]--;
                    else    return ;
                }
            }
        }
        else    solve(board,r,c,b,i,j+1);
        return ;
    }
    void solveSudoku(vector<vector<char>>& board) {
       vector<vector<int>> r(10,vector<int>(10,0)) , c(10,vector<int>(10,0)) , b(10,vector<int>(10,0));
       for(int i = 0; i<9; i++){
           for(int j = 0; j<9; j++){
               if(board[i][j] != '.')   r[i][board[i][j] - '0']++ , c[j][board[i][j] - '0']++ , b[(i/3)*3 + j/3][board[i][j] -'0']++;
           }
       }
       solve(board,r,c,b,0,0);
       return ;
    }
};