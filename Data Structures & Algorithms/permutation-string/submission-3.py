class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        len1, len2 = len(s1), len(s2)

        if len1 > len2:
            return False

        # Frequency count of characters in s1
        s1_count = [0] * 26
        window_count = [0] * 26

        # Initialize counts for s1 and the first window of s2
        for i in range(len1):
            s1_count[ord(s1[i]) - ord('a')] += 1
            window_count[ord(s2[i]) - ord('a')] += 1

        if s1_count == window_count:
            return True

        # Slide the window across the rest of s2
        for i in range(len1, len2):
            # Add the new character entering the window
            window_count[ord(s2[i]) - ord('a')] += 1

            # Remove the character leaving the window (leftmost of previous window)
            left_char = s2[i - len1]
            window_count[ord(left_char) - ord('a')] -= 1

            # Compare frequency counts
            if s1_count == window_count:
                return True

        return False