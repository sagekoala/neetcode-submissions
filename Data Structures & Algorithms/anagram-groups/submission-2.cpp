class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> hashMap;
        for (std::string str : strs) {
            std::string tmp = str;
            sort(tmp.begin(), tmp.end());
            hashMap[tmp].push_back(str);
        }

        std::vector<std::vector<std::string>> result;
        for (auto& [group, elems] : hashMap) {
            result.push_back(elems);
        }
        return result;
    }
};
