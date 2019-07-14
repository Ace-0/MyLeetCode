// 241. Different Ways to Add Parentheses


#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		return possible_results(input, 0, input.length() - 1);
	}
private:
	vector<int> possible_results(string& input, int start, int end) {
		string num_str = "";
		vector<int> results;
		for (int i = start; i <= end; ++i) {
			if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
				vector<int> front_results = possible_results(input, start, i - 1);
				vector<int> back_results = possible_results(input, i + 1, end);
				for (int num1 : front_results)
					for (int num2 : back_results)
						if (input[i] == '+')
							results.push_back(num1 + num2);
						else if (input[i] == '-')
							results.push_back(num1 - num2);
						else
							results.push_back(num1 * num2);
			}
		}
		// return the number
		if (results.empty())
			results.push_back(stoi(input.substr(start, end - start + 1)));
		return results;
	}
};

//int main() {
//	Solution s = Solution();
//
//	string testcase = "2*3-4*5";
//	
//	vector<int> ans = s.diffWaysToCompute(testcase);
//
//	cout << "[ ";
//	for (int n : ans)
//		cout << n << " ";
//	cout << "]" << endl;
//	system("pause");
//	return 0;
//}