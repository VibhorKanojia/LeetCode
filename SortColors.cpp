class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = nums.size()-1;
        while (white <= blue){
            if (nums[white] == 0){
                nums[white] = nums[red];
                nums[red] = 0;
                red++;
                white++;
            }
            else if (nums[white] == 1){
                white++;
            }
            else if (nums[white] == 2){
                nums[white] = nums[blue];
                nums[blue] =2;
                blue--;
            }
        }
        return;
    }
};
