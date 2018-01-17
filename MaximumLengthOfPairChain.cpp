class Solution {

bool static compareFunction(vector<int> v1, vector<int> v2){
    return (v1[1] < v2[1] || (v1[1] == v2[1] && v1[0] < v2[0]));
}
    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
       sort(pairs.begin(), pairs.end(), compareFunction);
       int count = 0;
       int end = INT_MIN;
       for (int i=0 ; i < pairs.size(); i++){
           cout<<pairs[i][0]<<" "<<pairs[i][1]<<endl;
           if (pairs[i][0] > end){
               count++;
               end = pairs[i][1];
           }
       }
        return count;
    }
};
