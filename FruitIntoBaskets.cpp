class Solution {
public:
    int totalFruit(vector<int>& tree) {
        if (tree.size() <= 2) return tree.size(); 
        int f1 = -1;
        int f2 = -1;
        int max_len = 0;
        int f1_streak = 0;
        int f2_streak = 0;
        int cur_len = 0;
        for (int i = 0; i < tree.size(); i++){
            if (tree[i] == f1) {
                f1_streak++;
                f2_streak = 0;
                cur_len++;
            }
            else if (tree[i] == f2) {
                f2_streak++;
                f1_streak = 0;
                cur_len++;
            }
            else{
                if (f1 == -1){
                    f1 = tree[i];
                    f1_streak++;
                    f2_streak = 0;
                    cur_len++;
                    continue;
                }
                else if (f2 == -1){
                    f2 = tree[i];
                    f2_streak++;
                    f1_streak = 0;
                    cur_len++;
                    continue;
                }
                else{
                    max_len = max(max_len, cur_len);
                    if (f1_streak == 0) {
                        f1 = tree[i];
                        cur_len = 1+f2_streak;
                        f2_streak=0;
                        f1_streak++;
                    }
                    else if (f2_streak == 0) {
                        f2 = tree[i];
                        cur_len = 1 +f1_streak;
                        f1_streak = 0;
                        f2_streak++;
                    }
                }
            }
        }
        max_len = max(max_len, cur_len);
        return max_len;
    }
};
