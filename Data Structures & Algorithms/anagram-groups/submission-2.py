class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        groups = {}
        
        for s in strs:
            # Create the universal key by sorting the string
            key = ''.join(sorted(s))
            
            # If the key isn't in our map yet, create an empty list for it
            if key not in groups:
                groups[key] = []
                
            # Append the original string to its matching key
            groups[key].append(s)
            
        return list(groups.values())