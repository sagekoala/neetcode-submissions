class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        // input => nums = {1,1,0,1,1,1}
        int curr = 0, maxV = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) curr++;
            else {
                if (curr > maxV) maxV = curr;
                curr = 0;
            }
        }
        return max(maxV, curr);
    }
};