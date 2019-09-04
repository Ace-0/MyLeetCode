// 218. The Skyline Problem


#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		priority_queue<pair<int, int>> pri_que;  // <height, end>

		int i = 0, cur_x = 0, cur_h = 0;
		vector<vector<int>> result;

		while (i < buildings.size() || !pri_que.empty()) {
			cur_x = pri_que.empty() ? buildings[i][0] : pri_que.top().second;

			if (i >= buildings.size() || buildings[i][0] > cur_x) {
				while (!pri_que.empty() && pri_que.top().second <= cur_x)
					pri_que.pop();
			}
			else {
				cur_x = buildings[i][0];
				while (i < buildings.size() && buildings[i][0] == cur_x) {
					pri_que.push(pair<int, int>(buildings[i][2], buildings[i][1]));
					++i;
				}
			}

			cur_h = pri_que.empty() ? 0 : pri_que.top().first;
			if (result.empty() || result.back()[1] != cur_h) {
				result.push_back(vector<int>({cur_x, cur_h}));
			}
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> buildings = { {2,9,10},{3,7,15},{5,12,12},{15,20,10},{19,24,8} };
//
//	vector<vector<int>> ans = s.getSkyline(buildings);
//
//	for (auto p : ans) {
//		cout << p[0] << ", " << p[1] << endl;
//	}
//	cout << endl;
//
//	system("pause");
//	return 0;
//}