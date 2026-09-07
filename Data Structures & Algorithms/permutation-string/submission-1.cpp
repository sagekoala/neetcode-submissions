class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    
        // Sort s1
        std::sort(s1.begin(), s1.end());

        // Size of window 
        int windowSize = s1.size();
        int L = 0, R = windowSize - 1;
        while (L <= R && R < s2.size() && R - L + 1 == windowSize) {
            std::string tmp = s2.substr(L, windowSize);
            std::sort(tmp.begin(), tmp.end());
            if (tmp == s1) return true;
            L++;
            R++;
        }
        return false;
    }
};
