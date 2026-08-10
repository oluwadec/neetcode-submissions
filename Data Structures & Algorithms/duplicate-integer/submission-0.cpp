#include <vector>
#include <unordered_set>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // Step 1: Create our blank checklist
        std::unordered_set<int> seen;

        // step 2: Look at each number in the array one by one
        for (int num : nums) {

            // Step 3: Is this number already on our checklist?
            if (seen.count(num) > 0) {
                return true; // We found a repeat!
            }
            // Step 4: If not, add it to the checklist and keep going
            seen.insert(num);
        }
        
        // Step 5: If we finish checking every number and found no repeats
        return false;
    }
};