// 773. Sliding Puzzle


#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
		vector<vector<int>> directions = { {1, 0}, {0, -1}, {-1, 0}, {0, 1} };
		int zero_x = 0, zero_y = 0;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 3; ++j)
				if (board[i][j] == 0) {
					zero_x = i;
					zero_y = j;
				}
		Node* cur_node = new Node(board, zero_x, zero_y);
        queue<Node*> que;
		unordered_set<string> visited;
		que.push(cur_node);
		visited.insert(cur_node->key);
		int step = 0;
		while (!que.empty()) {
			int cur_size = que.size();
			while (cur_size-- > 0) {
				cur_node = que.front();
				que.pop();
				if (is_solved(cur_node)) {
					return step;
				}
				for (int i = 0; i < 4; ++i) {
					int next_x = cur_node->zero_x + directions[i][0];
					int next_y = cur_node->zero_y + directions[i][1];
					if (next_x >= 0 && next_x < 2 && next_y >= 0 && next_y < 3) {
						vector<vector<int>> cur_board = cur_node->board;
						cur_board[cur_node->zero_x][cur_node->zero_y] = cur_board[next_x][next_y];
						cur_board[next_x][next_y] = 0;
						Node* next_node = new Node(cur_board, next_x, next_y);
						if (visited.find(next_node->key) == visited.end()) {
							que.push(next_node);
							visited.insert(next_node->key);
						}
					} 
				}
			}
			++step;
		}
		return -1;
    }
private:
	struct Node {
		vector<vector<int>> board;
		int zero_x;
		int zero_y;
		string key;
		Node(vector<vector<int>>& b, int x, int y): board(b), zero_x(x), zero_y(y) {
			key = "";
			for (int i = 0; i < 3; ++i)
				key += to_string(i) + ":" + to_string(b[0][i]);
			for (int i = 0; i < 3; ++i)
				key += to_string(i) + ":" + to_string(b[1][i]);
		}
	};

	bool is_solved(Node* cur_node) {
		return cur_node->board[0][0] == 1 && cur_node->board[0][1] == 2 && cur_node->board[0][2] == 3
			&& cur_node->board[1][0] == 4 && cur_node->board[1][1] == 5 && cur_node->board[1][2] == 0;
	}
};

// int main() {
// 	Solution s = Solution();

// 	vector<vector<int>> testcase = { {4,1,2}, {5,0,3} };
	
// 	int ans = s.slidingPuzzle(testcase);

// 	cout << ans << endl;

// 	// system("pause");
// 	return 0;
// }