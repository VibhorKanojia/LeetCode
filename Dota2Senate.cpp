class Solution {
public:
    string predictPartyVictory(string senate) {
        int rc = 0; //Total number of R left in the queue
        int dc = 0; //Total number of D left in the queue
        queue<char> buffer;
        for (int i =0 ; i < senate.size(); i++){
            if (senate[i] == 'R') {
                buffer.push('R');
                rc++;
            }
            else {
                buffer.push('D');
                dc++;
            }
        }
        int rk = 0; //rk -ve means number of R voided, so only insert back if it is positive
        int dk = 0; //dk -ve means number of D voided, so only insert back if it is positive
        do{    
            char cur_elem = buffer.front();
            buffer.pop();
            if (cur_elem == 'R' && rk >=0){
                dk--;
                buffer.push(cur_elem);
            }
            else if (cur_elem =='R' && rk < 0){
                rk++;
                rc--;
            }
            else if (cur_elem == 'D' && dk >=0){
                rk--;
                buffer.push(cur_elem);
            }
            else if (cur_elem == 'D' && dk < 0){
                dk++;
                dc--;
            }
        }while (buffer.size() != rc && buffer.size() != dc);
        if (buffer.size() == rc) return "Radiant";
        else return "Dire";
    }
};
