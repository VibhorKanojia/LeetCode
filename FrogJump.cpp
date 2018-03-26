struct path{
    int stone;
    int step;
    path(int stone, int step){
        this->stone = stone;
        this->step = step;
    }
};

class Solution {

public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_set<int> hash_map;
        for (int i =0 ; i < n; i++){
            hash_map.insert(stones[i]);
        }
        
        int last = stones[n-1];
        if (last > 606000) return false; //n*(n+1)/2
        if (stones[1] != 1) return false;
        stack<path *> buffer;
        buffer.push(new path(1,1));
        while (!buffer.empty()){
            path * top = buffer.top();
            
            buffer.pop();
            if (top->stone == last) return true;
            if (hash_map.find(top->stone + top->step-1) != hash_map.end()){
                int new_stone = top->stone + top->step-1;
                int new_step = top->step-1;
                if (new_step != 0) buffer.push(new path(new_stone, new_step));
            }
            if (hash_map.find(top->stone + top->step) != hash_map.end()){
                int new_stone = top->stone + top->step;
                int new_step = top->step;
                buffer.push(new path(new_stone, new_step));
            }
            if (hash_map.find(top->stone + top->step+1) != hash_map.end()){
                int new_stone = top->stone + top->step+1;
                int new_step = top->step+1;
                buffer.push(new path(new_stone, new_step));
            }
        }
        
        return false;
    }
};
