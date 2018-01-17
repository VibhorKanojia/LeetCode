class Solution {
private:
    int binarySearch(int start, int end, int target){
        
        if (start > end)return -1;
        int mid = end - (end-start)/2;
        double value = 2*(double)target/(double)(mid+1);
        
        if (mid <= value && (mid+2) > value) return mid;
        else if (mid < value) return binarySearch(mid+1, end, target);
        else return binarySearch(start, mid-1, target);
    }
    
public:
    int arrangeCoins(int n) {
        if (n <= 0) return 0; 
        return binarySearch(1, sqrt(2)*sqrt(n)+1, n);   
    }
};
