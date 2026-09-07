class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // K is going to track position in original arr of unique elements
        int k = 1, minVal = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > minVal) {
                nums[k] = nums[i];
                minVal = nums[i];
                k++;
            }
        }
        return k;
    }
};