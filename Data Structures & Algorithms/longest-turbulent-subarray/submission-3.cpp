class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        bool greater = false, lesser = false;
        int L = 0, longest = 1;
        for (int R = L + 1; R < arr.size(); R++) {
            int curr = arr[R], prev = arr[R - 1];
            if (curr > prev && !greater) {
                greater = true;
                lesser = false;
            }
            else if (curr < prev && !lesser) {
                lesser = true;
                greater = false;
            }
            else {
                L = R - 1;
                if (arr[R] < arr[L]) {
                    lesser = true;
                    greater = false;
                } else if (arr[R] > arr[L]) {
                    greater = true;
                    lesser = false;
                } else {
                    L = R;
                    greater = lesser = false;
                }
            }
            longest = max(longest, R - L + 1);
        }
        return longest;
    }
};