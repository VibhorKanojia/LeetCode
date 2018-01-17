class Solution {
public:
    int addDigits(int num) {
        //digit root congruence property;
         return 1 + (num - 1) % 9;
    }
};
