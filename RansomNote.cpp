class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() == 0) return true;
        if (magazine.size() == 0) return false;
        int count[256];
        for (int i = 0 ; i < 256; i++) count[i] = 0;
        for (int i = 0 ; i < magazine.size(); i++) count[magazine[i]]++;
        
        for (int i = 0 ; i < ransomNote.size(); i++){
            if (count[ransomNote[i]] <= 0) return false;
            else count[ransomNote[i]]--;
        }
        
        return true;
    }
};
