// 1057. Campus Bikes


#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;


class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
		int workerCnt = workers.size();
        int bikesCnt = bikes.size();
		vector<priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare>> matchings(workerCnt, priority_queue<pair<int, int>, vector<pair<int, int>>, MyCompare>());
		for (int i = 0; i < workerCnt; ++i) {
			for (int j = 0; j < bikesCnt; ++j) {
				int wx = workers[i][0], wy = workers[i][1];
				int bx = bikes[j][0], by = bikes[j][1];
				int distance = abs(wx - bx) + abs(wy - by);
				matchings[i].push(pair<int, int>(j, distance));
			}
		}
		int availWorkerCnt = workerCnt;
		vector<bool> workerAvail(workerCnt, true);
		vector<bool> bikeAvail(bikesCnt, true);
		vector<int> result(workerCnt, 0);
		while (availWorkerCnt != 0) {
			int minI = -1, minDis = INT_MAX;
			for (int i = 0; i < workerCnt; ++i) {
				if (workerAvail[i]) {
					while (!matchings[i].empty() && !bikeAvail[matchings[i].top().first]) {
						matchings[i].pop();
					}
					if (matchings[i].top().second < minDis) {
						minI = i;
						minDis = matchings[i].top().second;
					}
				}
			}
			workerAvail[minI] = false;
			bikeAvail[matchings[minI].top().first] = false;
			result[minI] = matchings[minI].top().first;
			--availWorkerCnt;
		}
		return result;
    }
private:
	struct MyCompare {
		bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
			if (a.second == b.second)
				return a.first > b.first;
			else
				return a.second > b.second;
		}
	};
};


// int main() {
// 	Solution s = Solution();

// 	vector<vector<int>> workers = {
// 		{0,0},
// 		{1,1},
// 		{2,0}
// 	};
// 	vector<vector<int>> bikes = {
// 		{1,0},
// 		{2,2},
// 		{2,1}
// 	};
	
// 	vector<int> ans = s.assignBikes(workers, bikes);

// 	for (int n : ans) {
// 		cout << n << " ";
// 	}
// 	cout << endl;

// 	return 0;
// }