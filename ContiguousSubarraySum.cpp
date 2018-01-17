class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        vector<int> cummSum;
        int size = nums.size();
        if (size == 1) return false;
        k = abs(k);
        cout<<k<<endl;
        if (k == 0){
            for (int i = 1 ; i < size ; i++){
                if (nums[i] == 0 && nums[i-1] == 0){
                    return true;
                }    
                else{
                    return false;
                }
            }
        }
        
        
        cummSum.push_back(nums[0]);
        for (int i = 1 ; i < size ; i++){
            cummSum.push_back(cummSum[i-1] + nums[i]); 
            if (cummSum[i]%k == 0) return true;
        }
        
        map<int,int> remainderMap;
        map<int,int>::iterator it;
    
        for (int i = 0 ; i < size ; i++){
            int remainder = cummSum[i]%k;
            it = remainderMap.find(remainder);
            if (it != remainderMap.end()){
                return true;
            }
            else{
                remainderMap[remainder] = i;
            }
        }
        return false;
    }
};
