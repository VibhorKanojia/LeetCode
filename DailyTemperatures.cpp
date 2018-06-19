class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int N = temperatures.size();
        vector<int> days(N,0);
        stack<int> buffer;
        buffer.push(0);
        for (int i = 1; i < N ; i++){
            while(!buffer.empty() && temperatures[i] > temperatures[buffer.top()]){
                days[buffer.top()] = i-buffer.top(); 
                buffer.pop();
            }
            buffer.push(i);
        }
        return days;
    }
};
