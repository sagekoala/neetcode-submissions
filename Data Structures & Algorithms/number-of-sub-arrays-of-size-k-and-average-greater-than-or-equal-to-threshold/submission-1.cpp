class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int L = 0;
        int currSum = 0;
        int result = 0;
        for (int R = L; R < arr.size(); R++) {
            if (R - L + 1 > k) {
                currSum -= arr[L];
                L++;
            }

            currSum += arr[R];

            if ((currSum / k) >= threshold && (R - L + 1) == k) result++;
        }
        return result;
    }
};