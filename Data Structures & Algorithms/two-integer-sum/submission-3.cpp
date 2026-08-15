class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> myMap;
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            if(myMap.count(complement)){
                return {myMap[complement], i};
            }
            myMap[nums[i]] =  i;
        }
        return {};
    }
};
