class Solution {
   public:
    int maxTurbulenceSize(vector<int>& arr) {
        int L = 0;
        int ans = 1;
        for (int R = L + 1; R < arr.size(); R++) {
            if (arr[R] == arr[R - 1]) {
                L = R;
            } else if (R >= 2) {
                if ((arr[R] > arr[R - 1] && arr[R - 1] > arr[R - 2]) ||
                    (arr[R] < arr[R - 1] && arr[R - 1] < arr[R - 2])) {
                    L = R - 1;
                }
            }
            ans = max(ans, R - L + 1);
        }
        return ans;
    }
};