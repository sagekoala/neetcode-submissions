class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        std::unordered_map<int, int> hashMap; // {element, index}
        for (int i = 0; i < nums.size(); i++) {
            if (hashMap.count(nums[i]) && abs(i - hashMap[nums[i]]) <= k) return true;
            hashMap[nums[i]] = i;
        }
        return false;
    }
};