/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */


/**
 * BFS version
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	if (!node) {
		return NULL;
	}
	map<int, UndirectedGraphNode*> node_map;
	node_map[node->label] = new UndirectedGraphNode(node->label);
	queue<UndirectedGraphNode*> que;
	que.push(node);
	while (!que.empty()) {
		UndirectedGraphNode* temp = que.front();
		que.pop();
		for (int i = 0; i < temp->neighbors.size(); i++) {
			UndirectedGraphNode* neighbor = temp->neighbors[i];
			if (node_map[neighbor->label] == NULL) {
				node_map[neighbor->label] = new UndirectedGraphNode(neighbor->label);
				que.push(neighbor);
			}
			node_map[temp->label]->neighbors.push_back(node_map[neighbor->label]);
		}
	}
	return node_map[node->label];
    }
};

/**
 * DFS version
 */
class Solution {

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
	    if (!node) {
    		return NULL;
	    }
	    node_map[node->label] = new UndirectedGraphNode(node->label);
	    dfs(node);
	    return node_map[node->label];
    }
private:
    map<int, UndirectedGraphNode*> node_map;
    void dfs(UndirectedGraphNode* &node) {
	    for (int i = 0; i < node->neighbors.size(); i++) {
	    	UndirectedGraphNode* neighbor = node->neighbors[i];
	    	if (node_map[neighbor->label] == NULL) {
	    		node_map[neighbor->label] = new UndirectedGraphNode(neighbor->label);
	    		dfs(neighbor);
	    	}
	    	node_map[node->label]->neighbors.push_back(node_map[neighbor->label]);
	    }
    }
};
