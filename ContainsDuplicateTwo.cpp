class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.size() == 0) return false;
        unordered_map<int,int> mymap;
        unordered_map<int,int>::iterator it;
        for (int i=0 ; i < nums.size() ; i++){
            it = mymap.find(nums[i]);
            if (it == mymap.end()){
                mymap.insert(pair<int,int>(nums[i],i));
            }
            else{
                if (i - it->second <= k) return true;
                it->second = i;
            }
        }
        return false;
    }
};
