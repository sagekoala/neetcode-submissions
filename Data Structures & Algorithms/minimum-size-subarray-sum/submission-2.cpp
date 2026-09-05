class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Sliding window
        int L = 0, currSum = 0, minLen = 1e9;
        for (int R = L; R < nums.size(); R++) {
            currSum += nums[R];
            while (currSum >= target) {
                minLen = min(minLen, R - L + 1);
                currSum -= nums[L];
                L++;
            }
        }
        if (minLen == 1e9) return 0;
        else return minLen;
    }
};