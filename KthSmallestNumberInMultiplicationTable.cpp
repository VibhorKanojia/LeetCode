//Solution using heap is m*nlogn; Solution using binary search is m*log(m*n);

class Solution {
private:
    int getPos(int val, int m, int n){
        int count = 0;
        for (int i = 1; i <=m ; i++){
            count += min(val/i,n);
        }
        return count;
    }
    
    int binarySearch(int m, int n, int k, int start, int end){
        if (start == end) return start;
        int mid = start + (end-start)/2;
        int pos= getPos(mid,m,n);
        //We cannot return mid when pos == k because it is not guaranteed that mid exists in the table. But it is guaranteed that a number t < mid exists with the same pos. So we keep on reducing the range until we are left with only one element which would be t.
        //cout<<start<<" "<<mid<<"("<<pos<<") "<<end<<endl;
        if (pos >= k) return binarySearch(m,n,k,start,mid);
        else return binarySearch(m, n, k, mid+1, end);
    }
public:
    int findKthNumber(int m, int n, int k) {
        return binarySearch(m, n, k, 1, m*n);
    }
};
