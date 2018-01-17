class RandomizedSet {
private:
    unordered_map<int,int> mapper;
    vector<int> buffer;
    unordered_map<int,int>::iterator it;
    
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        it = mapper.begin();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        it = mapper.find(val);
        if (it != mapper.end()) return false;
        else {
            buffer.push_back(val);
            int index = buffer.size()-1;
            mapper.insert(pair<int,int>(val,index));
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        it = mapper.find(val);
        if (it == mapper.end()) return false;
        else {
            int index = it->second;
            int end = buffer.size()-1;
            if (end == index){
                buffer.pop_back();
                mapper.erase(it);
                return true;
            }
            else{
                buffer[index] = buffer[end];
                buffer.pop_back();
                mapper.erase(it);
                if (buffer.size() == 0) return true;
                it = mapper.find(buffer[index]);
                it->second = index;
                return true;
            }
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int index = rand() % buffer.size();
        return buffer[index];
    }
};

