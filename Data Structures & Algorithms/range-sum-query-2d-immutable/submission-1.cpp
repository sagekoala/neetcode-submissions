class NumMatrix {
private:
    // Member variable to hold prefix sum array
    std::vector<std::vector<int>> prefixArr_; // prefixArr_ is 1 indexed

public:
    NumMatrix(vector<vector<int>>& matrix) {
        // Build the prefix array
        int ROWS = matrix.size(), COLS = matrix[0].size();
        prefixArr_ = std::vector<std::vector<int>>(ROWS + 1, std::vector<int>(COLS + 1, 0));

        for (int r = 0; r < ROWS; r++) {
            int currPrefix = 0;
            for (int c = 0; c < COLS; c++) {
                currPrefix += matrix[r][c];
                int above = prefixArr_[r][c + 1]; // prefixArr_ is 1 indexed
                prefixArr_[r + 1][c + 1] = currPrefix + above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Because prefixArr_ is 1 indexed, need to increment these ptrs
        row1++; col1++; row2++; col2++;
        int bottomRight = prefixArr_[row2][col2];
        int above = prefixArr_[row1 - 1][col2];
        int left = prefixArr_[row2][col1 - 1];
        int topLeft = prefixArr_[row1 - 1][col1 - 1];
        return bottomRight - above - left + topLeft;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */