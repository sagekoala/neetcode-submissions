class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Kadane's algo
        int maxSum = 0, curr = 0, largest = nums[0];
        for (int num : nums) {
            if (num > largest) largest = num;
            curr += num;
            curr = max(curr, num);
            maxSum = max(curr, maxSum); 
        }
        if (largest < 0) return largest;
        return maxSum;
    }
};
