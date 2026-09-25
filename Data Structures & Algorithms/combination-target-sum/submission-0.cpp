class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(candidates, target, 0, current, result);
        return result;
    }

private:
    void backtrack(vector<int>& candidates, int remaining, int start,
                    vector<int>& current, vector<vector<int>>& result) {
        if (remaining == 0) {
            result.push_back(current);
            return;
        }
        if (remaining < 0) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            current.push_back(candidates[i]);
            // not i+1, since we can reuse the same element
            backtrack(candidates, remaining - candidates[i], i, current, result);
            current.pop_back();
        }
    }
};