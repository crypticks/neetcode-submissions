#include <cstring>
class MyHashSet {
public:
    int size = 1000;
    int arr[1000] = {-1};
    MyHashSet() {
        //memset(this->arr, -1, 1000 );
        for(int i = 0; i < 1000; i++) this->arr[i] = -1;
    }

    int hash(int key, int i)
    {
        return (key + i)%this->size;
    }
    
    void add(int key) {
        int i = 0;
        int m = hash(key, i);
        int cp = m;
        while(this->arr[m] != -1)
        {
            i++;
            if(this->arr[m] == key) return;
            m = hash(key, i);
            if(cp == m) return;
        }
        this->arr[m] = key;
    }
    
    void remove(int key) {
        
        int i = 0;
        int m = hash(key, i);
        int cp = m;
        while(this->arr[m] != key)
        {
            i++;
            m = hash(key, i);
            if(cp == m) return;
        }
        this->arr[m] = -1;

    }
    
    bool contains(int key) {
        
        int i = 0;
        int m = hash(key, i);
        int cp = m;
        while(cp!=(m+1)%this->size)
        {
            i++;
            if(this->arr[m] == key) return true;
            m = hash(key, i);
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */