class Solution {
public:
    class DisjointSet {
    private:
        int count;
        int size;
        vector<int> parent;
    public:
        DisjointSet(int size, int count): count(count), size(size) {
            parent.resize(size);
            for (int i = 0; i < size; i++) parent[i] = i;
        }

        int find(int x) {
            while (parent[x] != x) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        void join(int x, int y) {
            x = find(x);
            y = find(y);
            if (x != y) {
                parent[x] = y;
                count--;
            }
        }

        int getCount() {
            return count;
        }
    };
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        if (cols == 0) return 0;

        int count = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') count++;
            }
        }
        int size = rows * cols;

        DisjointSet djs(size, count);

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    if (i + 1 < rows && grid[i + 1][j] == '1') {
                        djs.join(i * cols + j, (i + 1) * cols + j);
                    }
                    if (j + 1 < cols && grid[i][j + 1] == '1') {
                        djs.join(i * cols + j, i * cols + j + 1);
                    }
                }
            }
        }

        return djs.getCount();
    }
};
