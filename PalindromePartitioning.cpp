class Solution {
private:
    bool isPalindrome(string s){
        int i = 0;
        int j = s.size()-1;
        while (i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    void backtrack(string s, int index, vector<string> elem, vector<vector<string>> & result){
        if (index >= s.size()) {
            result.push_back(elem);
            return;
        }
        string cur_str = "";
        for (int i = index ; i < s.size(); i++){
            cur_str += s[i];
            if (isPalindrome(cur_str)){
                elem.push_back(cur_str);
                backtrack(s,i+1, elem, result);
                elem.pop_back();
            }
        }
        return;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> elem;
        backtrack(s, 0, elem, result);
        return result;
    }
};
