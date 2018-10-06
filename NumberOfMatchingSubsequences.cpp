class Solution {
private:
    int isSubsequence(string word, string S, vector<int> count){
        int s_ptr = 0;
        int w_ptr = 0;
        for (w_ptr = 0; w_ptr < word.size() && s_ptr < S.size(); w_ptr++){
            if (count[word[w_ptr]-'a'] == 0) return 0;
            while (word[w_ptr] != S[s_ptr]) {
                count[S[s_ptr]-'a']--;
                s_ptr++;
            }
            count[word[w_ptr]-'a']--;
            s_ptr++;
        }
        if (w_ptr == word.size()) return 1;
        else return 0;
    }
    
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<int> count(26,0);
        for (int i = 0; i < S.size(); i++) count[S[i]-'a']++;
        unordered_map<string, int> hash;
        int result = 0;
        for (int i = 0; i < words.size(); i++){
            if (hash.find(words[i]) == hash.end()){
                int val = isSubsequence(words[i], S, count);
                hash.insert(pair<string,int>(words[i], val));
                result += val;
            }
            else{
                result += hash[words[i]];
            }
        }
        return result;
    }
};
