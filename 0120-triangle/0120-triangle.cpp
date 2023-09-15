class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = 2;
        for(int i = 1; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(j - 1 >= 0 && j < m-1)
                {
                    triangle[i][j] = min(triangle[i-1][j],triangle[i-1][j-1]) + triangle[i][j];
                }
                else if(j-1 < 0)
                {
                    triangle[i][j] = triangle[i-1][j] + triangle[i][j];
                }
                else if(j >= m-1)
                {
                    triangle[i][j] = triangle[i-1][j-1] + triangle[i][j];
                }
            }
            m++;
        }
        int ma = 100000000;
        for(int i = 0; i<m-1; i++)
        {
            ma = min(ma,triangle[n-1][i]);
        }
        return ma;
    }
};