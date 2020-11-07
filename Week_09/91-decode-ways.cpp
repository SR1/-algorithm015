class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) return 0;

        int size = s.size();
        vector<int> dp(size + 1);
        for (int i = 0; i < size; i++) {
            if (i == 0) {
                if (s[i] == '0') return 0; // 第一位为 0 无法解码
                dp[1] = 1;
            } else if (i == 1) {
                string num2 = s.substr(0, 2);
                if ("10" <= num2 && num2 <= "26") {
                    if (s[i] == '0') dp[2] = 1;
                    else dp[2] = 2; 
                } else {
                    if (s[i] == '0') return 0;
                    else dp[2] = 1;
                }
            } else {
                string num2 = s.substr(i - 1, 2);
                if ("10" <= num2 && num2 <= "26") {
                    if (s[i] == '0') {
                        dp[i + 1] = dp[i - 1]; // '0' 无法独立解码，在 dp[i - 1]的基础上两位解码
                    } else {
                        dp[i + 1] = dp[i - 1] + dp[i]; // 既可组合解码，又可独立解码 
                    }
                } else {
                    if (s[i] == '0') return 0; // ‘0’ 无法单独解码
                    dp[i + 1] = dp[i];
                }
            }
        }
        return dp[size];
    }
};
