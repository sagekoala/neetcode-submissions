class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Convert vectors to queues
        std::queue<int> stdQ; // {idx, preference}
        std::queue<int> sanQ;
        for (int i = 0; i < students.size(); i++) stdQ.push(students[i]);
        for (int i = 0; i < sandwiches.size(); i++) sanQ.push(sandwiches[i]);

        int maxLoops = 4 * students.size();
        int currLoops = 0;
        while (!stdQ.empty()) {
            if (currLoops == maxLoops) return stdQ.size();
            int std = stdQ.front();
            stdQ.pop();
            if (std == sanQ.front()) {
                // Student takes the sandwich
                sanQ.pop();
            } else {
                // Student goes to back of line
                stdQ.push(std);
            }
            currLoops++;
        }
        return stdQ.size();
    }
};