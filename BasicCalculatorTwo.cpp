class Solution {
public:
    inline int getNum(string s, int & index){
        int num = 0;
        while (s[index] == ' ') {
            index++;
        }
        for (int i = index ; i < s.size(); i++){
            if (isdigit(s[i])){
                num = num*10 + (s[i]-'0');
            }
            else break;
        }
       index--;
       return num; 
    }
    
    int calculate(string s) {
        s = '+' + s + '+';
        int answer = 0;
        int pre_val = 0;
        for (int i = 0; i < s.size(); i++){
            while (s[i] == ' ') {
                i++;
            }
            char op = s[i];
            if (op == '+' || op == '-'){
                answer += pre_val;
                i++;
                pre_val = getNum(s,i);
                pre_val *= (op == '+')?1:-1; 
            }
            else if (op == '/'){
                i++;
                pre_val /= getNum(s,i);
            }
            
            else if (op == '*'){
                i++;
                pre_val *= getNum(s,i);
            }
        }
            
        return answer;
    }
};
