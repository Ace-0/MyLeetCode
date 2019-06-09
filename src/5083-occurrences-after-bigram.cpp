// 5083. Occurrences After Bigram


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> findOcurrences(string text, string first, string second) {
		vector<string> words;
		string cur_word = "";
		for (int i = 0; i < text.length(); ++i) {
			if (text[i] == ' ') {
				words.push_back(cur_word);
				cur_word.clear();
			}
			else {
				cur_word += text[i];
			}
		}
		words.push_back(cur_word);

		vector<string> result;
		for (int i = 0; i < words.size() - 2; ++i) {
			if (words[i] == first && words[i + 1] == second) {
				result.push_back(words[i + 2]);
			}
		}
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "we will we will rock you";
//
//	vector<string> ans = s.findOcurrences(testcase, "we", "will");
//
//	for (string str : ans)
//		cout << str << endl;
//
//	system("pause");
//	return 0;
//}
