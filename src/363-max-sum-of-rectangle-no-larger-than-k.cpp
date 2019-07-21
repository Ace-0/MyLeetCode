// 363. Max Sum of Rectangle No Larger Than K


#include <iostream>
#include <vector>
#include <set>
#include <climits>

using namespace std;

// kadane algorithm: https://www.youtube.com/watch?v=-FgseNO-6Gk
// max sum no larger than k: https://www.quora.com/Given-an-array-of-integers-A-and-an-integer-k-find-a-subarray-that-contains-the-largest-sum-subject-to-a-constraint-that-the-sum-is-less-than-k
class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		int rows = matrix.size(), cols = matrix[0].size();
		int max_submatrix_sum = INT_MIN;
		for (int left = 0; left < cols; ++left) {
			// initialize row sums vector
			vector<int> row_sum(rows, 0);
			for (int right = left; right < cols; ++right) {
				// update row sums vector
				for (int r = 0; r < rows; ++r)
					row_sum[r] += matrix[r][right];
				// find max sum no larger than k
				set<int> accu_sum;
				accu_sum.insert(0);
				int cur_accu_sum = 0;
				for (int rs : row_sum) {
					cur_accu_sum += rs;
					set<int>::iterator it = accu_sum.lower_bound(cur_accu_sum - k);
					if (it != accu_sum.end() && (cur_accu_sum - *it) > max_submatrix_sum)
						max_submatrix_sum = cur_accu_sum - *it;
					accu_sum.insert(cur_accu_sum);
				}
			}
		}
		return max_submatrix_sum;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> testcase = {
//		{ 1, 0, 1 },
//		{ 0, -2, 3 }
//	};
//	int k = 2;
//	
//	int ans = s.maxSumSubmatrix(testcase, k);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}