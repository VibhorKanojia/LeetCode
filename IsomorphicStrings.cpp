class Solution {
private:
    bool isIsomorphicHelper(string s, string t){
        unordered_map<char,char> mymap;
        unordered_map<char,char>::iterator it;
        for (int i = 0 ; i < s.size() ; i++){
            char c = s[i];
            if (mymap.find(c) == mymap.end()){
                mymap.insert(pair<char,char>(c,t[i]));
            }
            else{
               it = mymap.find(c);
               if (it->second != t[i]) return false;
            }
        }
        return true;
    }
    
public:
    bool isIsomorphic(string s, string t) {
        return (isIsomorphicHelper(s,t) && isIsomorphicHelper(t,s));
    }
};
