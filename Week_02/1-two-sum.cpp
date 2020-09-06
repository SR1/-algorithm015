class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        for (int idx = 0; idx < nums.size(); idx++) {
            int thisVal = nums[idx];
            int otherVal = target - thisVal;
            if (hash.count(otherVal) > 0) {
                vector<int> result;
                result.push_back(hash[otherVal]);
                result.push_back(idx);
                return result;
            }
            hash[thisVal] = idx;
        }
        return vector<int>();
    }
};
