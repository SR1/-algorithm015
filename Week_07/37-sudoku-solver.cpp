class Solution {
private: 
    unordered_set<int> rows[9];
    unordered_set<int> cols[9];
    unordered_set<int> blks[9];

    int indexOfRow(int x, int y) {
        return x;
    }

    int indexOfCol(int x, int y) {
        return y;
    }

    int indexOfBlk(int x, int y) {
        return x / 3 * 3 + y / 3;
    }

    void init(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int value = board[i][j] - '0';
                    rows[indexOfRow(i, j)].insert(value);
                    cols[indexOfCol(i, j)].insert(value);
                    blks[indexOfBlk(i, j)].insert(value);
                }
            }
        }
    }

    bool solveSudoku(vector<vector<char>>& board, int position) {
        if (position == 81) return true;
        int i = position / 9;
        int j = position % 9;

        if (board[i][j] != '.') {
            return solveSudoku(board, position + 1);
        }

        char originValue = board[i][j];

        char choices[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        for (char choice : choices) {
            int value = choice - '0';
            if (rows[indexOfRow(i, j)].count(value) == 0 
                && cols[indexOfCol(i, j)].count(value) == 0 
                && blks[indexOfBlk(i, j)].count(value) == 0) {

                rows[indexOfRow(i, j)].insert(value);
                cols[indexOfCol(i, j)].insert(value);
                blks[indexOfBlk(i, j)].insert(value);

                board[i][j] = choice;
                
                if (solveSudoku(board, position + 1)) {
                    return true;
                }

                rows[indexOfRow(i, j)].erase(value);
                cols[indexOfCol(i, j)].erase(value);
                blks[indexOfBlk(i, j)].erase(value);
            }
        }
        board[i][j] = originValue;
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        init(board);
        solveSudoku(board, 0);
    }
};
