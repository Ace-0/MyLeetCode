// 454. 4Sum II

#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		int length = A.size();
		unordered_map<int, int> hash_map;
		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < length; ++j) {
				if (hash_map.find(A[i] + B[j]) == hash_map.end())
					hash_map[A[i] + B[j]] = 0;
				hash_map[A[i] + B[j]] += 1;
			}
		}
		int cnt = 0;
		for (int i = 0; i < length; ++i) {
			for (int j = 0; j < length; ++j) {
				int target = 0 - C[i] - D[j];
				if (hash_map.find(target) != hash_map.end())
					cnt += hash_map[target];
			}
		}
		return cnt;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<int> A = { 1, 2 };
//	vector<int> B = { -2, -1 };
//	vector<int>	C = { -1, 2 };
//	vector<int>	D = {0, 2};
//	
//	int ans = s.fourSumCount(A, B, C, D);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}