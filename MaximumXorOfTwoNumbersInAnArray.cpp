class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxNum = INT_MIN;
        for (int i =0 ; i < nums.size() ; i++) maxNum = max(maxNum, nums[i]);
        //size = maximum number of bits possible in the XOR
        int size = log(maxNum)/log(2);
        
        int mask = 0;        
        
        
        int curMax = 0;
        
        int potentialMax = 0;
        for (int i = size; i >= 0 ; i--){ //Consider each bit starting from the most significant bit
            unordered_set<int> hashSet;
            mask = mask | (1 << i); //mask - 10000... -> 11000... -> 11100... -> 11110...
            for (int j = 0 ; j < nums.size(); j++) hashSet.insert(mask & nums[j]); 
            
            //curMax -> guaranteed max until this point;
            //potentialMax -> if we find 2 numbers differing at bit i, what would be the new max
            potentialMax = curMax | (1 << i); 
            for (auto it = hashSet.begin(); it != hashSet.end(); it++){
                if (hashSet.find(*it ^ potentialMax) != hashSet.end()){ //a^b = c => a^c = b; used to check the above condition
                    curMax = potentialMax; //change curMax if we find such two numbers
                    break;      //no need to continue checking
                }
            }
            
        }
        return curMax;
    }
};
