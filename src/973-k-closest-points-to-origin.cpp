// 973. K Closest Points to Origin


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
		sort_k(points, 0, points.size() - 1, K);
		vector<vector<int>> result(points.begin(), points.begin() + K);
		return result;
	}
private:
	void sort_k(vector<vector<int>>& points, int left, int right, int K) {
		if (left >= right)
			return;
		int pivot_idx = partition(points, left, right);
		int left_part_size = pivot_idx - left;
		if (left_part_size + 1 < K) {
			sort_k(points, pivot_idx + 1, right, K - left_part_size - 1);
		}
		else if (left_part_size > K) {
			sort_k(points, left, pivot_idx - 1, K);
		}
		else {
			return;
		}
	}

	int partition(vector<vector<int>>& points, int left, int right) {
		int pivot = get_distance(points[left]);
		int i = left, j = right + 1;
		while (true) {
			while (get_distance(points[++i]) < pivot)
				if (i == right)
					break;
			while (get_distance(points[--j]) > pivot)
				if (j == left)
					break;
			if (i >= j)
				break;
			swap(points, i, j);
		}
		swap(points, left, j);
		return j;
	}

	int get_distance(const vector<int>& p) {
		return p[0] * p[0] + p[1] * p[1];  // sqrt() or not dose NOT matter here
	}

	void swap(vector<vector<int>>& points, int i, int j) {
		vector<int> temp = points[i];
		points[i] = points[j];
		points[j] = temp;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> testcase = { { 5,-3 },{3,-4 },{ -2,9 },{-8, -8},{ -6,5 },{ 6,1 },{ 5,9 } };
//	//                                 34       25       85      128        61     37      106
//	int k = 6;
//	
//	vector<vector<int>> ans = s.kClosest(testcase, k);
//
//	for (vector<int> p : ans)
//		cout << "(" << p[0] << "," << p[1] << ")" << endl;
//
//	system("pause");
//	return 0;
//}