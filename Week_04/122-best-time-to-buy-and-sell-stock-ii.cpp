class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;

        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            // 可以理解为只要知道明天会涨，就今天买入，明天卖出
            int delta = prices[i] - prices[i - 1];
            if (delta > 0) {
                profit += delta;
            }
        }

        return profit;
    }
};

// *实现思路:* 
// 贪心算法
// 贪心体现在不错过任何一天的收益，也就是只要知道明天会涨，就今天买入明天卖出

// *实现难点:*
// 老实说，这个贪心的点不够明显。

// *潜在的坑:*
// 可能会跟动态规划混淆
