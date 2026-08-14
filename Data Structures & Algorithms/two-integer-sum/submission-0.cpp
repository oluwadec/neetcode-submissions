#include <vector> // Gives us std::vector (dynamic arrays)
#include <unordered_map> // Gives us std::unordered_map (Hash Map)
class Solution {
public:
    std::vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> mp;

        for (int i=0; i < nums.size(); ++i) {

            int currentNum = nums[i];
            int diff = target - currentNum;

            if (mp.count(diff)) {

                return {mp[diff], i};
            }
            mp[currentNum] = i;
        }
        return{};
    }
};
