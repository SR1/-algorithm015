class Solution {
public:
    string reverseWords(string s) {
        stringstream stream(s);
        string result, word;
        while ((stream >> word)) {
            if (result.empty()) {
                result = word;
             } else {
                result = word + " " + result;
            }
        }
        return result;
    }
};
