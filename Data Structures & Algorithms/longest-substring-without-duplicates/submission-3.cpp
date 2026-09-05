class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> hashMap; // {character, index};
        int L = 0, longest = 0;
        for (int R = L; R < s.size(); R++) {
            if (hashMap.count(s[R]) && L <= hashMap[s[R]]) {
                // Move L one index past first occurrence of s[R]
                L = hashMap[s[R]] + 1;
            }
            hashMap[s[R]] = R;
            longest = max(longest, R - L + 1);
        }
        return longest;
    }
};
