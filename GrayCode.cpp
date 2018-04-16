class Solution {
private:
    vector<string> grayCodeHelper(int n){
        vector<string> result;
        if (n == 0){
            result.push_back("0");
        }
        else if (n == 1){
            result.push_back("0");
            result.push_back("1");
        }
        else{
            vector<string> pre = grayCodeHelper(n-1);
            for (int i = 0 ; i < pre.size(); i++){
                result.push_back(pre[i]+"0");
            }
            for (int i = pre.size()-1 ; i >= 0; i--){
                result.push_back(pre[i]+"1");
            }
        }
        return result;
    }
    
    int convert(string str){
        int val = 0;
        for (int i = 0 ; i < str.size(); i++){
            int bit = str[i] - '0';
            if (bit) val = val + pow(2, i);
        }
        return val;
    }
public:
    vector<int> grayCode(int n) { 
        vector<string> binary = grayCodeHelper(n);
        vector<int> result;
        for (int i =0 ; i < binary.size(); i++){
            result.push_back(convert(binary[i]));
        }
        return result;
    }
};
