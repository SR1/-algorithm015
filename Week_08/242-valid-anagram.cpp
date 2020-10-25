class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> map(26);
        for (char c : s) map[c - 'a']++;
        for (char c : t) {
            map[c - 'a']--;
            if (map[c - 'a'] < 0) return false;
        }
        return true;
    }
};
