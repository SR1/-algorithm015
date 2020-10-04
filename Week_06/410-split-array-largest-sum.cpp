class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        // dp[i][j]: 把 i 个数字分割成 j 个非空连续子数组，各自和的最小最大值
        // sub(i, j): 从 i 到 j 的和
        // dp[i][j] = min(max(dp[k][j - 1], sub(k + 1, i))) (j - 1 <= k < i)

        vector<int> sub(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) { sub[i] = sub[i - 1] + nums[i - 1]; }

        vector<vector<int>> dp(nums.size() + 1, vector<int>(m + 1, INT_MAX));
        dp[0][0] = 0;

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j <= min(i, m); j++) {
                for (int k = 0; k < i; k++) {
                    dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sub[i] - sub[k]));
                }
            } 
        }


        return dp[nums.size()][m]; 
    }
};
