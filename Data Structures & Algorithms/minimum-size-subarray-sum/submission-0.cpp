class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // Sliding window
        int L = 0, currSum = 0, minLen = 1e9;
        
        for (int R = L; R < nums.size(); R++) {
            currSum += nums[R];
            while (currSum >= target) {
                if (R - L + 1 < minLen) minLen = R - L + 1;
                currSum -= nums[L];
                L++;
            }
        }
        return minLen == 1e9 ? 0 : minLen;
    }
};