class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1) return 0;

        int maxLength = 0;
        vector<int> dp(s.size());
        for (int i = 0; i < s.size(); i++) {
            cout << s[i];
            if (s[i] == '(') {
                dp[i] = 0;
            } else {
                int idx = i - 1;
                if (i > 0) idx -= dp[i - 1];
                
                if (idx >= 0 && s[idx] == '(') {
                    dp[i] = dp[i - 1] + 2;
                    if (idx > 0) dp[i] += dp[idx - 1];
                } else {
                    dp[i] = 0;
                }
            }
            maxLength = max(maxLength, dp[i]);
        }

        return maxLength;
    }
};
