class Solution {
public:
    int getSum(int a, int b) {
        int sum = a; //Sum initialized with a
        while (b != 0){
            sum = a^b; //This calculations the sum of a and b but carry is not passed at all. Think!
            b = (a & b) << 1; // a&b calculates the positions where carry would have generated; bitshift moves the carry to the correct position;
            a = sum; //So that in the next loop, we add sum with the carry to get exact sum of a and b
        } //continue this process till carry becomes 0
        
        return sum;
    }
};
