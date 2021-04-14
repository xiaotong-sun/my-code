class Trie {
    private Trie[] childern;
    private boolean isEnd;

    /** Initialize your data structure here. */
    public Trie() {
        childern = new Trie[26];
        isEnd = false;
    }

    /** Inserts a word into the trie. */
    public void insert(String word) {
        Trie node = this;
        for (int i = 0; i < word.length(); i ++) {
            char ch = word.charAt(i);
            int index = ch - 'a';
            if (node.childern[index] == null) {
                node.childern[index] = new Trie();
            }
            
            // else {
            //     node = node.childern[index];
            // } 注意不能这样写
        
            node = node.childern[index];
        }
        node.isEnd = true;
    }

    /** Returns if the word is in the trie. */
    public boolean search(String word) {
        Trie node = searchPrefix(word);
        return node != null && node.isEnd;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    public boolean startsWith(String prefix) {
        Trie node = searchPrefix(prefix);
        return node != null;
    }

    private Trie searchPrefix(String prefix) {
        Trie node = this;
        for (int i = 0; i < prefix.length(); i ++) {
            char ch = prefix.charAt(i);
            int index = ch - 'a';
            if (node.childern[index] == null) {
                return node.childern[index];
            } else {
                node = node.childern[index];
            }
        }
        return node;
    }
}

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * boolean param_2 = obj.search(word);
 * boolean param_3 = obj.startsWith(prefix);
 */