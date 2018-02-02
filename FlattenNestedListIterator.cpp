/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
private:
    stack<vector<NestedInteger>::iterator> buffer;
    stack<vector<NestedInteger>::iterator> terminator;

    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        buffer.push(nestedList.begin()); 
        terminator.push(nestedList.end());
        
    }

    int next() {
        vector<NestedInteger>::iterator it = buffer.top();   //Guaranteed to be integer
        vector<NestedInteger>::iterator term = terminator.top();
        buffer.pop();
        terminator.pop(); 
        int val = it->getInteger();
        it++;
        if (it != term){
            buffer.push(it);
            terminator.push(term);
        }
        return val;
    }

    bool hasNext() { 
        bool flag = true; //becomes false when we encounter an integer
        while (flag && !buffer.empty()){
            auto it = buffer.top();
            auto term = terminator.top();
            if (it == term){
                buffer.pop();
                terminator.pop();
                continue;
            }
            if (it -> isInteger()){
                flag = false;
                continue;
            }
            else{                   //if It is a list
                buffer.pop();           // Remove the iterator from the stack
                terminator.pop();
                auto it2 = it;
                it++;
                if (it != term){
                    buffer.push(it);        //Only push it back if it was not the last element
                    terminator.push(term);
                }
            
                buffer.push((it2->getList()).begin());
                terminator.push((it2->getList()).end());
                
            }
        }
        return (!buffer.empty());
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
