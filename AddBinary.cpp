class Solution {
public:
    
    int getInt(char c){
        return c-'0';
    }
    string addBinary(string a, string b) {
        if (a== "0" && b=="0") return "0";
        stack<int> buffer;
        int N = a.size();
        int M = b.size();
        if (N < M){ //Making a the bigger string
            string temp = a;
            a = b;
            b = temp;
        }
        
        int carry = 0;
        int index1 = a.size()-1;
        int index2 = b.size()-1;
        while(index2 >= 0){
            int sum = getInt(a[index1]) + getInt(b[index2]) + carry;
            
            buffer.push(sum%2);
            carry = sum/2;
            index1--;
            index2--;
        }
        
        while(index1 >=0){
            int sum = getInt(a[index1]) + carry;
            buffer.push(sum%2);
            carry = sum/2;
            index1--;
        }
        if (carry != 0) buffer.push(carry);
        
        string answer = "";
        while (!buffer.empty() && buffer.top() == 0) buffer.pop();
        
        while(!buffer.empty()){
            answer += to_string(buffer.top());
            buffer.pop();
        }
        return answer;
    }
};
