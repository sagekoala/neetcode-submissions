class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Build queues
        std::queue<int> stdQ, sanQ;
        for (int std : students) stdQ.push(std);
        for (int san : sandwiches) sanQ.push(san);

        // Track num of preferences we have for each sandwich in stdnts arr
        std::unordered_map<int, int> prefMap;
        for (int pref : students) prefMap[pref]++;

        while (!stdQ.empty()) {
            if (prefMap[sanQ.front()] == 0) return stdQ.size();

            int pref = stdQ.front();
            stdQ.pop();
            if (pref == sanQ.front()) {
                // Student takes sandwich, exits
                prefMap[pref]--;
                sanQ.pop();
            } else {
                // Student returns to end of line
                stdQ.push(pref);
            }
        }
        return stdQ.size();
    }
};