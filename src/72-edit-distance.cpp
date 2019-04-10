// 72. Edit Distance


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.length(), n = word2.length();
		// pre_dis means i-1, cur_dis means i
		vector<int> pre_dis(n + 1, 0), cur_dis(n + 1, 0);
		for (int j = 1; j <= n; ++j)
			pre_dis[j] = j;
		for (int i = 1; i <= m; ++i) {
			cur_dis[0] = i;
			for (int j = 1; j <= n; ++j) {
				if (word1[i - 1] == word2[j - 1]) {
					cur_dis[j] = pre_dis[j - 1];
				}
				else {
					int insert_cost = cur_dis[j - 1] + 1;
					int delete_cost = 1 + pre_dis[j];
					int replace_cost = pre_dis[j - 1] + 1;
					cur_dis[j] = min(insert_cost, min(delete_cost, replace_cost));
				}
			}
			fill(pre_dis.begin(), pre_dis.end(), 0);
			pre_dis.swap(cur_dis);
		}
		return pre_dis[n];
	}
};

//class Solution {
//public:
//	int minDistance(string word1, string word2) {
//		int m = word1.length(), n = word2.length(); 
//		vector<vector<int>> distance(m + 1, vector<int>(n + 1));
//		// distance[0][k] = k, distance[k][0] = k
//		for (int i = 1; i <= m; ++i)
//			distance[i][0] = i;
//		for (int i = 1; i <= n; ++i)
//			distance[0][i] = i;
//		for (int i = 1; i <= m; ++i) {
//			for (int j = 1; j <= n; ++j) {
//				if (word1[i - 1] == word2[j - 1]) {
//					distance[i][j] = distance[i - 1][j - 1];
//				}
//				else {
//					int insert_cost = distance[i][j - 1] + 1;
//					int delete_cost = 1 + distance[i - 1][j];
//					int replace_cost = distance[i - 1][j - 1] + 1;
//					distance[i][j] = min(insert_cost, min(delete_cost, replace_cost));
//				}
//			}
//		}
//		return distance[m][n];
//	}
//};

//int main() {
//	Solution s = Solution();
//
//	string word1 = "horse", word2 = "ros";
//	
//	int ans = s.minDistance(word1, word2);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}