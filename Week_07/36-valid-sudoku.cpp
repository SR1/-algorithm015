class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(10, false));
        vector<vector<bool>> cols(9, vector<bool>(10, false));
        vector<vector<bool>> blks(9, vector<bool>(10, false));

        for (int row = 0; row < 9; row++) {
            for (int clo = 0; clo < 9; clo++) {
                char c = board[row][clo];
                if (c == '.') continue;
                int idx = c - '0';
                int blkIdx = row / 3 + clo / 3 * 3;
                if (rows[row][idx] == true 
                    || cols[clo][idx] == true 
                    || blks[blkIdx][idx] == true) {
                    return false;
                }
                rows[row][idx] = true;
                cols[clo][idx] = true;
                blks[blkIdx][idx] = true;
            }
        }
        return true;
    }
};
