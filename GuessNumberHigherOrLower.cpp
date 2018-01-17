// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
private:
    int guessNumberHelper(int start, int end){
        if (start>end) return -1;
        int mid = start + (end-start)/2;
        int res = guess(mid);
        if (res == 0) return mid;
        if (res < 0) return guessNumberHelper(start,mid-1);
        if (res > 0) return guessNumberHelper(mid+1, end);
    }
    
public:
    int guessNumber(int n) {
        return guessNumberHelper(1, n);
    }
};
