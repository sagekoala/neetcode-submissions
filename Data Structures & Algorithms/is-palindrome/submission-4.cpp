class Solution {
private: 
    std::string convertStr(std::string s) {
        std::string str = "";
        for (char c : s) {
            if (c >= 'A' && c <= 'Z') str += (c + 32);
            else if (c >= 'a' && c <= 'z') str += c;
            else if (c >= '0' && c <=  '9') str += c;
        }
        return str;
    }
public:
    bool isPalindrome(string s) {
        // Two pointer approach
        std::string cStr = convertStr(s);
        int L = 0, R = cStr.size() - 1;
        while (L < R) {
            if (cStr[L] != cStr[R]) return false;
            L++;
            R--;
        }
        return true;
    }
};
