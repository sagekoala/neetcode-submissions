class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        
        std::unordered_map<char, int> hashMap;
        for (char c : s) hashMap[c]++;
        for (char c : t) {
            hashMap[c]--;
            if (hashMap[c] < 0) return false;
        }
        return true;
    }
};
