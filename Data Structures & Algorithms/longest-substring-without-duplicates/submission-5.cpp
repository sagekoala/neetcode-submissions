class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Sliding window approach,
        // track seen chars in hashMap, {char, index}
        // if you find char youve seen, move L to index of prev occurence of char + 1
        // update longest substring dynamically
        std::unordered_map<char, int> seenMap;
        int L = 0, longest = 0;
        for (int R = L; R < s.size(); R++) {
            if (seenMap.count(s[R]) && L <= seenMap[s[R]] + 1) {
                L = seenMap[s[R]] + 1;
            }
            seenMap[s[R]] = R;
            longest = max(longest, R - L + 1);
        }
        return longest;
    }
};
