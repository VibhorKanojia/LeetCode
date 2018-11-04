#include <iostream>
#include <vector>
using namespace std;


// [2,3,5,8,7]
// K = 2
// []
// [2],[3],[5],[8],[7],             
// [2,3],[3,5],[5,8],[8,7],         
// [2,3,5],[3,5,8],[5,8,7],         
// [2,3,5,8]                       
//So answer should be 14


//Time complexity of the solution is O(K*N)

int main(){
    int N;
    cin >> N;
    vector<int> array(N,0);
    for (int i =0 ; i < N; i++){
        cin >> array[i];
    }
    int K;
    cin >> K;
    //DP[i][j] -> number of solutions that END at A[i] and have EXACTLY j odd numbers.
    int ** dp = new int*[N];
    for (int i =0; i < N; i++){
        dp[i] = new int[K+1];
    }

    // sum is initialized to 1 to count the null subarray i.e []
    int sum = 1; 
    
    for (int i = 0; i < N; i++){
        for (int j = 0; j < K+1; j++){
            
            //Case when current element is even
            if (array[i]%2 == 0){
                 
                // this case is handled separately to avoid error while accessing [i-1]
                if (i == 0){
                    dp[i][j] = 0;
                }
                else{
                    // as the current element is even, 
                    // the number of solutions ending at A[i] with j odd numbers are the same as 
                    // the number of solutions ending at A[i-1] with j odd numbers. 
                    dp[i][j] = dp[i-1][j];
                }

                // if j == 0, then we also need to include the solution that has just the current even element
                if (j == 0) dp[i][j]++;
                
            }

            else{ 
                //Again, this case is handled separately to avoid error while accessing [i-1] or [j-1]
                if (i == 0 || j == 0){
                    dp[i][j] = 0;
                }

                // as the current element is odd,
                // the number of solutions ending at A[i] with j odd numbers are the same as 
                // the number of solutions ending at A[i-1] with j-1 odd numbers.
                else{
                    dp[i][j] = dp[i-1][j-1];
                }

                // if j == 1, then we also need to include the solution that has just the current odd element.
                if (j == 1) dp[i][j]++;
            }
            
       }
   }
    
    
    for (int i = 0 ; i < N; i++){
        for (int j = 0; j < K+1; j++){
            cout<<dp[i][j]<<" ";
            sum +=dp[i][j];
        }
        cout<<endl;
    }
    cout<<sum<<endl;
    
    return 0;

}
