class Solution {
public:
	// bfs
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		int* preCourses = new int[numCourses] {0};
		bool** preTable = new bool*[numCourses];
		for (int i = 0; i < numCourses; i++) {
			preTable[i] = new bool[numCourses];
			for (int j = 0; j < numCourses; j++) {
				preTable[i][j] = false;
			}
		}
		for (int i = 0; i < prerequisites.size(); i++) {
			preCourses[prerequisites[i].first]++;
			preTable[prerequisites[i].first][prerequisites[i].second] = true;
		}

		queue<int> que;
		int coursesLeft = numCourses;
		for (int i = 0; i < numCourses; i++) {
			if (preCourses[i] == 0) {
				que.push(i);
				coursesLeft--;
			}
		}
		while (!que.empty()) {
			int curCouse = que.front();
			que.pop();
			for (int i = 0; i < numCourses; i++) {
				if (preTable[i][curCouse]) {
					preCourses[i]--;
					if (preCourses[i] == 0) {
						que.push(i);
						coursesLeft--;
					}
				}
			}
		}
		if (coursesLeft == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	// dfs
}; 