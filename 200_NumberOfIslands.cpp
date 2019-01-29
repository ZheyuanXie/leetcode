// dfs
class Solution {
private:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int nrow = grid.size();
        int ncol = grid[0].size();
        
        grid[row][col] = '0';
        if (row > 0 && grid[row-1][col] == '1') dfs(grid,row-1,col);
        if (row < nrow - 1 && grid[row+1][col] == '1') dfs(grid,row+1,col);
        if (col > 0 && grid[row][col-1] == '1') dfs(grid,row,col-1);
        if (col < ncol - 1 && grid[row][col+1] == '1') dfs(grid,row,col+1);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int nrow = grid.size();
        if (nrow == 0) return 0;
        int ncol = grid[0].size();
        
        int cnt = 0;
        for (int row = 0; row < nrow; row++) {
            for (int col = 0; col < ncol; col++) {
                if (grid[row][col] == '1') {
                    cnt++;
                    dfs(grid,row,col);
                }
            }
        }
        return cnt;
    }
};