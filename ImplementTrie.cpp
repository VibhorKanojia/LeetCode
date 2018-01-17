struct TrieNode{
    bool isLeaf;
    TrieNode * children[26];
    TrieNode(){
        isLeaf = 0;
        for (int i = 0 ; i < 26 ; i++){
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode * root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        int size = word.size();
        struct TrieNode * tempNode = root;
        for (int i = 0 ; i < size ; i++){
            char c = word[i];
            if (tempNode->children[c-97] == NULL){
                struct TrieNode * newNode = new TrieNode();
                tempNode->children[c-97] = newNode;
                tempNode = tempNode->children[c-97];    
            }
            else{
                tempNode = tempNode->children[c-97];    
            }
            if (i == size -1){
                tempNode->isLeaf = 1;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int size = word.size();
        struct TrieNode * tempNode = root;
        for (int i = 0 ; i < size ; i++){
            char c = word[i];
            
            if (tempNode->children[c-97] == NULL){
                return 0;
            }
            else{
                tempNode = tempNode->children[c-97];
            }
        }
        
        if (tempNode->isLeaf == 1) return 1;
        else return 0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int size = prefix.size();
        struct TrieNode * tempNode = root;
        for (int i = 0 ; i < size ; i++){
            char c = prefix[i];
            if (tempNode->children[c-97] == NULL){
                return 0;
            }
            else{
                tempNode = tempNode->children[c-97];
            }
        }
        return 1;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
