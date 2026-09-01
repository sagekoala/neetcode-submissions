class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr = 0, sum = 0;
        int largestElem = -1e9;
        for (int num : nums) {
            if (num > largestElem) largestElem = num;
            curr += num;
            curr = max(curr, num);
            sum = max(curr, sum);
        }
        if (largestElem < 0) return largestElem;
        return sum;
    }
};
