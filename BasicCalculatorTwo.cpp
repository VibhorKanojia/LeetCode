class Solution {
private:  
    int getNum(string s){
        int val = 0;
        for (int i = 0 ; i < s.size(); i++){
            val = val*10 + (s[i]-'0');
        }
       return val; 
    }
    
    string getNext(string& s){
        string next = "";
        if (s[0] == '+' || s[0] == '-') {
            next = next+s[0];
            s = s.substr(1);
            
        }
        else{
            int index = 0;
            char c = s[index];
            while(c != '+' && c != '-' && index < s.size()){
                next=next + c;
                index++;
                c = s[index];
            }
            
            s = s.substr(index);
        }
        return next;
    }
    
    int solve(string s){
       
        if (s == "") return 0;
        int index = 0;
        char c = s[index];
        string num = "";
        
        while (c != '/' && c != '*' && index < s.size()){
            num = num + c;
            index++;
            c = s[index];
        }
        
        if (index == s.size()) return getNum(num);
        char op = c;
        index++;
        c = s[index];
        string num2 = "";
        
        while (c != '/' && c != '*' && index < s.size()){
            num2 = num2 + c;
            index++;
            c = s[index];
        }
        cout<<num2<<endl;
        if (index == s.size()){
            if (op == '/') return getNum(num)/getNum(num2);
            else if (op == '*') return getNum(num)*getNum(num2);
        }
        
        if (op == '/'){
            return solve(to_string(getNum(num)/getNum(num2))+s.substr(index));
        }
        else if (op == '*'){
            return solve(to_string(getNum(num)*getNum(num2))+s.substr(index));
        }
        
        return 0;
    }
    
public:
  
    int calculate(string s) {
        if (s.size() == 0) return 0;
        s.erase(remove(s.begin(), s.end(), ' '), s.end());
        if (s.size() == 0) return 0;
        
        int answer = 0;
        while (s != ""){
            
            string next = getNext(s);
            
            if (next == "+"){
                next= getNext(s);
                
                int num = solve(next);
                
                answer = answer + num;
                
            }
            else if (next == "-"){
                next= getNext(s);
                int num = solve(next);
                answer = answer - num;
            }
            else{
                answer = solve(next);
            }
           
        }
        return answer;
    }
};
