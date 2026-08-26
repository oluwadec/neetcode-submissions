class Solution:
    def longestConsecutive(self, nums: list[int]) -> int:
        # Convert list to a set for O(1) membership lookups
        numSet = set(nums)
        longest = 0

        for n in numSet:
            # Check if 'n' is the start of a sequence
            if (n - 1) not in numSet:
                length = 1
                
                # Keep checking for the next numbers in sequence
                while (n + length) in numSet:
                    length += 1
                
                # Update our longest sequence record
                longest = max(length, longest)

        return longest