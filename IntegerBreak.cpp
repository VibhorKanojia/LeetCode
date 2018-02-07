// O(logN) solution; Idea is to generate as many 3s as possible and fill remaining with 2.
// If we have factor f, we can always replace it with [2, f-2], since 2*(f-2) >= f for bigger numbers.
// and between 2 and 3, 3*3 > 2*2*2, so we can always replace three 2s with two 3s. Therefore, maximum we can have only two 2s and remaining 3s
// If we take the derivative of the function, we can figure out that maximum product is achieved when we have n/e e (e = 2.78..)
 
class Solution {
public:
    int integerBreak(int n) {
        vector<int> array(n+1,0);
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n%3 == 0) return pow(3,n/3);
        if (n%3 == 1) return 2*2*pow(3, (n-4)/3);
        if (n%3 == 2) return 2*pow(3, (n-2)/3);
    }
};

/* O(N^2) solution
class Solution {
public:
    int integerBreak(int n) {
        vector<int> array(n+1,0);
        if (n == 2) return 1;
        array[1] = 1;
        array[2] = 2;
        for (int i = 3; i <= n; i++){
            for (int j = i-1; j >= 1; j--){
                array[i] = max(array[i], max(array[j],j)*(i-j));
            }
        }
        return array[n];
    }
};
*/
