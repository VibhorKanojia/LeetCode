class Solution {
private:
    float distance(vector<int> &p1, vector<int> &p2){
        return pow(p2[1] - p1[1], 2) + pow(p2[0] - p1[0], 2); 
    }
    
    float helper(float d){
        return 8*d;
    }
    
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        float d1 = distance(p1,p2);
        float d2 = distance(p2,p3);
        float d3 = distance(p3,p4);
        float d4 = distance(p1,p4);
        float d5 = distance(p1,p3);
        float d6 = distance(p2,p4);
        vector<float> array;
        array.push_back(d1);
        array.push_back(d2);
        array.push_back(d3);
        array.push_back(d4);
        array.push_back(d5);
        array.push_back(d6);
       
        sort(array.begin(),array.end());
        return (array[0] == array[1] && array[1] == array[2] && array[2] == array[3] && array[4] == array[5] && array[4] == 2*array[3] && array[4] > array[3]);
        
    
    }
};
