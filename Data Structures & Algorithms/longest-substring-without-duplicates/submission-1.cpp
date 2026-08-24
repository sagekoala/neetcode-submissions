class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> hashMap;
        int L = 0, result = 0;
        for (int R = 0; R < s.size(); R++) {
            if (hashMap.count(s[R])) {
                L = max(hashMap[s[R]] + 1, L);
            }
            hashMap[s[R]] = R;
            result = max(R - L + 1, result);
        }
        return result;
    }
};
