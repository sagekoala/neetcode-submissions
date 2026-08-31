class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Two cases:
        // If wraparound -> min sum array is inbetween, i.e. max sum array is wrapped
        // if not wrapround -> maxSum is a subarray within input array bounds
        int total = 0;
        int currMin = 0, minSum = 1e9;
        int currMax = 0, maxSum = -1e9;
        for (int num : nums) {
            total += num;

            currMin = min(currMin + num, num);
            minSum = min(currMin, minSum);
            currMax = max(currMax + num, num);
            maxSum = max(currMax, maxSum);
        }

        if (maxSum < 0) return maxSum;
        else return max(total - minSum, maxSum);
    }
};