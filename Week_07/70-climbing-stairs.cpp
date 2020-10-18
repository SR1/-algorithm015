class Solution {
public:
    int climbStairs(int n) {
        caches.resize(n + 1, 0);
        return climbStairsInternal(n);
    }
private:
    int climbStairsInternal(int n) {
        if (caches[n] > 0) return caches[n];
        if (n == 1) return 1;
        if (n == 2) return 2;
        int res = climbStairsInternal(n - 1) + climbStairsInternal(n - 2);
        caches[n] = res;
        return res;
    }
    vector<int> caches;
};
