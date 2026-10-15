class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        # Start a pointer at the very end of the string
        i = len(s) - 1
        length = 0
        
        # Step 1: Skip any trailing spaces at the end of the string
        while i >= 0 and s[i] == ' ':
            i -= 1
            
        # Step 2: Count the characters of the last word moving backwards
        while i >= 0 and s[i] != ' ':
            length += 1
            i -= 1
            
        # Return the final counted length
        return length