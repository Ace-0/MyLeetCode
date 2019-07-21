// 5087. Letter Tile Possibilities


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
		unordered_map<int, unordered_set<int>> red_graph, blue_graph;
		for (vector<int>& pair : red_edges)
			red_graph[pair[0]].insert(pair[1]);
		for (vector<int>& pair : blue_edges)
			blue_graph[pair[0]].insert(pair[1]);
		
		queue<Node> que;
		vector<bool> red_visited(n, false), blue_visited(n, false);  // get here through a red/blue edge
		vector<int> result(n, INT_MAX);

		for (int to : red_graph[0]) {
			result[to] = 1;
			que.push(Node(to, 1, false));
			red_visited[to] = true;
		}
		for (int to : blue_graph[0]) {
			result[to] = 1;
			que.push(Node(to, 1, true));
			blue_visited[to] = true;
		}
		while (!que.empty()) {
			Node cur_node = que.front();
			que.pop();
			if (cur_node.next_path_color) {
				for (int to : red_graph[cur_node.val])
					if (!red_visited[to]) {
						result[to] = min(result[to], cur_node.step + 1);
						que.push(Node(to, cur_node.step + 1, false));
						red_visited[to] = true;
					}
			}
			else {
				for (int to : blue_graph[cur_node.val]) 
					if (!blue_visited[to]) {
						result[to] = min(result[to], cur_node.step + 1);
						que.push(Node(to, cur_node.step + 1, true));
						blue_visited[to] = true;
					}
			}
		}

		for (int i = 0; i < n; ++i)
			if (result[i] == INT_MAX)
				result[i] = -1;
		result[0] = 0;
		return result;
	}
private:
	struct Node {
		int val;
		int step;
		bool next_path_color;    // next path required: true for red, false for blue
		Node(int v, int s, int npc): val(v), step(s), next_path_color(npc) {}
	};
};

//int main() {
//	Solution s = Solution();
//
//	int n = 3;
//	//vector<vector<int>> red_edges = { {0,1},{1,2} };
//	//vector<vector<int>> blue_edges = { };
//	//vector<vector<int>> red_edges = { {0,1} };
//	//vector<vector<int>> blue_edges = { {2,1} };
//	//vector<vector<int>> red_edges = { {1,0} };
//	//vector<vector<int>> blue_edges = { {2,1} };
//	//vector<vector<int>> red_edges = { {0,1} };
//	//vector<vector<int>> blue_edges = { {1,2} };
//	//vector<vector<int>> red_edges = { {0,1},{0,2} };
//	//vector<vector<int>> blue_edges = { {1,0} };
//
//
//	vector<int>  ans = s.shortestAlternatingPaths(n, red_edges, blue_edges);
//
//	for (int n : ans)
//		cout << n << " ";
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
