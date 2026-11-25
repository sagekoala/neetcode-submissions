class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        // Key is string, val is vec<str>
        std::unordered_map<std::string, std::vector<std::string>> hashMap;
        
        // Iterate list, treat sorted str as key, push original str as val
        for (std::string s : strs) {
            std::string tmp = s;
            std::sort(tmp.begin(), tmp.end());
            hashMap[tmp].push_back(s);
        }

        // Iterate through the unordered map, pushing the values into the solution 2d vec
        std::vector<std::vector<std::string>> sol;
        for (auto& block : hashMap) {
            sol.push_back(block.second);
        }
        return sol;
    }
};
