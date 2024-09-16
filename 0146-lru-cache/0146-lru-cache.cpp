class LRUCache {
public:
    list<int>dll;
    // map<int,pair<Address,int>>mp;
    map<int,pair<list<int>::iterator,int>>mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    void makeRecentlyUsed(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    int get(int key) {
        if(mp.find(key)==mp.end())return -1;

        makeRecentlyUsed(key);
       
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            mp[key].second=value;
            makeRecentlyUsed(key);
        }else

        {
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }
        if(n<0)
        {
            int key_tobe_deleted=dll.back();
            mp.erase(key_tobe_deleted);
            dll.pop_back();
            n++;
        }
    }
};

//brute force
/*
class LRUCache {
public:
    vector<pair<int, int>> cache;
    int n;
    
    LRUCache(int capacity) {
        n = capacity;
    }
    
    int get(int key) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                int value = cache[i].second;
                // Move the accessed item to the back of the cache (most recently used)
                cache.erase(cache.begin() + i);
                cache.push_back({key, value});
                return value;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for (int i = 0; i < cache.size(); i++) {
            if (cache[i].first == key) {
                // Remove the existing item
                cache.erase(cache.begin() + i);
                break;
            }
        }
        
        if (cache.size() == n) {
            // Remove the least recently used item (front of the vector)
            cache.erase(cache.begin());
        }
        
        // Insert the new item at the back (most recently used)
        cache.push_back({key, value});
    }
};

 */