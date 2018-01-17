class Solution {
private:
    void reverse(string& s){
        for (int i = 0 ; i < s.size()/2; i++){
            char temp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = temp;
        }
        return;
    }
    
    int toInt(char c){
        return (int)(c-'0');
    }
    
public:
    string addStrings(string num1, string num2) {
        string sum = "";
        reverse(num1);
        reverse(num2);
        int N = num1.size();
        int M = num2.size();
        int index = 0;
        int carry = 0;
        
        while (index < N && index < M){
            int ds = toInt(num1[index]) + toInt(num2[index]) + carry;
            sum = sum + to_string(ds%10);
            carry = ds/10;
            index++;
        }
        
        while (index < N){
            int ds = toInt(num1[index]) + carry;
            sum = sum + to_string(ds%10);
            carry = ds/10;
            index++;
        }
        
        while (index < M){
            int ds = toInt(num2[index]) + carry;
            sum = sum + to_string(ds%10);
            carry = ds/10;
            index++;
        }
        if (carry != 0){
            sum = sum + to_string(carry);
        }
        
        reverse(sum);
        return sum;
    }
};
