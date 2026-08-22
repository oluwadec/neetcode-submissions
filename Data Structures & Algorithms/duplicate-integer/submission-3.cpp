#include <vector>
#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        for (int num : nums) {
            // insert().second returns false if the element was already in the set
            if (!seen.insert(num).second) {
                return true;
            }
        }
        return false;
    }
};