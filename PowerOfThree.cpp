class Solution {
public:
    //REALLY GOOD QUESTION
    bool isPowerOfThree(int n) {
        int const powerMax = 1162261467;
        int const intMax = 2147483647;
        if (n <= 0 || n > powerMax) return false;
        return powerMax % n == 0;
    }
};
