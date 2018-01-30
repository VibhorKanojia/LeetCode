//GOOD QUESTION
struct Node{
    int val;
    int index;
    Node(int val, int index){
        this->val = val;
        this->index = index;
    }
};

class Compare{
    public:
        bool operator()(Node * a, Node * b){
            return (a->val > b->val);
        }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        priority_queue<Node *, vector<Node *>, Compare> heap;
        
        int cur_min = INT_MAX;
        int cur_max = INT_MIN;
        vector<int> pointerArray(k,0);
        for (int i = 0 ; i < k ; i++){
            Node * temp = new Node(nums[i][0],i);
            cur_min = min(cur_min, nums[i][0]);
            cur_max = max(cur_max, nums[i][0]);
            heap.push(temp);
        }
        int range_min = cur_min;
        int range_max = cur_max;
        
        while(true){
            Node * cur_node = heap.top();
            heap.pop();
            int index = cur_node->index;
            pointerArray[index]++;
            if (pointerArray[index] == nums[index].size()) break;
            heap.push(new Node(nums[index][pointerArray[index]],index));
            cur_min = heap.top()->val;
            cur_max = max(cur_max, nums[index][pointerArray[index]]);
            if (cur_max - cur_min < range_max - range_min){
                range_max = cur_max;
                range_min = cur_min;
            }
        }
        
        vector<int> answer;
        answer.push_back(range_min);
        answer.push_back(range_max);
        return answer;
    }
};
