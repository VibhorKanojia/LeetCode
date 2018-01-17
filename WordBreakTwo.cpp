class Solution {
private:
    
    vector<string> combine( vector<string> vec, string word){
        for (int i =0 ; i < vec.size(); i++){
            vec[i] = (vec[i] =="")? word: vec[i]+" "+word;   
        }
        return vec;
    }
    
    vector<string> fillDP(string s, vector<string> & wordDict, unordered_map<string, vector<string>> & memo){
        if (memo.find(s) != memo.end()) return memo[s];
        vector<string> result;
        for (int i= s.size()-1; i >= 0; i--){
           string word = s.substr(i);
           if (find(wordDict.begin(),wordDict.end(), word) != wordDict.end()){
                vector<string> temp = combine( fillDP(s.substr(0,i), wordDict, memo), word);
               result.insert(result.end(), temp.begin(), temp.end());
           }
        }
        memo.insert(pair<string,vector<string>>(s,result));
        return memo[s];
    }
    
public:   
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_map<string, vector<string>> memo;
        vector<string> temp;
        temp.push_back("");
        memo.insert(pair<string,vector<string>>("",temp));
        return fillDP(s, wordDict, memo);
    }
};
