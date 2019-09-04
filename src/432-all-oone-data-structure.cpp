// 432. All O`one Data Structure


#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class AllOne {
public:
	/** Initialize your data structure here. */
	AllOne() {}

	/** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
	void inc(string key) {
		list<Node>::iterator ori_it;
		// if key not exists, create a dummy node with value 0
		if (hash_map.find(key) == hash_map.end())
			ori_it = link_list.insert(link_list.begin(), Node(0));
		else
			ori_it = hash_map[key];

		list<Node>::iterator next_it = ori_it;
		++next_it;
		int ori_val = ori_it->val;
		
		// remove key from its original node
		ori_it->keys.erase(key);
		if (ori_it->keys.empty())
			link_list.erase(ori_it);

		// put key into node[ori_val + 1]
		// if not exists, create one first
		int next_val = ori_val + 1;
		if (next_it == link_list.end() || next_it->val != next_val)
			next_it = link_list.insert(next_it, Node(next_val));
		next_it->keys.insert(key);
		hash_map[key] = next_it;
	}

	/** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
	void dec(string key) {
		if (hash_map.find(key) == hash_map.end())
			return;

		list<Node>::iterator ori_it = hash_map[key];
		int ori_val = ori_it->val;
		
		// remove key from its original node
		ori_it->keys.erase(key);
		if (ori_it->keys.empty())
			ori_it = link_list.erase(ori_it);

		// put key into node[ori_val - 1]
		// if (ori_val - 1 == 0) do nothing
		// if not exists, create one first
		int pre_val = ori_val - 1;
		list<Node>::iterator pre_it = ori_it;
		if (ori_val != 1) {
			if (ori_it == link_list.begin() || (--pre_it)->val != pre_val)
				pre_it = link_list.insert(ori_it, Node(pre_val));
			pre_it->keys.insert(key);
			hash_map[key] = pre_it;
		}
		else {
			hash_map.erase(key);
		}
	}

	/** Returns one of the keys with maximal value. */
	string getMaxKey() {
		if (link_list.empty())
			return "";
		else	
			return *(link_list.rbegin()->keys.begin());
	}

	/** Returns one of the keys with Minimal value. */
	string getMinKey() {
		if (link_list.empty())
			return "";
		else
			return *(link_list.begin()->keys.begin());
	}
private:
	struct Node {
		int val;
		unordered_set<string> keys;
		Node(int v) : val(v) {}
	};
	list<Node> link_list;
	unordered_map<string, list<Node>::iterator> hash_map;
};

/**
* Your AllOne object will be instantiated and called as such:
* AllOne* obj = new AllOne();
* obj->inc(key);
* obj->dec(key);
* string param_3 = obj->getMaxKey();
* string param_4 = obj->getMinKey();
*/


//int main() {
//	AllOne* obj = new AllOne();
//
//	obj->inc("i");
//	obj->inc("love");
//	obj->inc("love");
//	obj->inc("love");
//	obj->inc("leetcode");
//	obj->inc("leetcode");
//	cout << obj->getMaxKey() << endl;
//	cout << obj->getMinKey() << endl;
//	obj->dec("love");
//	obj->dec("love");
//	cout << obj->getMaxKey() << endl;
//	cout << obj->getMinKey() << endl;
//
//	system("pause");
//	return 0;
//}