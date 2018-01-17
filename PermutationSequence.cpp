class Solution {
public:
    string getPermutation(int n, int k) {
        int factorials[] = {1,1,2,6,24,120,720,5040,40320,362880};
        unordered_set<int> buffer;
        string answer = "";
        while(n > 0){
            int num = 1;
            while (buffer.find(num) != buffer.end()) num++; 
            int threshold = factorials[n-1];
            while (threshold < k){
                num++;
                while (buffer.find(num) != buffer.end()) num++; 
                k -=threshold;
            }
            cout<<"NUM is "<<num<<endl;
            answer = answer + to_string(num);
            buffer.insert(num);
            n = n-1;
        }
        return answer;
    }
};
