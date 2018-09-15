class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> buffer;
        for (int i =0 ; i < asteroids.size(); i++){
            if (asteroids[i] > 0) buffer.push_back(asteroids[i]);
            else{
                while (!buffer.empty() && buffer.back() > 0 && buffer.back() < -1*asteroids[i]){
                    buffer.pop_back();
                }
                if (!buffer.empty() && buffer.back() == asteroids[i]*-1) buffer.pop_back();
                else if (buffer.empty() || buffer.back() < 0) buffer.push_back(asteroids[i]);
            }
        }
        return buffer;
    }
};
