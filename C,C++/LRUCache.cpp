#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class LRUCache
{
private:
    int size;
    list<int> keys;
    unordered_map<int, list<int>::iterator> keyPosMap;
    unordered_map<int, int> valueMap;

public:
    LRUCache(int capacity) : size(capacity) {}

    int get(int key)
    {
        if (keyPosMap.find(key) != keyPosMap.end())
        {
            keys.erase(keyPosMap[key]);
            keys.push_front(key);
            keyPosMap[key] = keys.begin();
            return valueMap[key];
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (keyPosMap.find(key) != keyPosMap.end())
        {
            keys.erase(keyPosMap[key]);
        }
        else
        {
            if (keys.size() == size)
            {
                int lru_key = keys.back();
                keys.pop_back();
                keyPosMap.erase(lru_key);
                valueMap.erase(lru_key);
            }
        }

        keys.push_front(key);
        keyPosMap[key] = keys.begin();
        valueMap[key] = value;
    }
};

int main()
{
    LRUCache *cache = new LRUCache(2);
    cache->put(1, 1);
    cache->get(1);
    cache->put(2, 2);
    cache->put(1, 1);
    delete cache;
    return 0;
}