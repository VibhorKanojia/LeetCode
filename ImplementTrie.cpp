struct TrieNode{
    bool isLeaf;
    char val;
    vector<TrieNode *> children;
    TrieNode(char val){
        isLeaf = false;
        this->val = val;
        children.resize(26);
    }
};

class Trie {
private:
    TrieNode * root;    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode('#');
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * node = root;
        for (int i =0 ; i < word.size(); i++){
            char c = word[i];
            if ((node->children)[c-'a'] == NULL){
                (node->children)[c-'a'] = new TrieNode(c);
            }
            node = (node->children)[c-'a'];
        }
        node->isLeaf = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * node = root;
        for (int i =0 ; i < word.size(); i++){
            char c = word[i];
            if ((node->children)[c-'a'] == NULL) return false;
            node = (node->children)[c-'a'];
        }
        return (node->isLeaf);
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * node = root;
        for (int i =0 ; i < prefix.size(); i++){
            char c = prefix[i];
            if ((node->children)[c-'a'] == NULL) return false;
            node = (node->children)[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
