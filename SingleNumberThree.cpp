class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xval = 0;
        vector<int> answer;
        for (int i = 0 ; i < nums.size(); i++) xval ^=nums[i];
        int temp = 1;
        while ((xval & temp) == 0) temp = temp*2;
        int elem1 = 0;
        int elem2 = 0;
        //cout<<temp<<endl;
        for (int i = 0 ; i < nums.size(); i++){
            if ((nums[i] & temp) == temp) elem1 ^=nums[i];
            else elem2 ^= nums[i];
        }
        answer.push_back(elem1);
        answer.push_back(elem2);
        return answer;
    }
};
