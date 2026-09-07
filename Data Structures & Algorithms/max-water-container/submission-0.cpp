class Solution {
public:
    int maxArea(vector<int>& heights) {
        int L = 0, R = heights.size() - 1;
        int maxWater = 0; 
        while (L < R) {
            // Update max water
            int h = min(heights[L], heights[R]);
            int w = R - L;
            if (h * w > maxWater) maxWater = h * w;

            // Update pointers, increment/decrement the ptr to shortest bar
            if (heights[L] < heights[R]) L++;
            else if (heights[L] > heights[R]) R--;
            else L++;
        }
        return maxWater;
    }
};
