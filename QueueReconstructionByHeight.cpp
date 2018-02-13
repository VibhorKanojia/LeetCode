//O(N^2) Solution
class Solution {
private:
    bool static Compare(pair<int,int> a, pair<int,int> b){
        if (a.first > b.first) return true;
        if (a.first == b.first && a.second < b.second) return true;
        else return false;
    } 
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), Compare);
        vector<pair<int,int>> result;
        int n = people.size();
        for (int i =0; i < n ; i++){
            int count = 0;
            auto it = result.begin();
            while(it != result.end()){
                if (count == people[i].second) break;
                if (it->first >= people[i].first) count++;
                it++;
            }
            result.insert(it,people[i]);
        }
        return result;
    }
};
