// 787. Cheapest Flights Within K Stops


#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <functional>

using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        // build adjacent matrix
		vector<vector<int>> adjMatrix(n, vector<int>(n, -1));
		for (const vector<int>& f : flights) {
			adjMatrix[f[0]][f[1]] = f[2];
		}
		// store distTo in a priority queue: { vertex, distance, stopCnt }
		priority_queue<vector<int>, vector<vector<int>>, function<bool(const vector<int>&, const vector<int>&)>> priQue(
			[](const vector<int>& a, const vector<int>& b) -> bool {
				return a[1] > b[1];
			}
		);
		// dijkstra withou visited array (because of the constrain of K stops)
		priQue.push(vector<int>{ src, 0, -1 });
		while (!priQue.empty()) {
			int stop = priQue.top()[0];
			int cost = priQue.top()[1];
			int k = priQue.top()[2];
			priQue.pop();
			if (k > K) {
				continue;
			}
			if (stop == dst) {
				return cost;
			}
			for (int i = 0; i < n; ++i) {
				if (adjMatrix[stop][i] != -1) {
					priQue.emplace(vector<int>{ i, cost + adjMatrix[stop][i], k + 1 });
				}
			}
		}
		return -1;
    }
};

// int main() {
// 	Solution s = Solution();

// 	int n = 3;
//  	vector<vector<int>> flights = { {0,1,100}, {1,2,100}, {0,2,500} };
// 	int src = 0;
// 	int dst = 2;
// 	int K = 1;
	
// 	int ans = s.findCheapestPrice(n, flights, src, dst, K);

// 	cout << ans << endl;

// 	return 0;
// }