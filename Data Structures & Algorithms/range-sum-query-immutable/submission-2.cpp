class NumArray {
public:
    // Member variable to hold the prefix arr
    std::vector<int> prefix_;

    NumArray(vector<int>& nums) {
        // Build the prefix arr
        int total = 0;
        for (int n : nums) {
            total += n;
            prefix_.push_back(total);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return prefix_[right];
        return prefix_[right] - prefix_[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */