class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        // 1. Count element frequencies
        std::unordered_map<int, int> countMap;
        for (int num : nums) {
            countMap[num]++;
        }

        // 2. Create buckets where index = frequency, value = list of numbers
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (const auto& [num, freq] : countMap) {
            buckets[freq].push_back(num);
        }

        // 3. Iterate backwards from highest possible frequency
        std::vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
            for (int num : buckets[i]) {
                result.push_back(num);
                if (result.size() == k) break;
            }
        }

        return result;
    }
};