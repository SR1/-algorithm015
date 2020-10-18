class Solution {
private:
    class DisjointSet {
    public:
        DisjointSet(int size): size(size), unionCount(size) {
            parent.resize(size);
            for (int i = 0; i < size; i++) { parent[i] = i; }
        }

        int find(int value) {
            while (parent[value] != value) {
                parent[value] = parent[parent[value]];
                value = parent[value];
            }
            return value;
        }

        void join(int x, int y) {
            int xHead = find(x);
            int yHead = find(y);
            if (xHead != yHead) {
                parent[xHead] = yHead;
                unionCount--;
            }
        }

        int getUnionCount() {
            return unionCount;
        }
    private:
        int size;
        int unionCount;
        vector<int> parent;
    };
public:
    int findCircleNum(vector<vector<int>>& M) {
        DisjointSet js(M.size());

        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M.size(); j++) {
                if (M[i][j] == 1) {
                    js.join(i, j);
                }
            }
        }

        return js.getUnionCount();
    }
};
