class Solution {
private:
    char toChar(int pos){
        return ('A'+pos);
    }
    
public:
    string convertToTitle(int n) {
        string title ="";
        while (n > 0){
            n = n-1;
            int pos = n%26;
            title = toChar(pos)+title;
            n = n/26;
        }
        return title;
    }
};
