class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        std::vector<int> ans = nums;
        for (int num : nums) ans.push_back(num);
        return ans;
    }
};