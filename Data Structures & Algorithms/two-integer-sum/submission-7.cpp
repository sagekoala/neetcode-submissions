class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i++) {
            int check = target - nums[i];
            if (hashMap.count(check)) return {hashMap[check], i};
            hashMap[nums[i]] = i;
        }
        return {};
    }
};
