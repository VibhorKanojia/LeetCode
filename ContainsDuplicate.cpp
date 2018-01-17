class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> mymap;
        for (int i = 0; i < nums.size(); i++){
            if (mymap.find(nums[i]) == mymap.end()){
                mymap.insert(pair<int,bool>(nums[i],true));
            }
            else return true;
        }
        return false;
    }
};
