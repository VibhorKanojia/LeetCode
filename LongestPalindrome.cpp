class Solution {
public:
    int longestPalindrome(string s) {
        int count[256];
        for (int i = 0 ; i < 256; i++) count[i] = 0;
        for (int i = 0 ; i < s.size(); i++) count[s[i]]++;
        
        int oddCount = 0;
        for (int i = 0 ; i < 256; i++){    
            if (count[i]%2 == 1) oddCount++;
        }
        
        return s.size() - oddCount + (oddCount > 0); //oddCount > 0 is 1 only if odd numbers exist else 0. Really good thought process!
    }
};
