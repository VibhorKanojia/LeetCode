class Solution {
private:
    void fill (bitset<26> & map, string word){
        for (int i = 0 ; i < word.size() ; i++){
            map[word[i]-'a'] = 1;
        }
    }
public:
    int maxProduct(vector<string>& words) {
        int maxProd = 0;
        
        for (int i =0 ; i < words.size(); i++){
            bitset<26> word1Map;
            fill(word1Map,words[i]);
            for (int j = i+1; j < words.size(); j++){
                bitset<26> word2Map;
                fill(word2Map,words[j]);
                int prod = words[i].size() * words[j].size();
                if ((word1Map & word2Map) == 0) maxProd = max(maxProd, prod);
            }
        }
        return maxProd;
    }
};
