struct TrieNode{
    int val;
    bool isLeaf;
    vector<TrieNode *> array;
    TrieNode(int val){
        this->val = val;
        isLeaf = false;
        array.resize(256,NULL);
    }
};

class MapSum {
private:
    TrieNode * root;
    unordered_map<string, int> mapper;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode(0);
    }
    
    void insert(string key, int val) {
        auto it = mapper.find(key);
        if (it == mapper.end()){
            mapper.insert(pair<string,int>(key,val));
            TrieNode * node = root;
            node->val += val;
            for (int i = 0 ; i < key.size(); i++){
                if ((node->array)[key[i]] == NULL){
                    (node->array)[key[i]] = new TrieNode(val);
                    node = (node->array)[key[i]];
                }
                else{
                    (node->array)[key[i]]->val +=val;
                    node = (node->array)[key[i]];
                }
            }
            node->isLeaf = true;
        }
        else{
            int pre_val = it->second;
            it->second = val;
            TrieNode * node = root;
            node->val  += val - pre_val;
            for (int i = 0 ; i < key.size(); i++){
                (node->array)[key[i]]->val += val - pre_val;
                node = (node->array)[key[i]];
            }
            node->isLeaf = true;       
        }
        return;
    }
    
    int sum(string prefix) {
        TrieNode * node =root;
        for (int i =0 ; i < prefix.size(); i++){
            if ((node->array)[prefix[i]] == NULL) return 0;
            node = (node->array)[prefix[i]];
        }
        return node->val;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */
