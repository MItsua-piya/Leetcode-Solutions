class MyHashMap {
private:
    struct Node {
        int key;
        int value;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            next = nullptr;
        }
    };

    static const int SIZE = 1000;
    Node* buckets[SIZE];

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashMap() {
        for (int i = 0; i < SIZE; i++) {
            buckets[i] = nullptr;
        }
    }

    void put(int key, int value) {
        int index = hash(key);

        if (buckets[index] == nullptr) {
            buckets[index] = new Node(key, value);
            return;
        }

        Node* curr = buckets[index];

        while (curr != nullptr) {
          
            if (curr->key == key) {
                curr->value = value;
                return;
            }

         
            if (curr->next == nullptr) {
                break;
            }

            curr = curr->next;
        }

        
        curr->next = new Node(key, value);
    }

    int get(int key) {
        int index = hash(key);

        Node* curr = buckets[index];

        while (curr != nullptr) {
            if (curr->key == key) {
                return curr->value;
            }

            curr = curr->next;
        }

        return -1;
    }

    void remove(int key) {
        int index = hash(key);

        Node* curr = buckets[index];
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->key == key) {

                if (prev == nullptr) {
                    buckets[index] = curr->next;
                }
               
                else {
                    prev->next = curr->next;
                }

                delete curr;
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */