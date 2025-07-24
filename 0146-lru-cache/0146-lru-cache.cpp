class LRUCache {
public:
    class node {
        public:
        int key;
        int val;
        node* prev;
        node* next;
        node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    int capacity;
    unordered_map<int, node*> m;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void insertNode(node* newNode) {
        node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        temp->prev = newNode;
        newNode->next = temp;
    }

    void deleteNode(node* dlt) {
        node* prevdlt = dlt->prev;
        node* nextdlt = dlt->next;
        prevdlt->next = nextdlt;
        nextdlt->prev = prevdlt;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            node* res = m[key];
            int value = res->val;
            m.erase(key);
            deleteNode(res);
            insertNode(res);
            m[key] = head->next;
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            node* res = m[key];
            m.erase(key);
            deleteNode(res);
        }
        if (m.size() == capacity) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        insertNode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */