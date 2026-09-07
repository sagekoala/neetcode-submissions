class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        // Sort the input arr
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        for (int i = 0; i < nums.size() - 2; i++) {

            // Avoid positive values & duplicates for i (i.e. leftmost ptr)
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int L = i + 1, R = nums.size() - 1;
            while (L < R) {

                // Calculate sum, update ptrs
                int sum = nums[i] + nums[L] + nums[R];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[L], nums[R]});
                    L++;
                    R--;
                    while (L < R && nums[L] == nums[L - 1]) L++;
                    while (R > L && nums[R] == nums[R + 1]) R--;
                }
                else if (sum < 0) L++;
                else if (sum > 0) R--;
            }
        }
        return ans;
    }
};
