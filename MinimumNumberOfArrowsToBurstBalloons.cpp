
bool Compare(pair<int,int> a, pair<int,int> b){
    return (a.first < b.first);
}

class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n = points.size();
        if (n == 0) return 0;
        sort(points.begin(),points.end(),Compare);
        int arrows = 0;
        int cur_end = points[0].second;
        for (int i = 0 ; i <  n; i++){
            if (points[i].first > cur_end){
                arrows++;
                cur_end = points[i].second;
            }
            else{
                cur_end = min(cur_end, points[i].second);
            }
        }
        arrows++;
        return arrows;
    }
};
