class Solution {
private:
    bool isSubsequenceHelper(string s, string t, int si, int ti){
        int n = s.size();
        if ((n ==0)) return true;
        int m = t.size();
        while (ti < m){
            if (s[si] == t[ti]){
                si++;
                ti++;
            }
            else ti++;
            if (si >= n) return true;
        }
        return false;
    }
public:
    bool isSubsequence(string s, string t) {
        vector<int> tc(26,0);
        vector<int> sc(26,0);
        for (int i =0 ; i < s.size(); i++) sc[s[i]-'a']++;
        for (int i =0 ; i < t.size(); i++) tc[t[i]-'a']++;
        
        for (int i = 0; i< 26; i++){
            if (sc[i] > tc[i]) return false;
        }
        
        return isSubsequenceHelper(s,t,0,0);
    }
};
