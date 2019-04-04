// 378. Kth Smallest Element in a Sorted Matrix

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int small = matrix[0][0], large = matrix[n - 1][n - 1];
		while (small < large) {
			int mid = (large - small) / 2 + small;
			int count = countNoLargerThan(mid, n, matrix);
			if (count < k) {
				small = mid + 1;
			}
			else {
				large = mid;
			}
		}
		return small;
	}

	int countNoLargerThan(int x, int n, vector<vector<int>>& matrix) {
		int count = 0;
		for (int i = 0; i < n; ++i) {
			int j = n - 1;
			while (j >= 0 && matrix[i][j] > x)
				j--;
			count += j + 1;
		}
		return count;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> matrix = {
//		{ 1,  5,  9  },
//		{ 10, 11, 13 },
//		{ 12, 13, 15 }
//	};
//	
//	int ans = s.kthSmallest(matrix, 8);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}