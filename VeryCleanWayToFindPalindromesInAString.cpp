class Solution {
private:
   
public:
    void Palindromes(string s) {
        int n = s.size();
        bool ** array = new bool*[n];
        for (int i = 0; i < n; i++){
            array[i] = new bool[n];
        }
        
        for (int len = 1; len <= n; len++){  //iterate over length
            for (int i = n-len; i >= 0; i--){  // i = n-len is to make sure that j is always inbound; note that i start from right to left
                int j = len+i-1;    // j-i+1 = len
                if (i == j) array[i][j] = 1;  //len =1 base case
                else if (j == i+1) array[i][j] = (s[i] == s[j]); //len=2 base case
                else array[i][j] = (array[i+1][j-1] && s[i] == s[j]);  //above loop made sure that array[i+1][j-1] is calculated before array[i][j]
            }
        }

        for (int i =0 ; i < n; i++){
            for (int j =0; j < n; j++){
                cout<<array[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
};
