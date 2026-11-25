class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // Create a hashMap to store / read vals in O(1)
        std::unordered_set<int> s;
        for (int num : nums) {
            if (!s.insert(num).second) return true;
        }
        return false;
    }
};