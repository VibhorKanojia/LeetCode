class Solution {
private:
    bool binarySearch(int start, int end, int num){
        
        if (start>end) return 0;
        int mid = start + (end-start)/2;
        float val = (float)num/(float)mid;
        if (mid == val) return 1;
        if (mid > val) return binarySearch(start, mid-1,num);
        else return binarySearch(mid+1, end, num);
    }
    
public:
    bool isPerfectSquare(int num) {
        if (num < 1) return false;
        if (num == 1) return true;
        return binarySearch(0,num, num); 
    }
};
