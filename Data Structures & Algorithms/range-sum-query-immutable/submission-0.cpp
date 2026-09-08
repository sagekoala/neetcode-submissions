class NumArray {
public:
    // Member variable
    std::vector<int> prefix_;

    NumArray(vector<int>& nums) {
        int total = 0;
        for (int n:nums) {
            total += n;
            prefix_.push_back(total);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return prefix_[right];
        else return prefix_[right] - prefix_[left - 1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */ 