//Incredible question
class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int count = 0;
        long int maxReach = 0;
        int index = 0;
        while (maxReach < n){
            if (index < nums.size() && nums[index]<=maxReach+1){
                maxReach = maxReach + nums[index];
                index++;
            }
            else{
                maxReach = maxReach + (maxReach+1); //maxReach+1 is the new number that we have added.
                count++;
            }
        }
        return count;
    }
};
