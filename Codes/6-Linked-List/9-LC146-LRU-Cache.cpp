// Approach 1
class Node{
public:
    int key, val;
    Node *prev, *next;
    Node(int key=-1, int val=-1): 
        key(key), val(val), prev(nullptr), next(nullptr){}
};

// Time: O(1) - avg | Space: O(capacity)
class LRUCache {
public:
    int maxC;
    Node *head, *tail;
    unordered_map<int, Node*> m;

    LRUCache(int capacity): maxC(capacity), head(new Node()), tail(new Node()) {
        head->next = tail;
        tail->prev = head;
    }

    void insert(Node *n){
        n->next = head->next;
        n->prev = head;
        head->next->prev = n;
        head->next = n;
    }

    void remove(Node *n){
        n->prev->next = n->next;
        n->next->prev = n->prev;
    }
    
    int get(int key) {
        if(!m.count(key)) return -1;
        Node* n = m[key];
        remove(n);
        insert(n);
        return n->val;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            Node* n = m[key];
            n->val = value;
            remove(n);
            insert(n);
            return;
        }
        if(m.size() == maxC){
            Node *lru = tail->prev;
            m.erase(lru->key);
            remove(lru);
            delete lru;
        }
        Node *newNode = new Node(key, value);
        insert(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


// Approach 2: Using STL
class LRUCache {
public:
    int maxC;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;
    
    LRUCache(int capacity): maxC(capacity) {}
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end()) return -1;
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }
    
    void put(int key, int value) {
        auto it = m.find(key);
        if(it != m.end()){
            it->second->second = value;
            l.splice(l.begin(), l, it->second);
            return;
        }
        if(m.size() == maxC){
            auto lru = l.back();
            l.pop_back();
            m.erase(lru.first);
        }
        l.push_front({key, value});
        m[key] = l.begin();
    }
};