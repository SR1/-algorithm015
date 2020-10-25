class LRUCache {
public:
    LRUCache(int capacity): mCapacity(capacity), mSize(0) {
        head = new Node();
        tail = new Node();

        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // cout << ">>> get " << key << endl; 
        if (!caches.count(key)) {
            // cout << "<<< finish get " << key << ": -1" << endl;
            return -1;
        } else {
            Node* node = caches[key];
            removeNode(node);
            addToHead(node);
            // cout << "<<< finish get " << key << ": " << caches[key]->val << endl;
            return node->val;
        }
    }
    
    void put(int key, int value) {
        // cout << ">>> put " << key << " : " << value << endl;
        Node* node;
        if (caches.find(key) != caches.end()) {
            node = caches[key];
            removeNode(node);
        } else {
            node = new Node();
            caches[key] = node;
            mSize++;
        }
        node->val = value;
        node->key = key;
        addToHead(node);

        if (mSize > mCapacity) {
            Node* last = tail->prev;
            removeNode(last);
            caches.erase(last->key);
            delete last;
            mSize--;
        }
        // cout << "<<< finish put " << key << " " << endl;
    }
    
    struct Node {
        Node* prev; Node* next; int val; int key;
    };

private:
    int mCapacity;
    int mSize;
    unordered_map<int, Node*> caches;

    Node* head;
    Node* tail;

    void print() {
        Node* n = head->next;
        while (n != tail) {
            cout << n->val << "->";
            n = n->next;
        }
        cout << endl;
        for (auto& entry : caches) {
            cout << entry.first << ":" << entry.second << ", ";
        }
        cout << endl;
    }

    void addToHead(Node* node) {
        Node* next = head->next;

        next->prev = node;
        node->prev = head;
        head->next = node;
        node->next = next;

        // cout << "add node " << node->val << " to head" << endl; print();
    }

    void removeNode(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;

        // cout << "remove node " << node->val << endl; print();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
