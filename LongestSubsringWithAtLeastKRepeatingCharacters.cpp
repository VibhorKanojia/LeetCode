class Solution {

public:
    int longestSubstring(string s, int k) {
        vector<int> total(26,0);
        for (int i = 0; i < s.size(); i++){
            total[s[i]-'a']++;
        }
        vector<int> count(26,0);
        int cur_len = 0;
        int max_len = 0;
        for (int i =0 ; i < s.size(); i++){
            char c = s[i];
            if (total[c-'a'] < k){
                max_len = max(longestSubstring(s.substr(0,i),k), longestSubstring(s.substr(i+1),k));
                return max_len;
            }
            else{
                count[c-'a']++;
                cur_len++;
                int flag = 1;
                for (int i =0 ; i < 26; i++){
                    if (count[i] != 0 && count[i] < k){
                        flag = 0;
                    }
                }
                if (flag) max_len = cur_len;
            }
        }
        return max_len;
    }
};
