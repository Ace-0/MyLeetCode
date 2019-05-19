// 1042. Flower Planting With No Adjacent


#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
	vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
		vector<vector<int>> graph(N + 1, vector<int>());
		for (vector<int> path : paths) {
			graph[path[0]].push_back(path[1]);
			graph[path[1]].push_back(path[0]);
		}
		vector<int> ans;
		for (int i = 1; i <= N; ++i) {
			int color = 0;
			bool used = true;
			while (used) {
				++color;
				used = false;
				for (int j = 0; j < graph[i].size(); ++j) {
					if (graph[i][j] < i && ans[graph[i][j] - 1] == color)
						used = true;
				}
			}
			ans.push_back(color);
		}

		return ans;
	}
};

//int main() {
//	Solution s = Solution();
//
//	int N = 4;
//	vector<vector<int>> testcase = { {1,2}, {2,3}, {3,4}, {4,1}, {1,3}, {2,4} };
//	//vector<vector<int>> testcase = { {1,2}, {3,4} };
//
//	vector<int> ans = s.gardenNoAdj(4, testcase);
//
//	for (int n : ans)
//		cout << n << ' ';
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
