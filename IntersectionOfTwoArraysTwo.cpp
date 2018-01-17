class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> solution;
        unordered_map<int, int> mapper;
        unordered_map<int, int>::iterator it;
        for (int i = 0 ; i < nums1.size() ; i++){
            it = mapper.find(nums1[i]);
            if (it == mapper.end()){
                mapper.insert(pair<int,int>(nums1[i],1));
            }
            else{
                (it->second)++;
            }
        }
        
        for (int i = 0; i < nums2.size(); i++){
            it = mapper.find(nums2[i]);
            if (it != mapper.end() && it->second > 0){
                solution.push_back(it->first);
                (it->second)--;
            }
        }
        
        return solution;
    }
};
