//REALLY GOOD QUESTION
class Solution {
public:
    string removeDuplicateLetters(string s) {
        //Will act as a stack
        string result = "";
        vector<int> count(26,0);
        vector<int> visited(26,0);
        for (int i = 0 ; i < s.size(); i++) count[s[i]-'a']++;
        for (int i = 0 ; i < s.size(); i++){
            count[s[i]-'a']--;
            if (visited[s[i]-'a']) continue;
            while(!result.empty() && result.back() > s[i] && count[result.back()-'a']){
                visited[result.back()-'a'] = 0;
                result.pop_back();
            }
            result.push_back(s[i]);
            visited[s[i]-'a'] = true;
        }
        return result;
    }
};
