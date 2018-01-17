//REALLY GOOD QUESTION; READ THE BINARY SOLUTION
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int attempts = floor(minutesToTest/minutesToDie) + 1;
        return ceil(log(buckets)/log(attempts));
    }
};
