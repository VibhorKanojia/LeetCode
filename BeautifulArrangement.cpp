class Solution {
private:
    void backtrack(int index, unordered_set<int> & map, int & count, int N){
        if (index == N){
            count++;
            return;
        }
        for (int i = 1; i <= N ; i++){
            if (map.find(i) == map.end() && ( i%index == 0 || index%i == 0)){
                map.insert(i);
                backtrack(index+1, map, count, N);
                map.erase(i);
            }
        }
        return;
    }
    
public:
    int countArrangement(int N) {
        int count = 0;
        unordered_set<int> map;
        backtrack(1, map, count, N);
        return count;
    }
};
