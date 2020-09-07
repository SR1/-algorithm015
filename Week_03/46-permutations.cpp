class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int, bool> map;
        for (int val : nums) {
            map[val] = false; // 全部未使用
        }

        vector<vector<int>> result;
        vector<int> sub_result;
        
        premute(nums, map, result, sub_result);

        return result;
    }
private:
    void premute(vector<int>& nums, unordered_map<int, bool> map,
                 vector<vector<int>>& result, vector<int>& sub_result) {
        if (sub_result.size() == nums.size()) {
            result.push_back(sub_result);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            int value = nums[i];
            if (map[value] == false) {
                sub_result.push_back(value);
                map[value] = true;
                
                premute(nums, map, result, sub_result);

                map[value] = false;
                sub_result.pop_back();
            }
        }
    }
};
