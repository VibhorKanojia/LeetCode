class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int index = 0;
        while (index < nums.size()){
            int elem = nums[index];
            if (elem -1 == index) index++;
            else if (nums[elem-1] == nums[index]) return elem;
            else{
                swap(nums[elem-1],nums[index]);
            }
        }
        return -1; //Shouldn't reach here;
    }
};
