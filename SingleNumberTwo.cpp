class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int i =0 ; i < nums.size(); i++){
            twos = twos | (ones & nums[i]);   // send twos bit to 1 only if ones is set to 1 (contains bits which appear 3 times)
            
            ones = ones ^ nums[i];     // send ones bit to 1 if nums[i] has 1 (contains bits which appear 3 times)
            
            int common_mask = ~(ones & twos); // find common bits and flip them
            twos = twos & common_mask;  //remove them from twos to handle bits which appear 3 times
            ones = ones & common_mask; // remove them from ones to handle bits which appear 3 times
        }
        
        return ones;
    }
};



//Another Solution with explanation
//

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int i =0 ; i < nums.size(); i++){   
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }    
        return ones;
    }
};

/* Make a truth table
 *  00 -> a particular bit was on 0 or 3 times
 *  10 -> a particular bit was on 1 time
 *  01 -> a particular bit was on 2 times
 So the loop will be 00 -> 10 -> 01 -> 00

 'ones' represent the first index bit
 'twos' represent the second index bit

 Let's make a truth table

 Nums[i]    Ones   Twos   |   Ones_new    Twos_new

   0         0      0     |    0       0
   0         1      0     |    1       0
   0         0      1     |    0       1
   1         0      0     |    1       0
   1         1      0     |    0       1
   1         0      1     |    0       0


   From this, the formula for 
   Ones_new = Ones & ~Twos & ~Nums[i] | ~Ones & ~Twos & Nums[i]
            =>  (Ones & ~Nums[i] | ~Ones & Nums[i]) & ~Twos
            =>  (Ones ^ Nums[i]) & ~Twos

            So we update 'Ones' in the code;

   Similarly the formula for
   Twos_new = Twos & ~Ones_new & ~Nums[i] | ~Twos & ~Ones_new & Nums[i]
            => (Twos & ~Nums[i] | ~Twos & Nums[i]) & ~Ones_new
            => (Twos ^ Nums[i]) & ~Ones_new

            Here we used 'ones_new' instead of 'ones' because we are updated 'ones' before updating 'twos'


 When done for all the bits, whatever bits are left on in 'ones' have appeared only once. Hence, it will be our answer;
