class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answer;
        int index1 = 0;
        int index2 = numbers.size()-1;
        int sum;
        while (index1 < index2){
            sum = numbers[index1] + numbers[index2];
            if (sum == target){
                answer.push_back(index1+1);
                answer.push_back(index2+1);
                return answer;
            }
            else if (sum < target) index1++;
            else index2--;
        }
        return answer;
    }
};
