class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long missNum = 1, index = 0, toAddN = 0;
        while (missNum <= n) {
            if (index < nums.size() && nums[index] <= missNum) {
                missNum += nums[index];
                index++;
            }
            else {
                toAddN++;
                missNum *= 2;
            }
        }
        return toAddN;   
    }
};