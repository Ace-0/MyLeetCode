// 1046. Last Stone Weight


#include <iostream>
#include <vector>
#include <queue>
#include <functional> 


using namespace std;

class Solution {
public:
	int lastStoneWeight(vector<int>& stones) {
		priority_queue<int> sorted_stones(stones.begin(), stones.end());
		while (sorted_stones.size() > 1) {
			int y = sorted_stones.top();
			sorted_stones.pop();
			int x = sorted_stones.top();
			sorted_stones.pop();
			if (x != y) {
				sorted_stones.push(y - x);
			}
		}
		if (sorted_stones.empty())
			return 0;
		else
			return sorted_stones.top();
	}
};
