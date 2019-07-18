// 310. Minimum Height Trees


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<unordered_set<int>> in_nodes(n);
		for (int i = 0; i < edges.size(); ++i) {
			in_nodes[edges[i][0]].insert(edges[i][1]);
			in_nodes[edges[i][1]].insert(edges[i][0]);
		}
		vector<int> leaves;
		if (n == 1) {
			leaves.push_back(0);
			return leaves;
		}
		for (int i = 0; i < n; ++i)
			if (in_nodes[i].size() == 1)
				leaves.push_back(i);
		while (n > 2) {
			n -= leaves.size();
			vector<int> next_leaves;
			for (int leaf : leaves) {
				for (int connected_node : in_nodes[leaf]) {
					in_nodes[connected_node].erase(leaf);
					if (in_nodes[connected_node].size() == 1)
						next_leaves.push_back(connected_node);
				}
			}
			leaves = next_leaves;
		}
		return leaves;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<int>> testcase = { { 0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4} };
//	int k = 6;
//	
//	vector<int> ans = s.findMinHeightTrees(k, testcase);
//
//	for (int n : ans)
//		cout << n << ' ';
//	cout << endl;
//
//	system("pause");
//	return 0;
//}