class LFUCache {
public:
    class Node {
    public:
        // CREATING DLL 
        int key, val, freq;
        Node *next, *prev;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
            freq = 1;
        }
    };

    // LIST SHOWS THE MAXIMUM FREQ OF CURRENT ELEMENTS IN THE LIST
    class List {
    public:
        int size;
        Node* head;
        Node* tail;
        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
            size = 0;
        }
        void addFront(Node* curr) {
            Node* temp = head->next;
            curr->next = temp;
            head->next = curr;
            curr->prev = head;
            temp->prev = curr;
            size++;
        }
        void deleteNode(Node* curr) {
            Node* dltPrev = curr->prev;
            Node* dltNxt = curr->next;
            dltPrev->next = dltNxt;
            dltNxt->prev = dltPrev;
            size--;
        }
    };

    unordered_map<int, Node*> keyRef;
    unordered_map<int, List*> freqList;

    // MINFREQ - OVERALL MINIMUM FREQ(LIST WITH LEAST VALUE)
    // CURRSIZE - CURRECT ELEMENTS
    int minFreq, currSize, capacity;

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        currSize = 0;
    }

    void updateList(Node* curr) {
        // WE WILL ERASE THE KEY AND ITS NODE FROM MAP
        keyRef.erase(curr->key);
        freqList[curr->freq]->deleteNode(curr);

        // IF AFTER DELETING THE LIST OF CURRECT SIZE BECOMES EMPTY THEN INCREASE MINFREQ
        if (curr->freq == minFreq && freqList[curr->freq]->size == 0) {
            minFreq++;
        }
        List* newList = new List();

        // CHECK IF THERE IS ANY EXISTING LIST WITH FREQ SAME AS THAT OF CURRENT ELEMENT
        if (freqList.find(curr->freq + 1) != freqList.end()) {
            newList = freqList[curr->freq + 1];
        }
        curr->freq += 1;

        // AS IT IS RECENTLY USED ADD IT TO START OF LIST(WE WILL REMOVE LRU INCASE OF TIE)
        newList->addFront(curr);
        freqList[curr->freq] = newList;
        keyRef[curr->key] = curr;
    }

    int get(int key) {
        if (keyRef.find(key) != keyRef.end()) {
            Node* curr = keyRef[key];
            int val = curr->val;
            updateList(curr);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {

        // EDGE CASE CHECK
        if (capacity == 0) {
            return;
        }

        // IS THE KEY ALREADY EXISTS
        if (keyRef.find(key) != keyRef.end()) {
            Node* curr = keyRef[key];
            // JUST UPDATE THE VALUE AND ALSO ITS POS IN LIST 
            curr->val = value;
            updateList(curr);
        } 

        // NEW KEY
        else {
            if (currSize == capacity) {
            // SELECT THE LIST WITH MIN FREQ AND ERASE THE 1ST ELEMENT FROM THE TAIL
                List* list = freqList[minFreq];
                keyRef.erase(list->tail->prev->key);
                freqList[minFreq]->deleteNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            // NEW KEY WILL ALWAYS HAVE FREQ INITIALLY
            minFreq = 1;
            List* listFreq = new List();
            // AGAIN CHECK IF THERE IS LIST FOR FREQ = 1 AND IF YES THEN ADD THIS ELEMENT TO FRONT
            if (freqList.find(minFreq) != freqList.end()) {
                listFreq = freqList[minFreq];
            }
            Node* curr = new Node(key, value);
            listFreq->addFront(curr);
            keyRef[key] = curr;
            freqList[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */