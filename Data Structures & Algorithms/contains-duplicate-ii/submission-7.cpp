class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Using a sliding window and kadane's algo
        std::unordered_set<int> window; // window size <= k
        int L = 0;
        window.insert(nums[0]);
        for (int R = L + 1; R < nums.size(); R++) {
            if (R - L > k) { // window got too big, remove leftmost val from window
                window.erase(nums[L]);
                L++;
            }

            if (window.count(nums[R])) return true;
            window.insert(nums[R]);
        }
        return false;
    }
};