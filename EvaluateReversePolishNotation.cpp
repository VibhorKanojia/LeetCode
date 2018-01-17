class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> eval;
        for (int i = 0 ; i < tokens.size(); i ++){
            if (tokens[i] == "+"){
                double val1 = eval.top();
                eval.pop();
                double val2 = eval.top();
                eval.pop();
                eval.push(val1+val2);
            }
            
            else if (tokens[i] == "*"){
                double val1 = eval.top();
                eval.pop();
                double val2 = eval.top();
                eval.pop();
                eval.push(val1*val2);
            }
            
            else if (tokens[i] == "/"){
                double val1 = eval.top();
                eval.pop();
                double val2 = eval.top();
                eval.pop();
                eval.push(val2/val1);
            }
            
            else if (tokens[i] == "-"){
                double val1 = eval.top();
                eval.pop();
                double val2 = eval.top();
                eval.pop();
                eval.push(val2-val1);
            }
            
            else {
                eval.push(stoi(tokens[i]));
            }
        }
        return eval.top();
    }
};
