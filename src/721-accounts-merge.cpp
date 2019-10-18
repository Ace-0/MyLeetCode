// 721. Accounts Merge


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
		id = vector<int>(10001);
        for (int i = 0; i < 10001; ++i)
			id[i] = i;
		
		unordered_map<string, int> id_of_email;
		unordered_map<int, string> owner_of_email;
		int e_id = 0;
		for (vector<string> account : accounts) {
			string name = account[0];
			for (int i = 1; i < account.size(); ++i) {
				string email = account[i];
				if (id_of_email.find(email) == id_of_email.end()) {
					id_of_email[email] = e_id;
					++e_id;
				}
				owner_of_email[id_of_email[email]] = name;
				union_func(id_of_email[account[1]], id_of_email[email]);
			}
		}

		unordered_map<int, vector<string>> emails_of_root_id;
		for (pair<string, int> id_email : id_of_email) {
			int root_id = find(id_email.second);
			// if (emails_of_id.find(root_id) == emails_of_id.end())
			emails_of_root_id[root_id].push_back(id_email.first);
		}

		vector<vector<string>> result;
		for (pair<int, vector<string>> p : emails_of_root_id) {
			vector<string> vec;
			vec.push_back(owner_of_email[p.first]);
			for (string email : p.second)
				vec.push_back(email);
			sort(vec.begin(), vec.end());
			result.push_back(vec);
		}

        return result;
    }
private:
	void union_func(int x, int y) {
		id[find(x)] = find(y);
	}

	int find(int x) {
		if (id[x] != x)
			id[x] = find(id[x]);
		return id[x];
	}

	vector<int> id;
};

// int main() {
// 	Solution s = Solution();

// 	vector<vector<string>> accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
	
// 	vector<vector<string>> ans = s.accountsMerge(accounts);

// 	for (vector<string> acc : ans) {
//         cout << acc[0] << ":";
//         for (int i = 1; i < acc.size(); ++i)
//             cout << acc[i] << ", ";
//         cout << endl;
//     }

// 	return 0;
// }