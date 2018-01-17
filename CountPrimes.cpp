class Solution {
public:
    int countPrimes(int n) {
        vector<bool> seive(n,1);
        int count = 0;
        for (int i = 2; i < n; i++){
            if (seive[i]) {
                count++;
                for (int j = i ; j < n ; j=j+i) seive[j] = 0;
            }
        }
        return count;
    }
};
