// 332. Reconstruct Itinerary


#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<string> findItinerary(vector<vector<string>>& tickets) {
		map<string, vector<string>> graph;
		for (int i = 0; i < tickets.size(); ++i) {
			if (graph.find(tickets[i][0]) == graph.end())
				graph[tickets[i][0]] = vector<string>();
			graph[tickets[i][0]].push_back(tickets[i][1]);
		}

		map<string, vector<bool>> used;
		for (auto it = graph.begin(); it != graph.end(); ++it) {
			sort(it->second.begin(), it->second.end());
			used[it->first] = vector<bool>(it->second.size(), false);
		}

		int total_num = tickets.size() + 1;
		vector<string> itinerary;
		itinerary.push_back("JFK");
		dfs("JFK", itinerary, graph, used, total_num);
		return itinerary;
	}

private:
	bool dfs(string cur_airport, vector<string>& itinerary, map<string, vector<string>>& graph, map<string, vector<bool>>& used, const int total_num) {
		if (itinerary.size() == total_num)
			return true;
		for (int i = 0; i < graph[cur_airport].size(); ++i) {
			if (used[cur_airport][i] == false) {
				string to = graph[cur_airport][i];
				itinerary.push_back(to);
				used[cur_airport][i] = true;
				if (dfs(to, itinerary, graph, used, total_num))
					return true;
				itinerary.pop_back();
				used[cur_airport][i] = false;
			}
		}
		return false;
	}
};

//int main() {
//	Solution s = Solution();
//
//	vector<vector<string>> testcase = { {"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"} };
//	
//	vector<string> ans = s.findItinerary(testcase);
//
//	cout << "{ ";
//	for (string from_to : ans)
//		cout << from_to << " ";
//	cout << "}" << endl;
//
//	system("pause");
//	return 0;
//}