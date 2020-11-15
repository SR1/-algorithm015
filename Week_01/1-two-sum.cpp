class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            if (map.find(other) != map.end()) {
                result.push_back(map[other]);
                result.push_back(i);
                return result;
            }
            map[nums[i]] = i;
        }
        return result;
    }
};
