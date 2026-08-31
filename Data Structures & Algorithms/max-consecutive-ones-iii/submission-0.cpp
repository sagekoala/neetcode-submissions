class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        // Sliding window
        int L = 0, result = 0;
        for (int R = L; R < nums.size(); R++) {
            k -= (nums[R] == 0 ? 1 : 0);
            while (k < 0) {
                k += (nums[L] == 0 ? 1 : 0);
                L++;
            }
            result = max(R - L + 1, result);
        }
        return result;
    }
};