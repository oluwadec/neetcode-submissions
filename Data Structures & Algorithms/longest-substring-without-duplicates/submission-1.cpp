class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s[right];
            if (charIndex.count(c) && charIndex[c] >= left) {
                left = charIndex[c] + 1;
            }
            charIndex[c] = right;
            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};