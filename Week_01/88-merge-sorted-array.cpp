class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos = nums1.size() - 1;
        int p1 = m - 1, p2 = n - 1;
        while (p1 >= 0 || p2 >= 0) {
            int num;
            if (p1 < 0) {
                num = nums2[p2];
                p2--;
            } else if (p2 < 0) {
                num = nums1[p1];
                p1--;
            } else {
                if (nums1[p1] < nums2[p2]) {
                    num = nums2[p2];
                    p2--;
                } else {
                    num = nums1[p1];
                    p1--;
                }
            }
            nums1[pos] = num;
            pos--;
        }        
    }
};
