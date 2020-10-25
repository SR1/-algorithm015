class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        int times = 32;
        while (times--) {
            uint32_t low = n & 1;
            result |= low;
            if (times) {
                n = n >> 1;
                result = result << 1;
            }
        }
        return result;
    }
};
