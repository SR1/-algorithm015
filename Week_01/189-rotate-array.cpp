class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 0 || k % nums.size() == 0) return;
        
        int size = nums.size();
        k = k % size;
        vector<int> copy(nums);
        for (int i = 0; i < size; i++) {
            nums[i] = copy[(size - k + i) % size];
        }
    }
};
