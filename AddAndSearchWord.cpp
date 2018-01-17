struct TrieNode{
    
    TrieNode * array[26];
    bool isLeaf;
    TrieNode(){
        for (int i = 0 ; i < 26; i++) array[i] = NULL;      
        isLeaf = false;
    }
};

class WordDictionary {
private:
    TrieNode * root;
    
    bool searchHelper(string word, int index, TrieNode * root){
        if (root == NULL) return false;
        TrieNode * node = root;
        for (int i = index ; i < word.size(); i++){
            if (word[i] != '.'){
                int pos = word[i] - 'a';
                if (((node->array)[pos]) == NULL) return false;
                node = ((node->array)[pos]);
            }
            else{
                for (int j = 0 ; j < 26 ; j++){
                    if (searchHelper(word, i+1,(node->array)[j])) return true;
                }
                return false;
            }
        }
        return (node->isLeaf);
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
        for (int i = 0 ; i < 26 ; i++) root->array[i] = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode * node = root;
        for (int i = 0 ; i < word.size(); i++){
            int index = word[i] - 'a';
            if (((node->array)[index]) == NULL) ((node->array)[index]) = new TrieNode();
            node = ((node->array)[index]);
        }
        node->isLeaf = 1;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchHelper(word,0,root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
