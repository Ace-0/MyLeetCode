class Solution {
public:
int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int size = nums.size() - 2;
    int** matrix = new int*[size + 2];
    for (int i = 0; i < size + 2; i++) {
        matrix[i] = new int[size + 2];
    }
    for (int i = 0; i < size + 2; i++) {
        for (int j = 0; j < size + 2; j++)
            matrix[i][j] = 0;
    }
    for (int len = 1; len <= size; len++) {
        for (int left = 1; left <= size - len + 1; left++) {
            int right = left + len - 1;
            for (int k = left; k <= right; k++) {
                int leftCoins = k > left ? matrix[left][k - 1] : 0;  // left == k-1 时没有左子区间
                int rightCoins = k < right ? matrix[k + 1][right] : 0;  // right == k+1 时没有右子区间
                matrix[left][right] = std::max(matrix[left][right], nums[left - 1] * nums[k] * nums[right + 1] + leftCoins + rightCoins);
            }
        }
    }
    return matrix[1][size];
}
};