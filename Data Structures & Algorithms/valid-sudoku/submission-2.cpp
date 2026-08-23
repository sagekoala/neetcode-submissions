class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // used vectors, ex col[colNumber][usedDigit]
        std::vector<std::vector<bool>> col(9, std::vector<bool>(10, false));
        std::vector<std::vector<bool>> row(9, std::vector<bool>(10, false));
        std::vector<std::vector<bool>> box(9, std::vector<bool>(10, false));

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                int digit = board[r][c] - '0';
                int boxId = (r/3)*3 + (c/3);
                if (row[r][digit] || col[c][digit] || box[boxId][digit]) {
                    return false;
                } else {
                    row[r][digit] = col[c][digit] = box[boxId][digit] = true;
                }
            }
        }
        return true;
    }
};
