//ADVANCED DP QUESTION

class Solution {
private:
    int getVal(vector<int> & nums, int index){
        if (index < 0 || index >= nums.size()) return 1;
        else return nums[index];
    }
    
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int ** memo = new int*[n];   // memo[i][j] => maximum coins that we can get by popping all the balloons in range i to j
        for (int i = 0 ; i < n ; i++){
            memo[i] = new int[n];
        }
        
        for (int len = 1; len <= n; len++){
            for (int start = 0; start < n-len+1; start++){
                int end = start + len -1;
                int maxCoins = 0;

                for (int last = start; last <=end; last++){
                    int curCoins=0;
                    curCoins += (last != start)? memo[start][last-1]:0;
                    curCoins +=(last != end)? memo[last+1][end]:0;
                    curCoins += getVal(nums,last)*getVal(nums,start-1)*getVal(nums,end+1);
                    maxCoins = max(maxCoins, curCoins);
                }
                memo[start][end] = maxCoins;
            }
        }
        
        return memo[0][n-1];
    }
};
