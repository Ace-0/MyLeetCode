// 743. Network Delay Time


#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> canReach(N + 1);
        for (const vector<int>& edge : times) {
            canReach[edge[0]].push_back(pair<int, int>(edge[1], edge[2]));
        }
		priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(const pair<int, int>& a, const pair<int, int>& b)>> priQue(
			[](const pair<int, int>& a, const pair<int, int>& b) -> bool {
				return a.second > b.second;
			}
		);
		vector<int> distTo(N + 1, INT_MAX);
		vector<bool> visited(N + 1, false);
		distTo[K] = 0;
		priQue.push(pair<int, int>(K, distTo[K]));
		while (!priQue.empty()) {
			int curNode = priQue.top().first;
			int curDist = priQue.top().second;
			priQue.pop();
			if (visited[curNode]) {
				continue;
			}
			for (int i = 0; i < canReach[curNode].size(); ++i) {
				int nextNode = canReach[curNode][i].first;
				int nextDist = canReach[curNode][i].second;
				if (curDist + nextDist < distTo[nextNode]) {
					distTo[nextNode] = curDist + nextDist;
					priQue.push(pair<int, int>(nextNode, distTo[nextNode]));
				}
			}
			visited[curNode] = true;
		}
		for (int i = 1; i <= N; ++i) {
			if (!visited[i]) {
				return -1;
			}
		}
		int maxDist = 0;
		for (int i = 1; i <= N; ++i) {
			if (distTo[i] > maxDist) {
				maxDist = distTo[i];
			}
		}
		return maxDist;
    }
};

// class Solution {
// public:
//     int networkDelayTime(vector<vector<int>>& times, int N, int K) {
//         vector<vector<pair<int, int>>> canReach(N + 1);
//         for (const vector<int>& edge : times) {
//             canReach[edge[0]].push_back(pair<int, int>(edge[1], edge[2]));
//         }
//         priority_queue<int, vector<int>, function<bool(const int a, const int b)>> priQue(
// 			[this](const int a, const int b) -> bool {
// 				return this->distTo[a] > this->distTo[b];
// 			}
// 		);
// 		distTo = vector<int>(N + 1, INT_MAX);
// 		vector<bool> visited(N + 1, false);
// 		distTo[K] = 0;
// 		priQue.push(K);
// 		while (!priQue.empty()) {
// 			int curNode = priQue.top();
// 			priQue.pop();
// 			if (visited[curNode]) {
// 				continue;
// 			}
// 			for (int i = 0; i < canReach[curNode].size(); ++i) {
// 				int nextNode = canReach[curNode][i].first;
// 				int nextDist = canReach[curNode][i].second;
// 				if (distTo[curNode] + nextDist < distTo[nextNode]) {
// 					distTo[nextNode] = distTo[curNode] + nextDist;
// 				}
// 			}
// 			visited[curNode] = true;
// 		}
// 		for (int i = 1; i <= N; ++i) {
// 			if (!visited[i]) {
// 				return -1;
// 			}
// 		}
// 		int maxDist = 0;
// 		for (int i = 1; i <= N; ++i) {
// 			if (distTo[i] > maxDist) {
// 				maxDist = distTo[i];
// 			}
// 		}
// 		return maxDist;
//     }
// private:
// 	vector<int> distTo;
// };

// int main() {
// 	Solution s = Solution();

// 	vector<vector<int>> testcase = {{2,1,5},{2,3,10},{3,4,1}};
// 	int N = 4;
// 	int K = 2;
	
// 	int ans = s.networkDelayTime(testcase, N, K);

// 	cout << ans << endl;

// 	return 0;
// }