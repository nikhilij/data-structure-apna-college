// write the cpp program for lru cache

#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
private:
    // declaration of all memebers of cache
    int capacity;
    list<pair<int, int>> cache;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    // a function to move the node to the front of cache and add to the map if new occurs
    // or update the new value
    void moveToFront(int key, int value)
    {
        cache.erase(mp[key]);
        cache.push_front({key, value});
        mp[key] = cache.begin();
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }
    int get(int key)
    {
        // check if key doesn't exist return -1
        if (mp.find(key) == mp.end())
            return -1;
        // other wise take the value and move to front
        int value = mp[key]->second;
        moveToFront(key, value);
        return value;
    }
    void put(int key,int value){
        // if the current key exist in the cache then make it recent by moving it to the front
        if(mp.find(key)!=mp.end()){
            moveToFront(key,value);
        }else{
            // if key not exist in cache check the size
            if(cache.size() == capacity){
                // pop the least one from the back and erase it from mp too
                int lrukey = cache.back().first;
                cache.pop_back();
                mp.erase(lrukey);
            }
            // now add they key,value to front and update the map
            cache.push_front({key,value});
            mp[key]=cache.begin();
        }
    }
};

int main() {
    LRUCache lru(2); // capacity 2

    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl; // returns 1

    lru.put(3, 3); // evicts key 2
    cout << lru.get(2) << endl; // returns -1 (not found)

    lru.put(4, 4); // evicts key 1
    cout << lru.get(1) << endl; // returns -1 (not found)
    cout << lru.get(3) << endl; // returns 3
    cout << lru.get(4) << endl; // returns 4

    return 0;
}