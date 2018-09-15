//O(nlogn) solution; can be done in O(n) if bucket sort is used
struct car{
    float pos;
    float speed;
    car(int pos, int speed){
        this->pos = pos;
        this->speed = speed;
    }
};

bool sortFunction(car * a, car * b) {
    return (a->pos > b->pos);   
}
class Solution { 
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() == 0 || position.size() == 1 ) return position.size();
        vector<car *> carList;
        for (int i =0 ; i < position.size(); i++){
            car * c = new car(position[i], speed[i]);
            carList.push_back(c);
        }   
        sort(carList.begin(), carList.end(), sortFunction);
        int fleetCount = 1;
        float pre_time = (target - carList[0]->pos)/(carList[0]->speed);
        for (int i = 1 ; i < carList.size(); i++){
            float time = (target - carList[i]->pos)/(carList[i]->speed);
            if (time > pre_time){
                pre_time = time;
                fleetCount++;
            }
        }
        return fleetCount;
    }
};
