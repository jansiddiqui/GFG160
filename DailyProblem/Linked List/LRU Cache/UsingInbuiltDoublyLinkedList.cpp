#include<bits/stdc++.h>
using namespace std;

class LRUCache{
    public:
    int capacity;
    list<pair<int, int>> List;

    unordered_map<int, list<pair<int, int>>::iterator> cacheMap;

    LRUCache(int capacity){
        this->capacity = capacity;
    }
    int get(int key){
        auto it = cacheMap.find(key);
        if(it == cacheMap.end()){
            return -1;
        }

        int value = it->second->second;
        List.erase(it->second);
        List.push_front({key, value});

        cacheMap[key] = List.begin();

        return value;
    }

    void put(int key, int value){
        auto it = cacheMap.find(key);
        if(it != cacheMap.end()){
            List.erase(it->second);
            cacheMap.erase(it);
        }

        List.push_front({key, value});
        cacheMap[key] = List.begin();

        if(cacheMap.size() > capacity){
            auto lastNode = List.back().first;
            List.pop_back();
            cacheMap.erase(lastNode);
        }
    }
};

int main(){
    LRUCache cache(2);
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // returns 1
    cache.put(3, 3);
    cout << cache.get(2) << endl; // returns -1 (not found)
    cache.put(4, 4);
    cout << cache.get(1) <<endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;

    return 0;
}