struct Edge;
struct Node;

struct Node{
    vector<Edge *> neighbors;
    int index;
    int distance;
    int visited;
    Node(int index){
        this->index = index;
        visited = false;
    }
};

struct Edge{
    Node * to;
    int weight;
    Edge(Node* dest, int weight){
        to = dest;
        this->weight = weight;
    }
};

struct HeapNode{
    Node * u;
    int distance;
    HeapNode(Node * u, int distance){
        this->u = u;
        this->distance = distance;
    }
};

class compare{
    public:
        bool operator()(HeapNode * a, HeapNode * b){
            return (a->distance > b->distance);
        }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {        
        vector<Node *> graph;
        for (int i =0 ; i < N+1; i++){
            graph.push_back(new Node(i));
        }
        
        for (int i = 0; i < times.size(); i++){
            (graph[times[i][0]]->neighbors).push_back(new Edge(graph[times[i][1]], times[i][2]));
        }
        priority_queue<HeapNode *, vector<HeapNode *>, compare> heap;
        HeapNode * root = new HeapNode(graph[K], 0);
        heap.push(root);
        int delay = 0;
        while (!heap.empty()){
            HeapNode * topElem = heap.top();
            heap.pop();
            if (!topElem->u->visited) delay = topElem->distance;
            (topElem->u)->visited = true;
            for (int i = 0; i < ((topElem->u)->neighbors).size(); i++){
                Edge * edge = ((topElem->u)->neighbors)[i];
                if (!edge->to->visited){
                    HeapNode * temp = new HeapNode(edge->to, topElem->distance+edge->weight);
                    heap.push(temp);
                }
            }
        }
        
        for (int i = 1; i < N+1; i++){
            if (!graph[i]->visited) return -1;
        }
        return delay;
    }
};
