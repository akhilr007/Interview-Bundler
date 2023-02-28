/*
HEAD <-> NODE <-> NODE <-> NODE <-> NODE <-> TAIL
new node will get inserted at left of tail
so lru will be at next of head
*/

class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int key, int val){
        this->key = key;
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache{
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* head, *tail;

    void remove(Node* node){
        Node* prev = node->prev;
        Node* nxt = node->next;

        prev->next = nxt;
        nxt->prev = prev;

        delete node;
    }

    void insert(Node* node){

        Node* prev = tail->prev;
        Node* nxt = tail;

        prev->next = node;
        nxt->prev = node;

        node->prev = prev;
        node->next = nxt;
    }

public:
    LRUCache(int capacity){
        cap = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);

        head->next = tail;
        tail->prev = head;
    };

    int get(int key){   

        if(cache.find(key) != cache.end()){
            // remove the key from linked list and insert it to left of tail so that it becomes latest
            // key to be used and return its val
            remove(cache[key]);
            insert(cache[key]);
            return cache[key]->val;
        }

        // if not found, return -1
        return -1;

    }

    void put(int key, int value){

        if(cache.find(key) != cache.end()){
            remove(cache[key]);
        }

        cache[key] = new Node(key, val);
        insert(cache[key]);

        if(cache.size() > cap){
            Node* LRU = head->next;
            remove(LRU);
            cache.erase(LRU->key);
        }
    }
};