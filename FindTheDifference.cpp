class Solution {
public:
    char findTheDifference(string s, string t) {
        int count[256];
        for (int i =0; i < 256 ; i++) count[i] = 0;
        for (int i = 0 ; i < t.size(); i++) count[t[i]]++;
        for (int i = 0 ; i < s.size(); i++) count[s[i]]--;
        for (int i = 0 ; i < 256; i++){
            if (count[i] == 1) return i;
        }
        return 0;
    }
};
