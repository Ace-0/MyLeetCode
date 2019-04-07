// 36. Valid Sudoku

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

// brute  20ms 11.1MB
class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		vector<vector<bool>> n_exist_in_row(10, vector<bool>(9, false));
		vector<vector<bool>> n_exist_in_column(10, vector<bool>(9, false));
		vector<vector<bool>> n_exist_in_block(10, vector<bool>(9, false));
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					int num = board[i][j] - '0';
					int block_index = i / 3 * 3 + j / 3;
					if (n_exist_in_row[num][i]
						|| n_exist_in_column[num][j]
						|| n_exist_in_block[num][block_index])
						return false;
					n_exist_in_row[num][i] = true;
					n_exist_in_column[num][j] = true;
					n_exist_in_block[num][block_index] = true;
				}
			}
		}
		return true;
	}
};

//// using string  24ms 11.5MB
//class Solution {
//public:
//	bool isValidSudoku(vector<vector<char>>& board) {
//		unordered_set<string> exist;
//		for (int i = 0; i < 9; ++i) {
//			for (int j = 0; j < 9; ++j) {
//				if (board[i][j] != '.') {
//					// "cnx" means n in row x
//					// "rnx" means n in colunm x
//					// "bnx" means n in block x
//					int block_index = i / 3 * 3 + j / 3;
//					string row_str = "c";
//					row_str += board[i][j] + to_string(i);
//					string col_str = "r";
//					col_str += board[i][j] + to_string(j);
//					string blk_str = "b";
//					blk_str += board[i][j] + to_string(block_index);
//					if (exist.find(row_str) != exist.end()
//						|| exist.find(col_str) != exist.end()
//						|| exist.find(blk_str) != exist.end()
//						) {
//						return false;
//					}
//					exist.insert(row_str);
//					exist.insert(col_str);
//					exist.insert(blk_str);
//				}
//			}
//		}
//		return true;
//	}
//};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<char>> testcase = {
//		{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
//		{'6', '.', '.', '1', '9', '5', '.', '.', '.'},
//		{'.', '9', '8', '.', '.', '.', '.', '6', '.'},
//		{'8', '.', '.', '.', '6', '.', '.', '.', '3'},
//		{'4', '.', '.', '8', '.', '3', '.', '.', '1'},
//		{'7', '.', '.', '.', '2', '.', '.', '.', '6'},
//		{'.', '6', '.', '.', '.', '.', '2', '8', '.'},
//		{'.', '.', '.', '4', '1', '9', '.', '.', '5'},
//		{'.', '.', '.', '.', '8', '.', '.', '7', '9'}
//	};
//	
//	int ans = s.isValidSudoku(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}