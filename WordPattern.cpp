class Solution {
private:
    vector<string> split(string sentence, string delimiter){
        vector<string> wordList;
        int index = sentence.find(delimiter);
        while(index != -1){
            string word = sentence.substr(0,index);
            sentence = sentence.substr(index+1,sentence.size());
            wordList.push_back(word);
            index = sentence.find(delimiter);
        }
        wordList.push_back(sentence);
        return wordList;
    }
    
public:
    bool wordPattern(string pattern, string str) {
        if (pattern.size() == 0 || str.size() ==0) return false;
        unordered_map<char,string> mapper;
        unordered_map<string,bool> dictionary;
        unordered_map<char,string>::iterator it;
        vector<string> wordList = split(str, " ");
        if (pattern.size() != wordList.size()) return false;
        for (int i = 0 ; i < pattern.size(); i++){
            char c = pattern[i];
            int index = str.find(" ");
            string word = str.substr(0,index);
            str = str.substr(index+1,str.size());
            it = mapper.find(c);
            if (it == mapper.end()){
                if (dictionary.find(word) != dictionary.end()) return false;
                else {
                    mapper.insert(pair<char,string>(c, word));
                    dictionary.insert(pair<string,bool>(word,true));
                }
            }
            else{
                if (word != it->second) return false; 
            }
        }
        return true;
    }
};
