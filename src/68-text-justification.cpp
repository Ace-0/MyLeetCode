// 68. Text Justification


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> result;
		if (words.size() == 0)
			return result;
		int line_start = 0, line_end = 0, line_words_len = 0;
		for (int i = 0; i < words.size(); ++i) {
			if (line_words_len == 0) {
				line_words_len += words[i].length();
				line_start = i;
				line_end = i;
			}
			else {
				if (line_words_len + line_end - line_start + 1 + words[i].length() <= maxWidth) {
					line_words_len += words[i].length();
					line_end = i;
				}
				else {
					int total_space = maxWidth - line_words_len, avg_space = 0, extra_space = 0, back_space = 0;
					if (line_end == line_start) {
						// only one word
						avg_space = total_space;
						extra_space = 0;
						back_space = maxWidth - words[line_end].length();
					}
					else {
						avg_space = total_space / (line_end - line_start);
						extra_space = total_space % (line_end - line_start);
						back_space = 0;
					}
					string line = "";
					for (int j = line_start; j < line_end; ++j) {
						line += words[j];
						line += string(avg_space, ' ');
						if (extra_space > 0) {
							line += " ";
							--extra_space;
						}
					}
					line += words[line_end];
					line += string(back_space, ' ');
					result.push_back(line);
					line_words_len = 0;
					--i;
				}
			}
		}
		// deal with the last line
		// if it is already stored in result;
		if (line_words_len == 0)
			result.pop_back();
		string line = "";
		for (int i = line_start; i < line_end; ++i)
			line += words[i] + " ";
		line += words[line_end];
		while (line.length() < maxWidth)
			line += " ";
		result.push_back(line);

		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	//vector<string> testcase = { "What","must","be","acknowledgment","shall","be" };
//	//int maxWidth = 16;	
//	vector<string> testcase = { "Science", "is", "what", "we", "understand", "well", "enough", "to", "explain", "to", "a", "computer.", "Art", "is", "everything", "else", "we", "do" };
//	int maxWidth = 20;
//
//	vector<string> ans = s.fullJustify(testcase, maxWidth);
//
//	for (string line : ans)
//		cout << "\"" << line << "\"" << endl;
//
//	system("pause");
//	return 0;
//}