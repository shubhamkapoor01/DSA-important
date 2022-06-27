class DoublyListNode {
public:
    int key;
    int val;
    DoublyListNode* next;
    DoublyListNode* prev;
    
    DoublyListNode(int key, int val) {
        this -> key = key;
        this -> val = val;
        this -> next = nullptr;
        this -> prev = nullptr;
    }
};

class LRUCache {
private:
    unordered_map<int, DoublyListNode*> mp;
    DoublyListNode* head;
    DoublyListNode* tail;
    int currSize;
    int maxSize;
    
    void moveToBack(DoublyListNode* node) {
        if (!node) return;
        
        DoublyListNode* before = node -> prev;
        DoublyListNode* after = node -> next;
        
        if (before) before -> next = after;
        if (after) after -> prev = before;
        
        node -> prev = tail -> prev;
        tail -> prev -> next = node;
        node -> next = tail;
        tail -> prev = node;
        return;
    }
    
    
    
public:
    LRUCache(int capacity) {
        this -> head = new DoublyListNode(-1, -1);
        this -> tail = new DoublyListNode(-1, -1);
        this -> head -> next = this -> tail;
        this -> tail -> prev = this -> head;
        this -> maxSize = capacity;
        this -> currSize = 0;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }
        
        moveToBack(mp[key]);
        return mp[key] -> val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key] -> val = value;
            mp[key] -> key = key;
            moveToBack(mp[key]);
            return;
        }
        
        if (currSize < maxSize) {
            mp[key] = new DoublyListNode(key, value);
            moveToBack(mp[key]);
            currSize ++;
            
        } else {
            DoublyListNode* temp = head -> next;
            mp.erase(temp -> key);
            head -> next = temp -> next;
            temp -> next -> prev = head;
            delete temp;
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