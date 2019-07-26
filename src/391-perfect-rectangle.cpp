// 391. Perfect Rectangle


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <unordered_set>

using namespace std;

class Solution {
public:
	bool isRectangleCover(vector<vector<int>>& rectangles) {
		int bottom_left_x = INT_MAX, bottom_left_y = INT_MAX;
		int top_right_x = INT_MIN, top_right_y = INT_MIN;
		int actual_area = 0;
		unordered_set<string> points;
		for (vector<int>& rect : rectangles) {
			bottom_left_x = min(bottom_left_x, rect[0]);
			bottom_left_y = min(bottom_left_y, rect[1]);
			top_right_x = max(top_right_x, rect[2]);
			top_right_y = max(top_right_y, rect[3]);

			actual_area += (rect[2] - rect[0]) * (rect[3] - rect[1]);

			vector<string> point_strs = {
				to_string(rect[0]) + "-" + to_string(rect[1]),
				to_string(rect[0]) + "-" + to_string(rect[3]),
				to_string(rect[2]) + "-" + to_string(rect[3]),
				to_string(rect[2]) + "-" + to_string(rect[1])
			};
			for (string& str : point_strs) {
				unordered_set<string>::iterator it = points.find(str);
				if (it != points.end())
					points.erase(it);
				else
					points.insert(str);
			}
		}
		int expected_area = (top_right_x - bottom_left_x) * (top_right_y - bottom_left_y);
		if (actual_area == expected_area
			&& points.size() == 4
			&& points.find(to_string(bottom_left_x) + "-" + to_string(bottom_left_y)) != points.end()
			&& points.find(to_string(bottom_left_x) + "-" + to_string(top_right_y)) != points.end()
			&& points.find(to_string(top_right_x) + "-" + to_string(top_right_y)) != points.end()
			&& points.find(to_string(top_right_x) + "-" + to_string(bottom_left_y)) != points.end()
			)
			return true;
		else
			return false;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> rectangles = {
//		{1, 1, 3, 3},
//		{3, 1, 4, 2},
//		{3, 2, 4, 4},
//		{1, 3, 2, 4},
//		{2, 3, 3, 4}
//	};
//	bool ans = s.isRectangleCover(rectangles);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}