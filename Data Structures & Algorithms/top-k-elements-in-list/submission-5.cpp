class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Capture the frequency of elemens in the vector
        std::unordered_map<int, int> hashMap;
        for (int num : nums) hashMap[num]++;

        // Build a max heap ({frequency, elem})
        std::priority_queue<pair<int, int>> pq;
        for (auto& [elem, freq] : hashMap) {
            pq.push({freq, elem});
        } 

        // Pop k times from the max heap
        std::vector<int> sol;
        for (int i = 0; i < k; i++) {
            sol.push_back(pq.top().second);
            pq.pop();
        }
        return sol;
    }
};
