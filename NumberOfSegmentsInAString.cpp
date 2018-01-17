class Solution {
private:
    vector<string> split(string sentence, string delimiter){
        vector<string> wordList;
        int index = sentence.find(delimiter);
        while(index != -1){
            string word = sentence.substr(0,index);
            sentence = sentence.substr(index+1,sentence.size());
            if (word != "") wordList.push_back(word);
            index = sentence.find(delimiter);
        }
        if (sentence != "") wordList.push_back(sentence);
        return wordList;
    }
    
public:
    int countSegments(string s) {
        if (s == "") return 0;
        vector<string> wordList = split(s, " ");
        return wordList.size();
    }
};
