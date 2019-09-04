// 286. Walls and Gates


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	void wallsAndGates(vector<vector<int>>& rooms) {
		if (rooms.empty())
			return;
		const int GATE = 0, WALL = -1, INF = 2147483647;
		const vector<vector<int>> directions = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };
		queue<pair<int, int>> points_que;
		for (int i = 0; i < rooms.size(); ++i) {
			for (int j = 0; j < rooms[i].size(); ++j) {
				if (rooms[i][j] == GATE)
					points_que.push(pair<int, int>(i, j));
			}
		}
		const int rows = rooms.size(), cols = rooms[0].size();
		while (!points_que.empty()) {
			int cur_i = points_que.front().first, cur_j = points_que.front().second;
			points_que.pop();
			for (vector<int> d : directions) {
				int next_i = cur_i + d[0], next_j = cur_j + d[1];
				if (0 <= next_i && next_i < rows && 0 <= next_j && next_j < cols && rooms[next_i][next_j] == INF) {
					rooms[next_i][next_j] = rooms[cur_i][cur_j] + 1;
					points_que.push(pair<int, int>(next_i, next_j));
				}
			}
		}
		return;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> testcase = {
//		{ 2147483647, -1, 0, 2147483647 },
//		{ 2147483647, 2147483647, 2147483647 ,-1 },
//		{ 2147483647, -1, 2147483647, -1 },
//		{ 0, -1, 2147483647, 2147483647 }
//	};
//	
//	s.wallsAndGates(testcase);
//
//	for (int i = 0; i < testcase.size(); ++i) {
//		cout << "[ ";
//		for (int j = 0; j < testcase[i].size(); ++j) {
//			cout << testcase[i][j] << " ";
//		}
//		cout << "]" << endl;
//	}
//
//	system("pause");
//	return 0;
//}