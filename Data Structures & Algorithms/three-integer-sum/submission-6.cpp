class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Sort input to have access to negatives
        std::sort(nums.begin(), nums.end());

        std::vector<std::vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int L = i + 1, R = nums.size() - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    while (L < R && nums[L] == nums[L + 1]) L++;
                    while (L < R && nums[R] == nums[R - 1]) R--;
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
