class Solution {
public:
    int characterReplacement(string s, int k) {
        // Sliding window
        int L = 0, maxFreq = 0, longest = 0;
        std::unordered_map<char, int> freqMap;
        for (int R = L; R < s.size(); R++) {
            freqMap[s[R]]++;
            maxFreq = max(maxFreq, freqMap[s[R]]);

            // if length of curr window (R - L + 1) - maxFreq > k, then need to shrink window from
            // the left and reflect changes in the frequency map
            while ((R - L + 1) - maxFreq > k) {
                freqMap[s[L]]--;
                L++;
            }
            longest = max(longest, R - L + 1);
        }
        return longest;
    }
};
