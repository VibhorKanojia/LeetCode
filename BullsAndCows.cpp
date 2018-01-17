//https://leetcode.com/problems/bulls-and-cows/description/
class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> s_count(10,0);
        vector<int> g_count(10,0);
        int bull = 0;
        int cow = 0;
        for (int i = secret.size()-1 ; i >= 0; i--) {
            s_count[secret[i]-'0']++;
            g_count[guess[i]-'0']++;
            if (secret[i] == guess[i]) bull++;
        }
        for (int i = 0 ; i< 10 ; i++){
            cow += min(s_count[i],g_count[i]);
        }
        cow = cow - bull;
        
        return to_string(bull) + "A" + to_string(cow) + "B";
        
    }
};
