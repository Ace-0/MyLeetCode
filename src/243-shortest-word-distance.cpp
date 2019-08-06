// 243. Shortest Word Distance


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
	int shortestDistance(vector<string>& words, string word1, string word2) {
		int last_first = -1, last_second = -1;
		int min_dist = words.size();
		int i = 0;
		while (i < words.size()) {
			if (words[i] == word1)
				last_first = i;
			else if (words[i] == word2)
				last_second = i;
			if (last_first != -1 && last_second != -1)
				min_dist = min(min_dist, abs(last_first - last_second));
			++i;
		}
		return min_dist;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<string> words = { "practice", "makes", "perfect", "coding", "makes" };
//	string word1 = "coding", word2 = "practice";
//
//	int ans = s.shortestDistance(words, word1, word2);
//
//	cout << ans << endl;
//
//	system("pause");
//	return 0;
//}