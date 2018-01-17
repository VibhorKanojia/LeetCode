class Solution {
private:
    bool isVowel(char c){
        if (c < 97) c=c+32;
        return (c == 'a' || c == 'e' || c == 'i' || c=='o' || c=='u');
    }
    
public:
    string reverseVowels(string s) {
        int ptr1 = 0;
        int ptr2 = s.size()-1;
        while (ptr1 < ptr2){
            while (!isVowel(s[ptr1]) && ptr1 < ptr2) ptr1++;
            while (!isVowel(s[ptr2]) && ptr1 < ptr2) ptr2--;
            if (ptr1 >= ptr2) break;
            char temp = s[ptr1];
            s[ptr1]=s[ptr2];
            s[ptr2] = temp;
            ptr1++;
            ptr2--;
        }
        return s;
    }
};
