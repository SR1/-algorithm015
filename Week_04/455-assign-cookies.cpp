class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int gsize = g.size();
        int ssize = s.size();
        if (gsize == 0 || ssize == 0) return 0;

        // 从小到大排序
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int count = 0;
        int i = 0, j = 0;
        while (i < gsize && j < ssize) {
            // 尽可能匹配恰好满足还在胃口的饼干
            if (g[i] <= s[j]) {
                i++;
                j++;
                count++;
            } else {
                j++; // 下一块饼干
            }
        }
        return count;
    }
};

// **实现思路:**

// 贪心算法
// 此贪心的最优选择为: 为孩子分配恰好满足其胃口的最小饼干
