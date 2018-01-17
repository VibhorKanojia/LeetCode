//NOT AS BAD AS IT SEEMED AFTER READING;
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> answer;
        int hours[12];
        int minutes[60];
        
        for (int i = 0 ; i < 12; i++){
            bitset<4> hr(i);
            hours[i] = hr.count();
        }
        for (int i = 0 ; i < 60; i++){
            bitset<6> min(i);
            minutes[i] = min.count();
        }
        for (int i = 0 ; i <= num; i++){
            int j = num-i;
            string h = "";
            string m = "";
            for (int k = 0 ; k < 12; k++){
                if (hours[k] == i) {
                    h = to_string(k);
                    for (int g = 0 ; g < 60 ; g++){
                        if (minutes[g] == j) {
                            m = to_string(g);
                            if (g<=9) m ="0"+m;
                            string ti = h+":"+m;
                            answer.push_back(ti);
                        }
                    }
                }
                
            }
        }
        return answer;
    }
};
