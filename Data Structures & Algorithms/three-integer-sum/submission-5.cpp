class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort the input so we have easy access to the negatives elems
        std::sort(nums.begin(), nums.end());

        // Going to run a 3 ptr approach,
        // iterate through vector w one ptr, and then a 2-ptr approach within
        std::vector<std::vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i - 1] == nums[i]) continue; // avoid duplicates

            int L = i + 1, R = nums.size() - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    // Avoid duplicate values in ans vector
                    while (L < R && nums[L] == nums[L + 1]) L++;
                    while (L < R && nums[R - 1] == nums[R]) R--;

                    ans.push_back({nums[i], nums[L], nums[R]});
                    L++;
                } else {
                    if (sum > 0) R--;
                    else L++;
                }
            }
        }
        return ans;
    }
};
