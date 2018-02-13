class Solution {
public:
    string removeKdigits(string num, int k) {
        string result = "";
        int size = num.size()-k;
        for (int i = 0 ; i < num.size(); i++){
            while (result.size() > 0 && result.back() > num[i] && k > 0){
                result.pop_back();
                k--;
            }
            result.push_back(num[i]);
        }
        result.erase(size,result.size());
        int index = 0;
        while (index < result.size() && result[index] == '0') index++;
        result.erase(0,index);
        return (result =="")?"0":result;
        
        
    }
};
