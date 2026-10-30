class Solution(object):
    def longestConsecutive(self, nums):
        mp = {}
        longest = 0
        for n in nums:
            if n not in mp:
                left = mp.get(n - 1, 0)
                right = mp.get(n + 1, 0)

                length = left + right + 1
                mp[n] = length 

                longest = max(longest, length)

                mp[n - left] = length
                mp[n + right] = length
        return longest
        """
        :type nums: List[int]
        :rtype: int
        """
             