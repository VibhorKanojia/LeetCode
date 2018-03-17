/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */


bool Compare(Interval a, Interval b){
    return (a.start < b.start);
}

class Solution {
private:
    int findMinArrowShots(vector<Interval>& points) {
        int n = points.size();
        if (n == 0) return 0;
        sort(points.begin(),points.end(),Compare);
        int arrows = 0;
        int cur_end = points[0].end;
        for (int i = 0 ; i <  n; i++){
            if (points[i].start >= cur_end){
                arrows++;
                cur_end = points[i].end;
            }
            else{
                cur_end = min(cur_end, points[i].end);
            }
        }
        arrows++;
        return arrows;
    }
    
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int arrows = findMinArrowShots(intervals);
        return (intervals.size()-arrows);
    }
};
