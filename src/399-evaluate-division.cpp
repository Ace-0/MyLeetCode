// 399. Evaluate Division


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		for (int i = 0; i < equations.size(); ++i) {
			string first = equations[i][0], second = equations[i][1];
			double cur_val = values[i];
			if (parent.find(first) == parent.end() && parent.find(second) == parent.end()) {
				parent[second] = second;
				parent[first] = second;
				relative_val[second] = 1.0;
				relative_val[first] = cur_val;
			}
			else if (parent.find(first) == parent.end()) {
				string root = get_parent(second);
				parent[first] = root;
				relative_val[first] = cur_val * relative_val[second];
			}
			else if (parent.find(second) == parent.end()) {
				string root = get_parent(first);
				parent[second] = root;
				relative_val[second] = relative_val[first] / cur_val;
			}
			else {
				union_two_sets(first, second, cur_val);
			}
		}
		vector<double> result;
		for (vector<string>& q : queries) {
			if (relative_val.find(q[0]) == relative_val.end()
				|| relative_val.find(q[1]) == relative_val.end()
				|| get_parent(q[0]) != get_parent(q[1])
				)
				result.push_back(-1.0);
			else
				result.push_back(relative_val[q[0]] / relative_val[q[1]]);
		}
		return result;
	}

private:
	unordered_map<string, string> parent;
	unordered_map<string, double> relative_val;

	string get_parent(string str) {
		if (parent[str] == str)
			return str;
		parent[str] = get_parent(parent[str]);
		return parent[str];
	}

	void union_two_sets(string s, string t, double cur_val) {
		string s_parent = get_parent(s), t_parent = get_parent(t);
		double ratio = relative_val[s] /  cur_val / relative_val[t];  // actual ratio for t_parent : s_parent
		for (auto it = parent.begin(); it != parent.end(); ++it) {
			if (get_parent(it->first) == t_parent) {
				relative_val[it->first] *= ratio;
			}
		}
		parent[t_parent] = s_parent;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<string>> equations = {
//		{"a", "b"},
//		{"e", "f"},
//		{"b", "e"}
//	};
//	vector<double> values = { 3.4, 1.4, 2.3 };
//
//	vector<vector<string>> queries = {
//		{"b", "a"},{"a", "f"},{"f", "f"},{"e", "e"},{"c", "c"},{"a", "c"},{"f", "e"}
//	};
//	
//	vector<double> ans = s.calcEquation(equations, values, queries);
//
//	for (double a : ans)
//		cout << a << " ";
//	cout << endl;
//
//	system("pause");
//	return 0;
//}