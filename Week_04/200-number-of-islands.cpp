class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int height = grid.size();
        if (height == 0) return 0;

        int width = grid[0].size();
        if (width == 0) return 0;

        int island = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == '1') {
                    // 找到陆地
                    island++;
                    reachPossibleLand(grid, i, j, height, width);
                }
            }
        }
        return island;
    }
private:
    void reachPossibleLand(vector<vector<char>>& grid, int i, int j, int height, int width) {
        if (i < 0 || j < 0 || i >= height || j >= width) return;
        if (grid[i][j] == '1') {
            grid[i][j] = '0';
            reachPossibleLand(grid, i - 1, j, height, width);
            reachPossibleLand(grid, i + 1, j, height, width);
            reachPossibleLand(grid, i, j - 1, height, width);
            reachPossibleLand(grid, i, j + 1, height, width);
        }
    }
};

// *实现思路:* 
// 深度优先搜索、广度优先搜索
// 岛屿的每块土地都相连，可通过一块土地，访问下一块土地，迭代访问到岛屿的每块土地

// *实现难点:*
// 1. 需要记录每块访问过的土地，避免重复访问，可通过开辟一个新的表格来记录已经访问过的土地格子
// 2. 比较巧妙的方式是复用输入的二维网格，将访问过的格子标记为`0(水)`，避免额外的空间消耗

// *边界场景:*
// 1. 避免访问到网格之外

// *使用到的数据结构:*
// 数组

// *进一步优化:*
// 1. 使用深度优先搜索实现
// 2. 使用广度优先搜索实现
// 3. 了解并使用并查集实现
