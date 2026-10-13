class LRUCache {
    struct Node {
        int key, val;
        Node* prev;
        Node* next;
        Node(int k = 0, int v = 0) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;

    void remove(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRUCache(int capacity) : capacity(capacity) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (!cache.count(key)) return -1;
        Node* node = cache[key];
        remove(node);
        addToFront(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cache.count(key)) {
            remove(cache[key]);
            delete cache[key];
        }
        Node* node = new Node(key, value);
        cache[key] = node;
        addToFront(node);
        if ((int)cache.size() > capacity) {
            Node* lru = tail->prev;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
