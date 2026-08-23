class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int sum = 0, L = 0, resultCount = 0;
        for (int R = L; R < arr.size(); R++) {
            sum += arr[R];
            if (R - L + 1 > k) {
                sum -= arr[L];
                L++;
            }

            if (R - L + 1 == k && sum >= k * threshold) {
                resultCount++;
            }
        }
        return resultCount;
    }
};