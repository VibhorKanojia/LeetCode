class Solution {
public:
    bool isValid(string s) {
        stack<char> buffer;
        map<char,char> matcher;
        matcher['('] = ')';
        matcher['{'] = '}';
        matcher['['] = ']';
        
        for (int i= 0 ; i < s.size(); i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                buffer.push(s[i]);
            }
            else{
                if (buffer.empty()) return 0;
                char top = buffer.top();
                if (matcher[top] == s[i]) {
                    buffer.pop();
                }
                else{
                    return 0;
                }
            }
        }
        if (buffer.empty()) return 1;
        else return 0;
    }
};
