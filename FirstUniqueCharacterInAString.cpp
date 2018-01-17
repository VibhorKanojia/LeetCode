class Solution {
public:
    int firstUniqChar(string s) {
        int count[256];
        for (int i = 0; i < 256 ; i++) count[i] = -1;
        for (int i = 0 ; i < s.size() ; i++) {
            if (count[s[i]] == -1) count[s[i]] = i;
            else count[s[i]] = -2;
        }
        int min_elem = INT_MAX;
        for (int i = 0 ; i < 256; i++) {        
            if (count[i] != -1 && count[i] != -2) min_elem = min(min_elem,count[i]);
        }
        return (min_elem == INT_MAX)?-1:min_elem;
    }
};
