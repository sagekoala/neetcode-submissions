class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> mapS, mapT;
        for (char c : s) mapS[c]++;
        for (char c : t) mapT[c]++;

        return mapS == mapT;
    }
};
