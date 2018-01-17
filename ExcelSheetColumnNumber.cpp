class Solution {
private: 
    int toInt(char c){
        return (int)(c-64);
    }
public:
    int titleToNumber(string s) {
        int num = 0;
        for (int i = 0 ; i  < s.size() ; i++){
            num = num*26 + toInt(s[i]);
        }
        return num;
    }
};
