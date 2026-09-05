class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        count = {}  # frequency of characters in the current window
        left = 0
        max_freq = 0  # highest frequency of any single character seen in any window so far
        max_length = 0

        for right in range(len(s)):
            char = s[right]
            count[char] = count.get(char, 0) + 1
            max_freq = max(max_freq, count[char])

            # Window size - count of most frequent char = number of chars needing replacement
            window_size = right - left + 1
            if window_size - max_freq > k:
                # Too many replacements needed, shrink window from the left
                count[s[left]] -= 1
                left += 1

            # Recompute window size after potential shrink
            max_length = max(max_length, right - left + 1)

        return max_length