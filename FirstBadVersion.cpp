// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int binarySearch(int start, int end){
        if (start > end) return -1;
        int mid = end - (end-start)/2;
        int val1 = isBadVersion(mid);
        if (val1 && !isBadVersion(mid-1)) return mid;
        else if (val1) return binarySearch(start,mid-1);
        else if (!val1) return binarySearch(mid+1,end);
    }
    int firstBadVersion(int n) {
        return binarySearch(0, n);
    }
};
