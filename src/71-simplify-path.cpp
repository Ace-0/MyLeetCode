// 71. Simplify Path


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		vector<string> dirs;
		string cur_dir = "";
		path += "/";  // a little trick
		for (int i = 0; i < path.length(); ++i) {
			if (path[i] == '/') {
				if (cur_dir.length() == 0 || (cur_dir.length() == 1 && cur_dir[0] == '.')) {
					cur_dir = "";
				}
				else if (cur_dir.length() == 2 && cur_dir[0] == '.' && cur_dir[1] == '.') {
					if (!dirs.empty())
						dirs.pop_back();
					cur_dir = "";
				}
				else {
					dirs.push_back(cur_dir);
					cur_dir = "";
				}
			}
			else {
				cur_dir += path[i];
			}
		}
		string result = "";
		for (int i = 0; i < dirs.size(); ++i)
			result += "/" + dirs[i];
		if (result == "")
			result += "/";
		return result;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<string> testcase = { "/home/", "/../", "/home//foo/", "/a/./b/../../c/", "/a/../../b/../c//.//", "/a//b////c/d//././/..", "/...", "/..hidden" };
//
//	for (int i = 0; i < testcase.size(); ++i)
//		cout << s.simplifyPath(testcase[i]) << endl;
//
//	system("pause");
// 	return 0;
//}