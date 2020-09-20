class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        const int TURN_LEFT  = -2;
        const int TURN_RIGHT = -1;

        const int NORTH = 0;
        const int EAST  = 1;
        const int SOUTH = 2;
        const int WEST  = 3;

        // unordered_set 不支持 pair<int, int>
        // 因此使用 long 来存储两个 int
        unordered_set<long> obstacleSet;
        for (vector<int>& obstacle : obstacles) {
            obstacleSet.insert(((unsigned long)obstacle[0] << 32) | (unsigned)obstacle[1]);
        }

        // 在当前方向上前进的偏移
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        // 当前方向
        int direction = NORTH;
        // 当前位置
        int x = 0, y = 0;
        // 最远欧式距离的平方
        int maxDis = 0;

        for (int command : commands) {
            if (command == TURN_LEFT) {
                direction = (direction + 3) % 4;
            } else if (command == TURN_RIGHT) {
                direction = (direction + 1) % 4;
            } else {
                for (int i = 0; i < command; i++) {
                    int nx = x + dx[direction];
                    int ny = y + dy[direction];
                    if (obstacleSet.find(((unsigned long)nx << 32) | (unsigned)ny) == obstacleSet.end()) {
                        x = nx;
                        y = ny;
                        maxDis = max(maxDis, x * x + y * y);
                    }
                }
            }
        }

        return maxDis;
    }
};

// **实现思路:**

// 贪心算法
// 老实讲，这道题和贪心扯一起有点牵强，或者说，贪心就是暴力求解?
// 贪心可以理解为: 只要没有碰到障碍物，就一直往下走

// **实现难点:**

// 1. 需要能够快速查找是否碰到障碍物不能前进
// 2. 这种类型的查找可以使用 集合
// 3. 集合可以使用 `set` / `unordered_set`
// 4. `set` 支持 `pair<int, int>` 而 `unordered_set` 不支持
// 5. 可以利用 `long` 替代 `pair<int, int>`，巧妙地支持 `unordered_set`
// 6. 使用上述方法，要注意使用 `unsigned`
// 7. 关于前进的方向，使用数组关联索引的方式，将不同方向上的dx、dy预置，后续只需要从数组中直接索引，大大地简化了代码
// 8. 调整方向时，需要注意负数的情况，可将 -1 变为 +3 再取模，避免负数取模后依然得到负数
// 9. 需要使用一个变量，随时记录最大的欧式距离的平方


// **使用到的数据结构:**

// `set`、`unordered_set`
