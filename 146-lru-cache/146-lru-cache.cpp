struct DoublyListNode {
    int key;
    int val;
    DoublyListNode* prev;
    DoublyListNode* next;
    
    DoublyListNode(int key, int val) {
        this -> key = key;
        this -> val = val;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    DoublyListNode* head;
    DoublyListNode* tail;
    
public:
    DoublyLinkedList() {
        this -> head = new DoublyListNode(-1, -1);
        this -> tail = new DoublyListNode(-1, -1);
        this -> head -> next = this -> tail;
        this -> tail -> prev = this -> head;
    }
    
    DoublyListNode* getFront() {
        return head -> next;
    }
    
    DoublyListNode* getBack() {
        return tail -> prev;
    }
    
    void pushBack(DoublyListNode* node) {
        node -> prev = tail -> prev;
        tail -> prev -> next = node;
        node -> next = tail;
        tail -> prev = node;
    }
    
    void popFront() {
        DoublyListNode* temp = head -> next;
        head -> next = temp -> next;
        temp -> next -> prev = head;
        delete temp;
    }
    
    void removeNode(DoublyListNode* node) {
        DoublyListNode* before = node -> prev;
        DoublyListNode* after = node -> next;
        if (before) before -> next = after;
        if (after) after -> prev = before;
    }
    
    void moveBack(DoublyListNode* node) {
        removeNode(node);
        pushBack(node);
    }
};

class LRUCache {
private:
    unordered_map<int, DoublyListNode*> mp;
    DoublyLinkedList list;
    int currSize;
    int maxSize;
    
public:
    LRUCache(int capacity) {
        this -> maxSize = capacity;
        this -> currSize = 0;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        
        list.moveBack(mp[key]);
        return mp[key] -> val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key] -> val = value;
            mp[key] -> key = key;
            list.moveBack(mp[key]);
            return;
        }
        
        if (currSize < maxSize) {
            mp[key] = new DoublyListNode(key, value);
            list.pushBack(mp[key]);
            currSize ++;
            
        } else {
            mp.erase(list.getFront() -> key);
            list.popFront();
            currSize --;
            put(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */