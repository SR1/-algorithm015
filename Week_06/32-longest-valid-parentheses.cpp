class Solution {
public:
    int longestValidParentheses(string s) {
        // dp[i] 以 i 为终点的字符串的有效括号子串长度
        // dp[i] = (s[i] == ')' && s[i - 1] == '(') => dp[i - 2] + 2
        //         (s[i] == ')' && s[i - 1 - dp[i - 1]] == '(') => dp[i - 1] + 2 + dp[i - dp[i - 1] - 2]
        //         else => dp[i] = 0

        // dp[0] = 0
        // dp[1] = (s[1] == ')' && s[0] == '(') => dp[1] = 2
        // dp[2] = (s[2] == ')' && s[1] == '(') => dp[0] + 2
        //         (s[2] == ')' && s[2 - s[i - 1 - dp[i - 1]] == '(') => dp[i - 1] + 2
        //         else => dp[2] = 0

        int maxLength = 0;

        vector<int> dp(s.size());
        for (int i = 0; i < s.size(); i++) {
            if (i == 0) {
                dp[0] = 0;
            } else if (i == 1) {
                if (s[0] == '(' && s[1] == ')') {
                    dp[1] = 2;
                } else {
                    dp[1] = 0;
                }
            } else {
                if (s[i - 1] == '(' && s[i] == ')') {
                    dp[i] = dp[i - 2] + 2;
                } else if (i - 1 - dp[i - 1] >= 0 
                            && s[i - 1 - dp[i - 1]] == '(' && s[i] == ')') {
                    int index = i - 1 - dp[i - 1];
                    if (index - 1 > 0) {
                        dp[i] = dp[index - 1] + i - (index - 1);
                    } else {
                        dp[i] = dp[i - 1] + 2;
                    }
                } else {
                    dp[i] = 0;
                }
            }
            maxLength = max(maxLength, dp[i]);
        }
        return maxLength;
    }
};
