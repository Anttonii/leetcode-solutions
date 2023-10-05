class MyHashMap {
public:
    // naive implementation based on pairs and vectors
    std::vector<std::pair<int, int>> map;

    MyHashMap() {}
    
    void put(int key, int value) {
        bool updated = false;
        
        for (int i = 0; i < map.size(); i++) {
            if(map[i].first == key) {
                map[i].second = value;
                updated = true;
            }
        }

        if(!updated) map.push_back(std::make_pair(key, value));
    }
    
    int get(int key) {
        for (int i = 0; i < map.size(); i++) {
            if(map[i].first == key) return map[i].second;
        }
        return -1;
    }
    
    void remove(int key) {
        for (int i = 0; i < map.size(); i++) {
            if(map[i].first == key) map.erase(map.begin() + i);
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