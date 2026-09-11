class NumMatrix {
private:
    std::vector<std::vector<int>> prefixArr_;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int ROWS = matrix.size(), COLS = matrix[0].size();
        prefixArr_ = std::vector<std::vector<int>>(ROWS + 1, std::vector<int>(COLS + 1, 0));

        // Populate prefixArr_ -> O(n^2)
        for (int r = 0; r < ROWS; r++) {
            int prefix = 0;
            for (int c = 0; c < COLS; c++) {
                prefix += matrix[r][c];
                int above = prefixArr_[r][c + 1];
                prefixArr_[r + 1][c + 1] = prefix + above;
            }
        } 
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // prefixArr_ is 1 indexed
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