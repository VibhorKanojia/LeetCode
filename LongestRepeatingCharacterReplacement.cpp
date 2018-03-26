class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int start = 0;
        int end = 0;
        int len = s.size();
        int max_count = 0;
        int max_len = 0;
        
        while (end < len){
            count[s[end]-'A']++;
            max_count = max(max_count, count[s[end]-'A']);
            while (k < end-start+1 - max_count){
                count[s[start]-'A']--;
                start++;
                //We don't update the max_count here because we don't care about the accurate max_count, we just want to update max_count if the new value is greater than the historical max value
            }
            max_len = max(max_len, end-start+1);
            end++;
        }
        
        return max_len;
    }
};
