class Solution {
public:
    int characterReplacement(string s, int k) {
        // Frequency map
        std::unordered_map<char, int> hashMap; // {char, freq}
        int L = 0, longest = 0, maxFreq = 0;
        for (int R = L; R < s.size(); R++) {
            hashMap[s[R]]++;
            maxFreq = max(maxFreq, hashMap[s[R]]);
            while ((R - L + 1) - maxFreq > k) {
                hashMap[s[L]]--;
                L++;
            }
            longest = max(longest, R - L + 1);
        }
        return longest;
    }
};
