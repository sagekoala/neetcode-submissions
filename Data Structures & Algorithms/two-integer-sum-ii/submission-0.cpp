class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // Two pointer solution
        int L = 0, R = numbers.size() - 1;
        while (L < R) {
            int check = numbers[L] + numbers[R];
            if (check > target) R--;
            else if (check < target) L++;
            else return {L + 1, R + 1};
        }  
    }
};
