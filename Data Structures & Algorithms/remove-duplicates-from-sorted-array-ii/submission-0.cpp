class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        std::unordered_map<int, int> freqMap;
        int k = 0, minVal = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            freqMap[nums[i]]++;
            if (freqMap[nums[i]] <= 2) {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};