class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> sub_result;
        if (k == 0) return result;

        combine(0, n, k, result, sub_result);
        return result;
    }
private:
    void combine(int start, int end, int nums, 
                 vector<vector<int>>& result,
                 vector<int>& sub_result) {
        if (nums == 0) {
            result.push_back(sub_result);
            return;
        }

        for (int i = start; i < end; i++) {
            sub_result.push_back(i + 1);
            combine(i + 1, end, nums - 1, result, sub_result);
            sub_result.pop_back();
        }
    }
};
