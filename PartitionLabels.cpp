//Beats 97%
class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> parray(26,-1);
        vector<int> result;
        vector<int> index_array(26,-1);
        int pc = 0;
        for (int i = 0 ; i < S.size(); i++){
            char c = S[i];
            if (index_array[c-'a'] == -1){
                index_array[c-'a'] = i;           
                parray[pc] = 1;
                pc++;
            }
            else{
                
                int first_index = index_array[c-'a'];
                int count = 0;
                for (int j =0 ; j < pc ; j++){
                    if (first_index < count + parray[j]){
                        parray[j] = i - count+1;
                        pc = j+1;
                        break;
                    }
                    else{
                        count = count + parray[j];
                    }
                }
                
            }
        }
        for (int i = 0 ; i < pc ; i++) result.push_back(parray[i]);
        return result;
    }
};
