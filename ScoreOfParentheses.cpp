// REALLY GOOD QUESTION
class Solution {
private:
    int dp(unordered_map<string,int> & memo, string S){
        if (memo.find(S) != memo.end()) return memo[S];
        int count = 0;
        for (int i = 0 ; i < S.size()-1; i++){
            if (S[i] == '(') count++;
            else if (S[i] == ')') count--;
            if (count == 0){
                memo[S] = dp(memo, S.substr(0,i+1)) + dp(memo,S.substr(i+1));
                return memo[S];
            }
        }
        memo[S] = 2*dp(memo,S.substr(1,S.size()-2));
        return memo[S];
    }
    
public:
    int scoreOfParentheses(string S) {
        int n = S.size();
        unordered_map<string,int> memo;
        memo.insert(pair<string,int>("()",1));
        return dp(memo,S);
    }
};
