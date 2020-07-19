class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j)
    {
        if(i < 0 || i >= grid.size() ||
           j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j]='0';
        
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
    }

    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int row = grid.size();
        if (row == 0)
            return 0;
        int col = grid[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(grid[i][j] == '1')
                {
                    result++;
                    dfs(grid, i, j);
                } 
            }
        }
        return result;
    }
};