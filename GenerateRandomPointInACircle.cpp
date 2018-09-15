//not need of calling multiple times if using polar coordinates;
//much better solution with that
class Solution {
private:
    double radius;
    double x_center;
    double y_center;
public:
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    vector<double> randPoint() {
        double x = (2*((double)rand()/RAND_MAX) - 1.0)*radius;
        double y = (2*((double)rand()/RAND_MAX) - 1.0)*radius;;
        if (x*x + y*y <= radius*radius){
            vector<double> point;
            point.push_back(x+x_center);
            point.push_back(y+y_center);
            return point;
        }
        else{
            return randPoint();
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj.randPoint();
 */
