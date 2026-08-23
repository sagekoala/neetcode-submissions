class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Bucket sort solution
        // Capture frequency of each elem w a hashMap
        std::unordered_map<int, int> hashMap;
        for (int num : nums) hashMap[num]++;

        // 2d vector, indeces are frequencies, values are vectors of elements
        // corresponding to the indeces frequency
        std::vector<std::vector<int>> freqVec(nums.size() + 1);
        for (auto& [elem, freq] : hashMap) {
            freqVec[freq].push_back(elem);
        }

        std::vector<int> result;
        for (int i = freqVec.size() - 1; i >= 0; --i) {
            for (int j = 0; j < freqVec[i].size(); j++) {
                result.push_back(freqVec[i][j]);
                if (result.size() == k) return result;
            }
        }   
        return {};
    }
};
