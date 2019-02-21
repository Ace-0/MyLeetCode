#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

bool searchMatrix1(vector<vector<int>>& matrix, int target) {
	// 二分法
	int up = 0, down = matrix.size() - 1;
	if (matrix.empty() || matrix[0].empty()) {
		return false;
	}
	while (up <= down) {
		int mid = (up + down) / 2;
		if (target < matrix[mid][0]) {
			down = mid - 1;
		}
		else if (target > matrix[mid][0]) {
			up = mid + 1;
		}
		else {
			return true;
		}
	}
	for (int r = 0; r <= down; r++) {
		int left = 0, right = matrix[0].size() - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (target < matrix[r][mid]) {
				right = mid - 1;
			}
			else if (target > matrix[r][mid]) {
				left = mid + 1;
			}
			else {
				return true;
			}
		}
	}
	return false;
}

bool searchMatrix2(vector<vector<int>>& matrix, int target) {
	if (matrix.empty()) {
		return false;
	}
	int row = matrix.size() - 1, col = matrix[0].size() - 1;
	int r = row, c = 0;
	while (r >= 0 && c <= col) {
		if (target < matrix[r][c]) {
			r--;
		}
		else if (target > matrix[r][c]) {
			c++;
		}
		else {
			return true;
		}
	}
	return false;
}

int main() {
	vector<vector<int>> matrix;
	int arr1[5] = { 1, 4, 7, 11, 15 };
	int arr2[5] = { 2, 5, 8, 12, 19 };
	int arr3[5] = { 3, 6, 9, 16, 22 };
	int arr4[5] = { 10, 13, 14, 17, 24 };
	int arr5[5] = { 18, 21, 23, 26, 30 };
	matrix.push_back(vector<int>(arr1, arr1 + 5));
	matrix.push_back(vector<int>(arr2, arr2 + 5));
	matrix.push_back(vector<int>(arr3, arr3 + 5));
	matrix.push_back(vector<int>(arr4, arr4 + 5));
	matrix.push_back(vector<int>(arr5, arr5 + 5));
	cout << searchMatrix2(matrix, 19) << endl;
	system("pause");
}






//// ¶þ·Ö
//class Solution {
//public:
//	bool searchMatrix(vector<vector<int> >& matrix, int target) {
//		if (matrix.size() == 0) return false;
//
//		int i, j, mid, rows = matrix.size(), cols = matrix[0].size();
//
//		int limd = rows - 1, limu = 0;
//
//		/*¶þ·Ö²éÕÒÄ¿±êÖµ¿ÉÄÜËùÔÚÐÐµÄÏÂÏÞ*/
//		while (limu < limd)
//		{
//			mid = (limu + limd) / 2;
//			if (matrix[mid][0] > target) limd = mid - 1;
//			else if (matrix[mid][0] < target) limu = mid + 1;
//			else return true;
//		}
//
//		/*¶ÔÃ¿Ò»ÐÐ½øÐÐ¶þ·Ö²éÕÒ*/
//		for (i = 0; i <= limd; i++)
//		{
//			int l = 0, r = cols - 1;
//			while (l <= r)
//			{
//				mid = (l + r) / 2;
//				if (matrix[i][mid] < target) l = mid + 1;
//				else if (matrix[i][mid] > target) r = mid - 1;
//				else return true;
//			}
//		}
//
//		return false;
//	}
//};
//
//// ·ÖÖÎ
//class Solution {
//public:
//	bool searchMatrix(vector<vector<int> >& matrix, int target) {
//		if (matrix.size() == 0) return false;
//
//		int i, j, rows = matrix.size(), cols = matrix[0].size();
//
//		i = 0;
//		j = cols - 1;
//		while (i < rows && j >= 0)
//		{
//			if (matrix[i][j] == target) return true;
//			else if (matrix[i][j] > target) j--;
//			else i++;
//		}
//		return false;
//	}
//};