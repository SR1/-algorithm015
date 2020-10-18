class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        unordered_set<int> forbidColumns;
        unordered_set<int> forbidPies;
        unordered_set<int> forbidNas;

        solve(result, board, 0, forbidColumns, forbidPies, forbidNas);

        return result;
    }
private:
    void solve(vector<vector<string>>& result,
               vector<string>& board,
               int row,
               unordered_set<int>& forbidColumns,
               unordered_set<int>& forbidPies,
               unordered_set<int>& forbidNas
    ) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }

        for (int column = 0; column < board.size(); column++) {
            if (forbidColumns.find(column) == forbidColumns.end() 
                && forbidPies.find(column + row) == forbidPies.end() 
                && forbidNas.find(column - row) == forbidNas.end()) {
                forbidColumns.insert(column);
                forbidPies.insert(column + row);
                forbidNas.insert(column - row);

                board[row][column] = 'Q';
                solve(result, board, row + 1, forbidColumns, forbidPies, forbidNas);
                board[row][column] = '.';

                forbidNas.erase(column - row);
                forbidPies.erase(column + row);
                forbidColumns.erase(column);
            }
        }
    }
};
