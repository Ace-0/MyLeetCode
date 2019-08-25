// 311. Sparse Matrix Multiplication


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int rows = A.size(), tmp = B.size(), cols = B[0].size();
		unordered_set<int> hash_table;
        vector<vector<int>> result(rows, vector<int>(cols, 0));
		for (int i = 0; i < rows; ++i) {
			bool all_zeroes = true;
			for (int j = 0; j < tmp; ++j) {
				if (A[i][j] != 0)
					all_zeroes = false;
			}
			if (all_zeroes)
				hash_table.insert(i);
		}
		for (int j = 0; j < cols; ++j) {
			for (int i = 0; i < rows; ++i) {
				if (hash_table.find(i) == hash_table.end()) {
					for (int k = 0; k < tmp; ++k)
						result[i][j] += A[i][k] * B[k][j];
				}
			}
		}
		return result;
    }
};