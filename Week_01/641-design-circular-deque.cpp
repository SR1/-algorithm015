class MyCircularDeque {
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k): capacity(k), size(0) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        // cout << "insertFront: " << value << endl;
        if (size >= capacity) return false;
        Node* node = new Node();
        node->val = value;
        addToHead(node);
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        // cout << "insertLast: " << value << endl;
        if (size >= capacity) return false;
        Node* node = new Node();
        node->val = value;
        addToTail(node);
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        // cout << "deleteFront" << endl;
        if (size == 0) return false;
        remove(head->next);
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        // cout << "deleteLast" << endl;
        if (size == 0) return false;
        remove(tail->prev);
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        // cout << "getFront" << endl;
        if (size == 0) return -1;
        return head->next->val;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        // cout << "getRear" << endl;
        if (size == 0) return -1;
        return tail->prev->val;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        // cout << "isEmpty" << endl;
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        // cout << "isFull" << endl;
        return (size == capacity);
    }

    ~MyCircularDeque() {
        delete head;
        delete tail;
    }
private:
    struct Node {
        Node* prev; Node* next;
        int val;
    };

    int capacity;
    int size;
    
    Node* head;
    Node* tail;

    void addToHead(Node* node) {
        Node* oldHead = head->next;

        head->next = node;
        node->next = oldHead;

        oldHead->prev = node;
        node->prev = head;
    }

    void addToTail(Node* node) {
        Node* oldTail = tail->prev;
        
        oldTail->next = node;
        node->next = tail;

        tail->prev = node;
        node->prev = oldTail;
    }

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
        
        delete node;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
