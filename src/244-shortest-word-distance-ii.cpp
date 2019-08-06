// 244. Shortest Word Distance II


#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <cmath>
#include <algorithm>

using namespace std;

class WordDistance {
public:
	WordDistance(vector<string>& words) {
		for (int i = 0; i < words.size(); ++i)
			positions[words[i]].push_back(i);
	}

	int shortest(string word1, string word2) {
		vector<int> vec1 = positions[word1], vec2 = positions[word2];
		int i = 0, j = 0, min_dist = abs(vec1[0] - vec2[0]);
		while (i < vec1.size() && j < vec2.size()) {
			if (vec1[i] < vec2[j] && i < vec1.size() - 1)
				++i;
			else if (vec1[i] > vec2[j] && j < vec2.size() - 1)
				++j;
			else
				return min_dist;
			min_dist = min(min_dist, abs(vec1[i] - vec2[j]));
		}
		return min_dist;
	}
private:
	unordered_map<string, vector<int>> positions;
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */

//int main() {
//	vector<string> words = { "practice", "makes", "perfect", "coding", "makes" };
//
//	WordDistance wd = WordDistance(words);
//
//	cout << wd.shortest("coding", "practice") << endl;
//	cout << wd.shortest("makes", "coding") << endl;
//
//	system("pause");
//	return 0;
//}