/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool compareFunction(Interval a, Interval b){
        return (a.start < b.start);
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> answer;
        sort(intervals.begin(),intervals.end(),compareFunction);
        int i = 0;
        while (i < intervals.size()){
            int start_time = intervals[i].start;
            int end_time = intervals[i].end;
            int j = i;
            while(j < intervals.size() && intervals[j].start <= end_time){
                end_time = max(end_time, intervals[j].end);
                j++;   
            }
            Interval * temp = new Interval(start_time, end_time);
            answer.push_back(*temp);
            i = j;
        }
        
        
        return answer;
    }
};
