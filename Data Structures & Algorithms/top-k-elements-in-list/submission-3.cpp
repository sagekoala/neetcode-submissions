class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Solution with a maxHeap
        // Start by building a hashMap to track frequency of elems
        // {elem, frequency}
        // O(n)
        std::unordered_map<int, int> hashMap;
        for (int num : nums) hashMap[num]++;

        // Build maxHeap using pair, priority based on {frequency, element}
        // O(nlogn)
        std::priority_queue<pair<int, int>> maxHeap; 
        for (auto& [elem, freq] : hashMap) {
            maxHeap.push({freq, elem});
        }

        // Pop k most freq elements from maxHeap, O(klogn)
        std::vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return result;
    }
};
