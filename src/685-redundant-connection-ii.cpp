class Solution {
public:
int father[1001] = { 0 };

int getFather(int node) {
	if (father[node] == node) {
		return node;
	}
	else {
		int nodeFather = getFather(father[node]);
		father[node] = nodeFather;
		return nodeFather;
	}
}

vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
	for (int i = 1; i <= 1000; i++) {
		father[i] = i;
	}
	vector<int> resultA, resultB;
	int parent[1001] = { 0 };
	for (auto it = edges.begin(); it != edges.end(); it++) {
		if (parent[it->at(1)] == 0) {
			parent[it->at(1)] = it->at(0);
		}
		else {
			resultA.push_back(parent[it->at(1)]);
			resultA.push_back(it->at(1));
			resultB.push_back(it->at(0));
			resultB.push_back(it->at(1));
			it->clear();
		}
	}
 	
	for (auto it = edges.begin(); it != edges.end(); it++) {
		if (it->empty()) {
			continue;
		}
		int aFather = getFather(it->at(0));
		int bFather = getFather(it->at(1));
		if (aFather == it->at(1)) {
			if (resultA.empty()) {
				return *it;
			}
			else {
				return resultA;
			}
		}
		father[bFather] = aFather;
	}
	return resultB;
}

};