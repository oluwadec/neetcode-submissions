class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            // Sort the array on every single turn
            sort(stones.begin(), stones.end());
            
            int heaviest = stones.back();
            stones.pop_back();
            
            int secondHeaviest = stones.back();
            stones.pop_back();
            
            if (heaviest != secondHeaviest) {
                stones.push_back(heaviest - secondHeaviest);
            }
        }
        
        return stones.empty() ? 0 : stones[0];
    }
};