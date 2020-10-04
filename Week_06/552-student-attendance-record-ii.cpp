class Solution {
public:
    int checkRecord(int n) {
        // dpnAmL[i] 长度为 i ，包含 n 个 A，末尾为 m 个 L 的字符串，有多少种可能
        // dp0A0L[i] = dp0A0L[i - 1] + dp0A1L[i - 1] + dp0A2L[i - 1]
        // dp0A1L[i] = dp0A0L[i - 1]
        // dp0A2L[i] = dp0A1L[i - 1]
        // dp1A0L[i] = dp1A0L[i - 1] + dp1A1L[i - 1] + dp1A2L[i - 1]
        // dp1A1L[i] = dp1A0L[i - 1]
        // dp1A2L[i] = dp1A1L[i - 1]

        // 默认值
        // dp0A0L[0] = 0; dp0A0L[1] = 1 
        // dp0A1L[0] = 0; dp0A1L[1] = 1 
        // dp0A2L[0] = 0; dp0A2L[1] = 0
        // dp1A0L[0] = 0; dp1A0L[1] = 1 
        // dp1A1L[0] = 0; dp1A1L[1] = 0 
        // dp1A2L[0] = 0; dp1A2L[1] = 0

        long dp0A0L[n + 1];
        long dp0A1L[n + 1];
        long dp0A2L[n + 1];
        long dp1A0L[n + 1];
        long dp1A1L[n + 1];
        long dp1A2L[n + 1];

        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                dp0A0L[0] = 0; 
                dp0A1L[0] = 0;  
                dp0A2L[0] = 0; 
                dp1A0L[0] = 0; 
                dp1A1L[0] = 0;  
                dp1A2L[0] = 0; 
            } else if (i == 1) {
                dp0A0L[1] = 1;
                dp0A1L[1] = 1;
                dp0A2L[1] = 0;
                dp1A0L[1] = 1;
                dp1A1L[1] = 0;
                dp1A2L[1] = 0;
            } else {
                dp0A0L[i] = dp0A0L[i - 1] + dp0A1L[i - 1] + dp0A2L[i - 1];
                dp0A1L[i] = dp0A0L[i - 1];
                dp0A2L[i] = dp0A1L[i - 1];

                dp1A0L[i] = dp1A0L[i - 1] + dp1A1L[i - 1] + dp1A2L[i - 1];
                dp1A0L[i] += dp0A0L[i - 1] + dp0A1L[i - 1] + dp0A2L[i - 1];
                dp1A1L[i] = dp1A0L[i - 1];
                dp1A2L[i] = dp1A1L[i - 1];

                dp0A0L[i] %= 1000000007;
                dp0A1L[i] %= 1000000007;
                dp0A2L[i] %= 1000000007;
                dp1A0L[i] %= 1000000007;
                dp1A1L[i] %= 1000000007;
                dp1A2L[i] %= 1000000007;
            }
        }

        int lastIdx = n;
        return (int) ((dp0A0L[lastIdx] + dp0A1L[lastIdx] + dp0A2L[lastIdx] + dp1A0L[lastIdx] + dp1A1L[lastIdx] + dp1A2L[lastIdx]) % 1000000007);
    }
};
