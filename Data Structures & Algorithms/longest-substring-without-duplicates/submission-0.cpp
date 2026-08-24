class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> hashMap; // {char, index}
        int L = 0, currLen = 0, maxLen = 0;
        for (int R = 0; R < s.size(); R++) {
            if (hashMap.count(s[R])) {
                int pos = hashMap[s[R]]; // pos of prev occurence of s[R]
                while (L < pos + 1) {
                    hashMap.erase(s[L]);
                    L++;
                }
                hashMap[s[R]] = R;
                currLen = R - L + 1;
                if (currLen > maxLen) maxLen = currLen;
            } else {
                hashMap[s[R]] = R;
                currLen++;
                if (currLen > maxLen) maxLen = currLen;
            }
        }
        return maxLen;
    }
};
