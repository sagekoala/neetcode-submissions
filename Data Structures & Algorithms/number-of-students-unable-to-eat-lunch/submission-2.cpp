class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int prefZero = 0, prefOne = 0;
        for (int std : students) {
            if (std == 0) prefZero++;
            else prefOne++;
        }

        for (int san : sandwiches) {
            if (san == 0 && prefZero > 0) prefZero--;
            else if (san == 1 && prefOne > 0) prefOne--;
            else return prefZero + prefOne;
        }
        return prefZero + prefOne;
    }
};