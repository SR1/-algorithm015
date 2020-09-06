class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> collect; // key: origin word; value: sorted word
        for (string& word : strs) {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());
            collect[sorted_word].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& entry : collect) {
            result.push_back(entry.second);
        }
        return result;
    }
};
