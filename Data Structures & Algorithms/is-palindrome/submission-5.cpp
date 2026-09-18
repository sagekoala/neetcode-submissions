class Solution {
public:
    std::string convertInput(std::string& s) {
        std::string tmp = "";
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') {
                tmp += c + 32;
            } else if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
                tmp += c;
            } 
        }
        return tmp;
    }

    bool isPalindrome(string s) {
        std::string inp = convertInput(s);

        // Two pointer approach
        int L = 0, R = inp.size() - 1;
        while (L < R) {
            if (inp[L] != inp[R]) return false; 
            L++;
            R--;
        }
        return true;
    }
};
