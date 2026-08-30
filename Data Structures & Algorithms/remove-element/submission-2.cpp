class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int leftPtr = 0;
        for (int num : nums) {
            if (num != val) {
                nums[leftPtr] = num;
                leftPtr++;
            }
        }
        return leftPtr;
    }
};