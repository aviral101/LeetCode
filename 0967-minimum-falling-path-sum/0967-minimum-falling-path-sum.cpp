class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        for(int i = 1; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                int c;
                if(j-1 >=0 && j + 1 <n)
                {
                    c = min(matrix[i-1][j-1],matrix[i-1][j]);
                    c = min(c, matrix[i-1][j+1]);
                }
                else if(j-1<0)
                {
                    c = min(matrix[i-1][j],matrix[i-1][j+1]);
                }
                else if(j + 1 >= n)
                {
                    c = min(matrix[i-1][j-1],matrix[i-1][j]);
                }
                matrix[i][j] += c;
            }
        }
        int mi = 100000000;
        for(int i = 0; i<n; i++)
        {
            mi = min(mi,matrix[m-1][i]);
        }   
        return mi;
    }
};