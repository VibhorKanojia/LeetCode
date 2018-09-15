class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int count = 0;
        for (int i =shifts.size()-1 ; i >=0; i--){
            count = (count + shifts[i])%26;
            S[i] = 'a' + ((S[i]-'a' + count)%26);
        }
        return S;
    }
};
