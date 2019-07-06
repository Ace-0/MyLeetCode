// 93. Restore IP Addresses


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		string restored = "";
		vector<string> results;
		dfs(0, 0, restored, s, results);
		return results;
	}
private:
	void dfs(int start, int byte_cnt, string restored, string& digits, vector<string>& results) {
		if (byte_cnt > 4)
			return;
		if (start == digits.length()){
			if (byte_cnt == 4)
				results.push_back(restored);
			return;
		}
		string cur_ip = "";
		for (int i = start; i < start + 3 && i < digits.length(); ++i) {
			cur_ip += digits[i];
			if (stoi(cur_ip) > 255 || (cur_ip.length() > 1 && cur_ip[0] == '0'))
				continue;
			if (restored == "") {
				restored += cur_ip;
				dfs(i + 1, byte_cnt + 1, restored, digits, results);
				restored = restored.substr(0, restored.length() - cur_ip.length());
			}
			else {
				restored += ".";
				restored += cur_ip;
				dfs(i + 1, byte_cnt + 1, restored, digits, results);
				restored = restored.substr(0, restored.length() - cur_ip.length() - 1);
			}
		}
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "010010";
//	
//	vector<string> ans = s.restoreIpAddresses(testcase);
//
//	for (string ip : ans) {
//		cout << "\"" << ip << "\"" << endl;
//	}
//
//	system("pause");
//	return 0;
//}