class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int flag = 0;
        if(obstacleGrid[0][0] == 1) flag = 1;
        for(int i = 1; i<m; i++)
        {
            if(obstacleGrid[i][0] == 1)
            {
                flag = 1;
            }
            if(flag == 1)
            {
                obstacleGrid[i][0] = 0;
            }
            else
            {
                obstacleGrid[i][0] = 1;
            }
        }
        flag = 0;
        for(int i = 0; i<n; i++)
        {
            if(obstacleGrid[0][i] == 1)
            {
                flag = 1;
            }
            if(flag == 1)
            {
                obstacleGrid[0][i] = 0;
            }
            else
            {
                obstacleGrid[0][i] = 1;
            }
        }
        // cout<<"fsdfsdf\n";
        for(int i = 1; i<m; i++)
        {
            for(int j = 1; j<n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                {
                    obstacleGrid[i][j] = 0;
                }
                else
                {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        // for(int i = 0; i<m; i++)
        // {
        //     for(int j = 0; j<n; j++)
        //     {
        //         cout<<obstacleGrid[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        return obstacleGrid[m-1][n-1];
    }
};