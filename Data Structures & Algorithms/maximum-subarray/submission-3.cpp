class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0; // Going to represent window between R and L
        int maxSum = nums[0];
        for (int num : nums) {
            currSum = max(currSum, 0);
            currSum += num;
            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};
