class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            // ans[i >> 1] gives the count of 1s for i / 2
            // (i & 1) adds 1 if i is odd, or 0 if i is even
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};