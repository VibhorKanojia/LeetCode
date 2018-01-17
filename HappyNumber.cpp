class Solution {
public:
    int digitSum(int n){
        int new_n = 0;
        while (n > 0){
            new_n += (n%10)*(n%10);
            n = n/10;
        }
        return new_n;
    }
    
    bool isHappy(int n) {
        if (n == 0) return false;
        int slow = n;
        int fast = n;
        do{
            slow = digitSum(slow);
            fast = digitSum(fast);
            fast = digitSum(fast);
        } while (slow != fast);
        
        return (slow == 1);
    }
};
