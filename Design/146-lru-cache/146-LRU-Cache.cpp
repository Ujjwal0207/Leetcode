class LRUCache {
public:
    list<int> dll;
    int n;

    map<int, pair<list<int>::iterator, int>> mp;

    LRUCache(int capacity) {
        n = capacity;
    }

    void update(int key) {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin();
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            update(key);
            return mp[key].second;
        }

        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            mp[key].second = value;
            update(key);
        } else {
            dll.push_front(key);
            mp[key] = {dll.begin(), value};
            n--;
        }

        if (n < 0) {
            mp.erase(dll.back());
            dll.pop_back();
            n++;
        }
    }
};