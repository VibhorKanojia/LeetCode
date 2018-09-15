//O(NlogN) : N -> number of jobs
struct job{
    int d;
    int p;
    job(int difficulty, int profit){
        d = difficulty;
        p = profit;
    }
};

bool sortFunction(job * a, job * b){
    return (a->p < b->p);
}

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int N = difficulty.size();
        vector<job *> jobList;
        for (int i =0 ; i < N; i++){
            jobList.push_back(new job(difficulty[i], profit[i]));
        }
        
        sort(worker.begin(),worker.end());
        sort(jobList.begin(), jobList.end(), sortFunction);
        int M = worker.size();
        int p_p = N-1;
        int w_p = M-1;
        int max_profit = 0;
        int cur_diff = jobList[p_p]->d;
        int cur_work = worker[w_p];
        while (p_p >= 0 && w_p >=0){
            cur_diff = jobList[p_p]->d;
            int work_count = 0;
            while (cur_work >= cur_diff && w_p >=0){
                work_count++;
                w_p--;
                cur_work = worker[w_p];
            }
            max_profit += (jobList[p_p]->p)*work_count;
            work_count = 0;
            p_p--;
        }
        return max_profit;
    }
};
