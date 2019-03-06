# 208. Implement Trie (Prefix Tree)


class TrieNode:
    def __init__(self, x):
        self.val = x
        self.children = []

class Trie:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.root = TrieNode('')

    def insert(self, word: str) -> None:
        """
        Inserts a word into the trie.
        """
        word += '.'
        i = 0
        cur_node = self.root
        while i < len(word):
            found_next = False
            for child in cur_node.children:
                if child.val == word[i]:
                    if word[i] == '.':
                        return
                    cur_node = child
                    found_next = True
                    i += 1
                    break
            if not found_next:
                break
        while i < len(word):
            next_node = TrieNode(word[i])
            cur_node.children.append(next_node)
            cur_node = next_node
            i += 1


    def search(self, word: str) -> bool:
        """
        Returns if the word is in the trie.
        """
        word += '.'
        i = 0
        cur_node = self.root
        while i < len(word):
            found_next = False
            for child in cur_node.children:
                if child.val == word[i]:
                    if word[i] == '.':
                        return True
                    cur_node = child
                    found_next = True
                    i += 1
                    break
            if not found_next:
                return False

    def startsWith(self, prefix: str) -> bool:
        """
        Returns if there is any word in the trie that starts with the given prefix.
        """
        i = 0
        cur_node = self.root
        while i < len(prefix):
            found_next = False
            for child in cur_node.children:
                if child.val == prefix[i]:
                    cur_node = child
                    found_next = True
                    i += 1
                    break
            if not found_next:
                return False
        return True

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)


if __name__ == "__main__":
    import time
    start = time.clock()

    obj = Trie()
    obj.insert('apple')
    print(obj.search('apple'))
    print(obj.search('app'))
    print(obj.startsWith('app'))
    print(obj.startsWith('b'))


    end = time.clock()
    print('Running time: %s ms' % ((end - start) * 1000))