// Double LinkedList + Hash Table
// O(1) Time complexity

class LRUCache {
public:
    struct List {
        int val;
        List *next;
        List *prev;
        List(int val) {
            this->val = val;
            this->next = NULL;
            this->prev = NULL;
        }
    };
    
    LRUCache(int capacity) {
        head = NULL;
        tail = NULL;
        cap = capacity;
    }
    
    int get(int key) {
        if (map.find(key) != map.end()) {
            List *node = hash[key];
            if (node != tail) {
                List *prevNode = node->prev;
                List *nextNode = node->next;
                nextNode->prev = prevNode;
                if (prevNode != NULL) prevNode->next = nextNode;
                else head = head->next;
                tail->next = node;
                node->prev = tail;
                tail = node;
                hash[key] = node;
            }
            return map[key];
        }
        else return -1;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            List *node = hash[key];
            if (node != tail) {
                List *prevNode = node->prev;
                List *nextNode = node->next;
                nextNode->prev = prevNode;
                if (prevNode != NULL) prevNode->next = nextNode;
                else head = head->next;
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }  
        else {
            List *node = new List(key);
            if (head == NULL) {
                head = node;
                tail = node;
            }
            else if ((int)map.size() < cap) {
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
            else {
                tail->next = node;
                node->prev = tail;
                tail = node;
                List *temp = head;
                head = head->next;
                head->prev = NULL;
                map.erase(temp->val);
                delete(temp);
            }
            hash[key] = node;
        }
        map[key] = value;
    }
    
private:
    int cap;
    unordered_map<int, int> map;
    unordered_map<int, List *> hash;
    List *head;
    List *tail;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */