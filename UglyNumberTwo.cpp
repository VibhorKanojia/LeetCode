class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> primes;
        primes.push_back(2);
        primes.push_back(3);
        primes.push_back(5);
        vector<int> uglyArray(n,0);
        vector<int> pointers(primes.size(),0);
        uglyArray[0]=1;
        for (int i = 1 ; i < n ; i++){
            int nextUgly = INT_MAX;
            for (int j = 0; j < primes.size(); j++){
                nextUgly = min(nextUgly, primes[j]*uglyArray[pointers[j]]);
            }
            uglyArray[i] = nextUgly;
            for (int j = 0; j < primes.size(); j++){
                if (nextUgly == primes[j]*uglyArray[pointers[j]]) pointers[j]++;
            }
        }
        return uglyArray[n-1];
    }
};
