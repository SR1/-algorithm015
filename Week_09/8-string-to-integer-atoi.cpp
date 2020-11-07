class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        while (s[i] == ' ') i++;
        if (i >= s.size()) return 0;

        int sign = 1;
        if (s[i] == '-') sign = -1, i++;
        else if (s[i] == '+') sign = 1, i++;

        long sum = 0;
        while (i < s.size()) {
            int n = s[i] - '0';
            if (n < 0 || n > 9) break;

            sum *= 10;
            sum += n;
            if (sum > INT_MAX) return (sign == 1) ? INT_MAX : INT_MIN;
            i++;
        }
        return sum * sign;
    }
};
