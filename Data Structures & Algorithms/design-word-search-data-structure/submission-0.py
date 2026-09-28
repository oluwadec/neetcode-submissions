class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end_of_word = False

class WordDictionary:

    def __init__(self):
        """
        Initializes the data structure.
        """
        self.root = TrieNode()

    def addWord(self, word: str) -> None:
        """
        Adds a word into the data structure.
        Time Complexity: O(M), where M is the length of the word.
        Space Complexity: O(M) to insert a new word.
        """
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
        node.is_end_of_word = True

    def search(self, word: str) -> bool:
        """
        Returns true if the word is in the data structure. A dot '.' can match any letter.
        Time Complexity: O(M) for well-defined words. Up to O(26^M) for words containing many dots '.'.
        Space Complexity: O(M) system stack space for recursion.
        """
        def dfs(index: int, node: TrieNode) -> bool:
            # Base case: reached the end of the search word
            if index == len(word):
                return node.is_end_of_word
            
            char = word[index]
            
            if char == '.':
                # Wildcard matching: check all possible existing children nodes
                for child in node.children.values():
                    if dfs(index + 1, child):
                        return True
                return False
            else:
                # Standard matching: check if the exact character exists
                if char not in node.children:
                    return False
                return dfs(index + 1, node.children[char])

        return dfs(0, self.root)
