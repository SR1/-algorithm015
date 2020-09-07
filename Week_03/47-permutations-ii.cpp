// https://leetcode-cn.com/problems/permutations-ii/solution/c-jian-dan-hui-su-by-da-li-wang/
// 参考自此题解：
//    和其他通过 visited 记录是否使用过不同
//    此题解使用 map 减少了排序和记录visited 的开销
//    通过对 map 遍历，天然达成了避免重复使用同一个数的目的
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int value : nums) {
            map[value]++;
        }

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> sub_result;

        permuteUnique(nums, map, result, sub_result);

        return result;
    }
private:
    void permuteUnique(vector<int>& nums, unordered_map<int, int>& map,
                       vector<vector<int>>& result, vector<int>& sub_result) {
        if (nums.size() == sub_result.size()) {
            result.push_back(sub_result);
            return;
        }

        for (auto& entry : map) {
            if (entry.second > 0) {
                entry.second--;
                sub_result.push_back(entry.first);

                permuteUnique(nums, map, result, sub_result);

                sub_result.pop_back();
                entry.second++;
            }
        }
    }
};
