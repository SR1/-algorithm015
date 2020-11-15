class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int idx = digits.size();
        while (idx--) {
            digits[idx]++;
            if (digits[idx] < 10) return digits;
            digits[idx] -= 10;
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
