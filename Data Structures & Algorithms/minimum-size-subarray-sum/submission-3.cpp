class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0, sum = 0, minSize = 1e9;
        for (int R = L; R < nums.size(); R++) {
            sum += nums[R];

            // Shrink window from left, update minSize variable for window that meets
            // statment requirement
            while (sum >= target) {
                minSize = min(minSize, R - L + 1);
                sum -= nums[L];
                L++;
            }
        }
        if (minSize == 1e9) return 0;
        return minSize;
    }
};