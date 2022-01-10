struct DoublyListNode {
    int key = 0;
    int val = 0;
    DoublyListNode* next = NULL;
    DoublyListNode* prev = NULL;
};

class LRUCache {
    int maxSize;
    unordered_map<int, DoublyListNode*> mp;
    DoublyListNode* head;
    DoublyListNode* tail;
    
public:
    LRUCache(int capacity) {
        this -> maxSize = capacity;
        this -> head = new DoublyListNode;
        this -> tail = new DoublyListNode;
        this -> head -> next = this -> tail;
        this -> tail -> prev = this -> head;
        this -> head -> prev = NULL;
        this -> tail -> next = NULL;
    }
    
    int get(int key) {
        if (mp.find(key) != mp.end()) {
            int val = mp[key] -> val;
            
            DoublyListNode* temp = mp[key];
            DoublyListNode* tempNext = temp -> next;
            DoublyListNode* tempPrev = temp -> prev;
            
            if (tempNext) {
                tempNext -> prev = tempPrev;
            }
            if (tempPrev) {
                tempPrev -> next = tempNext;
            }
            
            temp -> prev = tail -> prev;
            temp -> next = tail;
            tail -> prev -> next = temp;
            tail -> prev = temp;
            
            return val;
            
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key] -> val = value;
            
            DoublyListNode* temp = mp[key];
            DoublyListNode* tempNext = temp -> next;
            DoublyListNode* tempPrev = temp -> prev;
            
            if (tempNext) {
                tempNext -> prev = tempPrev;
            }
            if (tempPrev) {
                tempPrev -> next = tempNext;
            }
            
            temp -> prev = tail -> prev;
            temp -> next = tail;
            tail -> prev -> next = temp;
            tail -> prev = temp;
            return;
        }
        
        if (mp.size() == maxSize) {
            DoublyListNode* temp = head -> next;
            mp.erase(temp -> key);
            head -> next = temp -> next;
            temp -> next -> prev = head;
            delete temp;
        }
        
        DoublyListNode* newTail = new DoublyListNode;
        newTail -> key = key;
        newTail -> val = value;
        newTail -> prev = tail -> prev;
        newTail -> next = tail;
        
        tail -> prev -> next = newTail;
        tail -> prev = newTail;
        
        mp[key] = newTail;
        return;
    }
};
