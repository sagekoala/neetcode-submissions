class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // key= sortedStr : val= arr of original strs in the same anagram group
        std::unordered_map<std::string, std::vector<std::string>> hashMap;

        // Group
        for (std::string s : strs) {
            std::string tmp = s;
            std::sort(tmp.begin(), tmp.end());
            if (hashMap.count(tmp)) hashMap[tmp].push_back(s);
            else hashMap[tmp] = {s};
        }

        // Iterate through the hashMap
        std::vector<std::vector<std::string>> ans;
        for (auto& item : hashMap) {
            ans.push_back(item.second);
        }
        return ans;
    }
};
