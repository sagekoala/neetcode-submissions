class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> ans(2 * n);
        int i = 0;
        while (i < 2 * n) {
            int j = i % n;
            ans[i] = nums[j];
            i++;
        }

        return ans;
    }
};