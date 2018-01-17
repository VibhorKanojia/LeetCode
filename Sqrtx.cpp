class Solution {
public:
    int binarySearch(int x, int start, int end){
        if (start > end) return start-1;
        int mid = start + (end-start)/2;
        if (mid == (int)x/mid) return mid;
        
        if (mid > x/mid) return binarySearch(x, start, mid-1);
        else return binarySearch(x,mid+1,end);
    }
    
    int mySqrt(int x) {
        
        if (x == 0 || x == 1) return x;
        return binarySearch(x, 1, x);
    }
};
