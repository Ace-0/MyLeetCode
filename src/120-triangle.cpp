class Solution {
public:
    int getIndex(int row, int num) {
        return (row * (row + 1) / 2 + num);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int rowNum = triangle.size();
        int totalNum = rowNum * (rowNum + 1) / 2;
        int* minValue = new int[totalNum] { 0 };
        minValue[0] = triangle[0][0];
        for (int row = 1; row < rowNum; row++) {
            for (int num = 0; num < triangle[row].size(); num++) {
                int left = 200000, right = 200000;
                if (num - 1 >= 0) {
                    left = minValue[getIndex(row - 1, num - 1)] + triangle[row][num];
                }
                if (num <= row - 1) {
                    right = minValue[getIndex(row - 1, num)] + triangle[row][num];
                }
                minValue[getIndex(row, num)] = left < right ? left : right;
            }
        }
        int min = 200000;
        for (int i = 0; i < rowNum; i++) {
            if (minValue[getIndex(rowNum - 1, i)] < min) {
                min = minValue[getIndex(rowNum - 1, i)];
            }
        }
        return min;
    }
};

class Solution {
public:
int minimumTotal(vector<vector<int> > &triangle) {
    int n = triangle.size();
    vector<int> minlen(triangle.back());
    for (int layer = n-2; layer >= 0; layer--) // For each layer
    {
        for (int i = 0; i <= layer; i++) // Check its every 'node'
        {
            // Find the lesser of its two children, and sum the current value in the triangle with it.
            minlen[i] = min(minlen[i], minlen[i+1]) + triangle[layer][i]; 
        }
    }
    return minlen[0];
}
};