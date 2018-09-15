class Solution {

public:
    int longestSubstring(string s, int k) {
        int max_len = 0;
        for (int h = 1 ; h < 26; h++){ // h unique characters; loop from 1 to 26
            int left = 0;
            int right = 0;
            int unique_count = 0;  // number of unique characters
            int more_than_k_count = 0; //number of unique characters with count >= k
            vector<int> count(26,0);
            while (right < s.size()){
                if (unique_count <= h){  // if unique count is less than h, more right pointer and update
                    char c = s[right];
                    if (count[c-'a'] == 0) unique_count++;
                    count[c-'a']++;
                    if (count[c-'a'] == k) more_than_k_count++;
                    right++;
                }
                else{ //if unique count is greater than h, move the left pointer to reduce unique count and update
                    char c = s[left];
                    if (count[c-'a'] == k) more_than_k_count--; // the order matters
                    count[c-'a']--;
                    if (count[c-'a'] == 0) unique_count--;
                    left++;
                }
                if (unique_count == h && more_than_k_count == h){
                    max_len = max(max_len, right-left);
                }
            }
        }
        return max_len;
    }
};
