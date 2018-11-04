class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int different_chars = 0;
        int interval_count = 0;
        vector<int> count(26,0);
        for (int i = 0; i < tasks.size(); i++) count[tasks[i]-'A']++;
        
        for (int i = 0 ; i < 26; i++) {
            if (count[i] != 0) different_chars++;
        }
        sort(count.begin(), count.end());
        reverse(count.begin(), count.end());
        
        while(different_chars != 0){
            int elems_used = 0;
            for (int i = 0; elems_used <= n && i < 26; i++){
                if (count[i] == 0) continue;
                else{
                    count[i]--;
                    elems_used++;
                    interval_count++;
                    if (count[i] == 0) different_chars--;
                    if (different_chars == 0) break;
                }
            }
            sort(count.begin(), count.end());
            reverse(count.begin(), count.end());
            if (different_chars == 0) break;
            interval_count = interval_count+(n-elems_used+1);
        }
        return interval_count;
    }
};
