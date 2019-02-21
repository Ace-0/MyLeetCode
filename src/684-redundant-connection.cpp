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

vector<int> findRedundantConnection(vector<vector<int>>& edges) {
	for (int i = 1; i <= 1000; i++) {
		father[i] = i;
	}
	vector<int> result;
	for (auto it = edges.begin(); it != edges.end(); it++) {
		int aFather = getFather(it->at(0));
		int bFather = getFather(it->at(1));
		if (aFather != bFather) {
			father[bFather] = aFather;
		}
		else {
			result.clear();
			result.push_back(it->at(0));
			result.push_back(it->at(1));
		}
	}
	return result;
}
};