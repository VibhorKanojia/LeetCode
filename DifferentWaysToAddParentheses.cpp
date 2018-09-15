class Solution {
private:
    bool isNumber(string input){
        for (int i = 0 ; i < input.size(); i++){
            if (input[i] < '0' || input[i] > '9') return false;
        }
        return true;
    }
    
    int getNumber(string input){
        int number = 0;
        for (int i =0 ; i < input.size(); i++){
            number = number*10 + (input[i]-'0');
        }
        return number;
    }
    
    bool isOperator(char c){
        return (c == '+' || c =='-' || c== '*');
    }
    
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        if (input.size() == 0) return result;
        else if (isNumber(input)) {
            result.push_back(getNumber(input));
            return result;
        }
        for (int i = 0; i < input.size(); i++){
            if (isOperator(input[i])){
                vector<int> r1 = diffWaysToCompute(input.substr(0,i));
                vector<int> r2 = diffWaysToCompute(input.substr(i+1));
                for (int j = 0 ; j < r1.size(); j++){
                    for (int k = 0 ; k < r2.size(); k++){
                        if (input[i] == '+') result.push_back(r1[j]+r2[k]);
                        else if (input[i] == '-') result.push_back(r1[j]-r2[k]);
                        else if (input[i] == '*') result.push_back(r1[j]*r2[k]);
                    }
                }
                
            }
        }
        return result;
    }
};
