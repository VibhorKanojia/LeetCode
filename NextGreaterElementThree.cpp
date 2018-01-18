class Solution {
public:
    int nextGreaterElement(int n) {
        int dc = log(n)/log(10)+1;
        vector<int> array(dc, 0);
        int index = dc -1; 
        while (n > 0){
            int digit = n%10;
            array[index] = digit;
            n = n/10;
            index--;
        }
        for (int i = dc -1; i >= 0; i--){
            // array[i] is current element
            for (int j = dc-1 ; j > i ; j--){
                if (array[j] > array[i]){
                    int temp = array[j];
                    array[j] = array[i];
                    array[i] = temp;
                    sort(array.begin()+i+1, array.end());
                    long int big_num = 0;
                    for (int k = 0 ; k < dc; k++){
                        cout<<array[k]<<" ";
                        big_num = big_num*10+array[k];
                    }
                    return (big_num > INT_MAX)?-1: big_num;
                }
            }
        }
        
        return -1;
    }
};
