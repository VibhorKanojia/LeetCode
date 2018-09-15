//BEATS 99%
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
        vector<int> hsl(N,-1);
        vector<int> vsl(M,-1);
        for (int i = 0 ; i < N; i++){
            for (int j = 0; j < M; j++){
                hsl[i] = max(hsl[i], grid[i][j]);
                vsl[j] = max(vsl[j], grid[i][j]);
            }
        }
        int sum = 0;
        for (int i = 0 ; i < N; i++){
            for (int j = 0 ; j < M ; j++){
                sum = sum + min(hsl[i],vsl[j]) - grid[i][j];
            }
        }
        return sum;
    }
};
