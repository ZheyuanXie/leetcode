//4 ms (55.74%)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[0][0] == 1) return 0;  // start position must not be blocked
        
        // first column and first row
        vector<vector<int>> sol(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),1));
        bool blocked = false;
        for (int i = 1; i < obstacleGrid.size(); i++) {
            if (obstacleGrid[i][0] == 1) blocked = true;
            if (blocked) sol[i][0] = 0;
            else sol[i][0] = 1;
            cout << i;
        }
        blocked = false;
        for (int i = 1; i < obstacleGrid[0].size(); i++) {
            if (obstacleGrid[0][i] == 1) blocked = true;
            if (blocked) sol[0][i] = 0;
            else sol[0][i] = 1;
        }
        
        // dp
        for (int i = 1; i < obstacleGrid.size(); i++) {
            for (int j = 1; j < obstacleGrid[0].size(); j++) {
                sol[i][j] = 0;
                if (obstacleGrid[i][j] == 1) continue;
                if (obstacleGrid[i-1][j] == 0) sol[i][j] += sol[i-1][j];
                if (obstacleGrid[i][j-1] == 0) sol[i][j] += sol[i][j-1];
            }
        }
        return sol[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};