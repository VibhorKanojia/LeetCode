class Solution {

public:
    int minMutation(string start, string end, vector<string>& bank) {
        vector<char> char_set;
        char_set.push_back('A');
        char_set.push_back('C');
        char_set.push_back('G');
        char_set.push_back('T');
        
        unordered_set<string> map;
        unordered_set<string> visited;
        for (int i = 0; i < bank.size(); i++){
            map.insert(bank[i]);
        }
        
        
        
        queue<string> buffer;
        buffer.push(start);
        int level = 0;
        int elem_count=1;
        while (!buffer.empty()){
            string cur_elem = buffer.front();
            buffer.pop();
            elem_count--;
            
            if (cur_elem == end) return level;
            visited.insert(cur_elem);
            
            for (int i = 0 ; i < 8 ; i++){
                char c = cur_elem[i];
                for (int j = 0 ; j < 4; j++){
                    cur_elem[i] = char_set[j];
                    if (map.find(cur_elem) != map.end() && visited.find(cur_elem) == visited.end()){
                        buffer.push(cur_elem);
                    }
                }
                cur_elem[i] = c;
            }
            
            if (elem_count == 0) {
                elem_count = buffer.size();
                level++;
            }
            
        }
        return -1;
    }
};
