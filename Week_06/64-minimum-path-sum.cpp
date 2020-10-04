class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[i][j]: 从左上角走到位置(i, j)
        // dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        
        // 边界条件: 
        // i == 0 && j == 0 时, dp[0][0] = grid[0][0]
        // i == 0 时, dp[0][j] = dp[0][j - 1] + grid[0][j]
        // j == 0 时, dp[i][0] = dp[i - 1][0] + grid[i][0]

        vector<vector<int>> dp(grid);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (i == 0 && j == 0) {
                    dp[0][0] = grid[0][0];
                } else if (i == 0) {
                    dp[0][j] = dp[0][j - 1] + grid[0][j];
                } else if (j == 0) {
                    dp[i][0] = dp[i - 1][0] + grid[i][0];
                } else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }
        }

        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
