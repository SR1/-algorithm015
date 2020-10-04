class Solution {
public:
    int minDistance(string word1, string word2) {
            // dp[i][j] <= 把字符串从word1[0:i] 变换成word2[0:j] 所需的最小编辑距离
            // dp[i][j]: (word1[i] == word2[j]) => dp[i - 1][j - 1]
            //           (dp[i - 1][j] + 1) // 插入一个字符
            //           (dp[i + 1][j] + 1) // 删除一个字符
            //           (dp[i][j] + 1) // 替换一个字符
            
        int dp[word1.size() + 1][word2.size() + 1];
        for (int i = 0; i < word1.size() + 1; i++) {
            for (int j = 0; j < word2.size() + 1; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = i + j;
                } else if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1]; // 字符相同不需要编辑
                } else {
                    dp[i][j] = min(
                        min(
                            dp[i - 1][j] + 1, // 添加一个字符
                            dp[i][j - 1] + 1 // 删除一个字符
                        ),
                        dp[i - 1][j - 1] + 1 // 替换一个字符
                    );
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
