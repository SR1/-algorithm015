class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        int charMap[26] = { 0 };
        for (char c : s) {
            charMap[c - 'a']++;
        }

        for (char c : t) {
            if (--charMap[c - 'a'] < 0) return false;
        }
        
        return true;
    }
};
