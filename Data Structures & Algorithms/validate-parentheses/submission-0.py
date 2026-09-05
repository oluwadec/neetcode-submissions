class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        pairs = {')': '(', ']': '[', '}': '{'}

        for char in s:
            if char in pairs:
                # Closing bracket - check if it matches the top of the stack
                if not stack or stack.pop() != pairs[char]:
                    return False
            else:
                # Opening bracket - push onto stack
                stack.append(char)

        # Valid only if all brackets were matched (stack is empty)
        return not stack