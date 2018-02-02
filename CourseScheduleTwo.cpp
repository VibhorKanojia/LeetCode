struct Node{
    int id;
    int status;
    vector<Node *> dependency;
    Node(int id){
        this->id = id;
        status = 0; //0->unvisited ; 1-> in stack ; 2->visited
    }
};

class Solution {
private:
    bool DFS(stack<int> & order, Node * u){
        u->status = 1;
        bool flag = 1;
        for (int i = 0 ; i < (u->dependency).size() ; i++){
            Node * v = (u->dependency)[i];
            if (v->status == 1) return 0; //Back-edge detected
            else if (v->status == 0){
                flag = DFS(order,v);
            }
            if (flag == 0) return 0; //No ordering possible if a back-edge is detected
        }
        order.push(u->id);    
        u->status = 2;
        return 1;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<Node *> graph;
        for (int i = 0 ; i < numCourses; i++){
            graph.push_back(new Node(i));
        }
        for (int i = 0 ; i < prerequisites.size(); i++){
            int u = prerequisites[i].first;
            int v = prerequisites[i].second;
            (graph[v]->dependency).push_back(graph[u]); //v is a dependency of u
        }
        stack<int> order;
        bool flag = 1;
        vector<int> answer;
        for (int i = 0 ; i < numCourses; i++){
            if (graph[i]->status == 0){
                flag = DFS(order,graph[i]);
            }
            if (flag == 0) return answer;
        }
        
        while (!order.empty()){
            answer.push_back(order.top());
            order.pop();
        }
        return answer;
    }
};
