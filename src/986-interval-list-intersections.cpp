// 986. Interval List Intersections


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		int i = 0, j = 0, max_start, min_end;
		vector<vector<int>> result;
		while (i < A.size() && j < B.size()) {
			max_start = max(A[i][0], B[j][0]);
			min_end = min(A[i][1], B[j][1]);
			if (max_start <= min_end) {
				result.push_back(vector<int>({ max_start, min_end }));
			}
			if (A[i][1] < B[j][1])
				++i;
			else
				++j;
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> A({ {0, 2},{5, 10}, {13, 23}, {24, 25} });
//	vector<vector<int>> B({ {1, 5}, {8, 12}, {15, 24}, {25, 26} });
//	
//	vector<vector<int>> ans = s.intervalIntersection(A, B);
//
//	for (vector<int> itv : ans) {
//		cout << "[" << itv[0] << ", " << itv[1] << "] ";
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}