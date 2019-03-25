// implement a double linked list
struct DoubleListNode {
	int key;
	int value;
	DoubleListNode *pre;
	DoubleListNode *next;
	DoubleListNode(int k, int v) : key(k), value(v), pre(nullptr), next(nullptr) {}
};

class DoubleLinkedList {

public:
	// head <--> node1 <--> ... <--> nodeN <--> tail
	DoubleLinkedList() {
		head = new DoubleListNode(0, 0);
		tail = new DoubleListNode(0, 0);
		head->next = tail;
		tail->pre = head;
	}

	~DoubleLinkedList() {
		DoubleListNode *tmp = nullptr;
		while (head) {
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	void insertAfterHead(DoubleListNode *node) {
		DoubleListNode *tmp = head->next;
		head->next = node;
		node->pre = head;
		node->next = tmp;
		tmp->pre = node;
	}

	void moveToHead(DoubleListNode* node) {
		// remove
		removeNode(node);
		// insert as head
		insertAfterHead(node);
	}

	void removeNode(DoubleListNode* node) {
		DoubleListNode *pre_node = node->pre;
		DoubleListNode *next_node = node->next;
		pre_node->next = next_node;
		next_node->pre = pre_node;
	}

	int removeBeforeTail() {
		if (head->next == tail)
			return -1;
		DoubleListNode* tmp = tail->pre;
		int return_key = tmp->key;
		tmp->pre->next = tail;
		tail->pre = tmp->pre;
		delete tmp;
		return return_key;
	}

private:
	DoubleListNode *head;
	DoubleListNode *tail;
};

class LRUCache {

public:
	LRUCache(int capacity) {
		cache_size = 0;
		cache_capacity = capacity;
	}

	int get(int key) {
		auto iter = hash_map.find(key);
		if (iter != hash_map.end()) {
			// found
			DoubleListNode *found_node = iter->second;
			int found_value = found_node->value;
			double_linked_list.moveToHead(found_node);
			return found_value;
		}
		else {
			// not found
			return -1;
		}
	}

	void put(int key, int value) {
		auto iter = hash_map.find(key);
		if (iter != hash_map.end()) {
			// found, update its value
			DoubleListNode *found_node = iter->second;
			found_node->value = value;
			double_linked_list.moveToHead(found_node);
		}
		else {
			// not found
			// if full
			if (cache_size == cache_capacity) {
				int tail_key = double_linked_list.removeBeforeTail();
				hash_map.erase(tail_key);
				--cache_size;
			}
			DoubleListNode* new_node = new DoubleListNode(key, value);
			double_linked_list.insertAfterHead(new_node);
			hash_map.insert(pair<int, DoubleListNode*>(key, new_node));
			++cache_size;
		}
	}

private:
	DoubleLinkedList double_linked_list;
	int cache_size;
	int cache_capacity;
	unordered_map<int, DoubleListNode*> hash_map;
};
