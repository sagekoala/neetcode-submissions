class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> hashSet(nums.begin(), nums.end());
        int longest = 0;
        for (int num : hashSet) {
            // If num - 1 NOT in hashSet, then num is start of seq
            if (!hashSet.count(num - 1)) {
                int currSeq = 0;
                while (hashSet.count(num)) {
                    currSeq++;
                    num++;
                }
                if (currSeq > longest) longest = currSeq;
            }
        }
        return longest;
    }
};
