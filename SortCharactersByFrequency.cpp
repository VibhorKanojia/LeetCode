class Compare{
    public:
        bool operator()(pair<char,int> a, pair<char,int> b){
            return (a.second < b.second);
        }
};

class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256,0);
        for (int i =0 ; i < s.size(); i++) freq[s[i]]++;
        priority_queue<pair<char,int>, vector<pair<char,int>>, Compare> heap;
        for (int i =0 ; i < 256; i++){
            heap.push(pair<char,int>(i, freq[i]));
        }
        string result = "";
        while (!heap.empty()){
            pair<char,int> top = heap.top();
            heap.pop();
            while (top.second--) result += top.first;
        }
        return result;
    }
};
