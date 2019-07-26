// 1079. Letter Tile Possibilities


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	int numTilePossibilities(string tiles) {
		vector<int> remains(26, 0);
		for (int i = 0; i < tiles.size(); ++i)
			++remains[tiles[i] - 'A'];
		int results = 0;
		string cur_seq = "";
		dfs(cur_seq, remains, results);
		return results;
	}

private:
	void dfs(string cur_seq, vector<int>& remains, int& results) {
		for (int i = 0; i < 26; ++i) {
			if (remains[i] > 0) {
				cur_seq.push_back(remains[i]);
				++results;
				--remains[i];
				dfs(cur_seq, remains, results);
				++remains[i];
				cur_seq.pop_back();
			}
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "AAABBC";
//
//	int ans = s.numTilePossibilities(testcase);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}
