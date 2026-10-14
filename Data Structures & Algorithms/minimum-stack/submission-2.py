class MinStack(object):

    def __init__(self):
        # We use two stacks:
        # 1. main_stack -> stores all the actual values, like a normal stack
        # 2. min_stack  -> stores the minimum value at each point in time
        #    (so min_stack[i] = the smallest value among main_stack[0..i])
        self.main_stack = []
        self.min_stack = []

    def push(self, val):
        """
        :type val: int
        :rtype: None
        """
        # Always push the value onto the main stack (normal stack behavior)
        self.main_stack.append(val)

        # Now figure out what the "current minimum" is after adding this value
        if not self.min_stack:
            # If min_stack is empty, this new value is the only value so far,
            # so it's automatically the minimum
            current_min = val
        else:
            # Otherwise, compare the new value with the last known minimum
            # and keep whichever is smaller
            current_min = min(val, self.min_stack[-1])

        # Push that minimum onto min_stack.
        # This way, min_stack[-1] ALWAYS tells us the minimum of everything
        # currently in main_stack, no matter how many pops/pushes happen.
        self.min_stack.append(current_min)

    def pop(self):
        """
        :rtype: None
        """
        # Remove the top value from both stacks at the same time.
        # Since they were pushed together, they stay in sync.
        self.main_stack.pop()
        self.min_stack.pop()

    def top(self):
        """
        :rtype: int
        """
        # The top of the main stack is just the last element added
        return self.main_stack[-1]

    def getMin(self):
        """
        :rtype: int
        """
        # The top of min_stack is always the minimum of the current stack
        # (we maintained this invariant every time we pushed)
        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()