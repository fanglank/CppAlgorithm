#include <unordered_map>
#include "ListNode.cpp"
using namespace std;
namespace chapter5 {
    class LRUCache
    {
    private:
        ListNode* head;
        ListNode* tail;
        unordered_map<int, ListNode*> map;
        int capcity;
    public:
        LRUCache(int cap);
        int get(int key);
        int put(int key, int value);
        void moveToTail(ListNode * node, int newValue);
        void deleteNode(ListNode* node);
        void insertToTail(ListNode* node);
        ~LRUCache();
    };
    
    LRUCache::LRUCache(int cap)
    {
       head = new ListNode(-1,-1);
       tail = new ListNode(-1, -1);
       head->next = tail;
       tail->prev = head;
       capcity = cap;
    }
    int LRUCache::get(int key){
        ListNode* node = map.at(key);
        if(node == nullptr) {
            return -1;
        }
        moveToTail(node, node->value);
        return node->value;
    }
    int LRUCache::put(int key, int value){
        if(map.count(key) > 0){
            moveToTail(map.at(key), value);
        }else {
            if(map.size() == capcity){
                ListNode* toBeDeleted = head->next;
                deleteNode(toBeDeleted);
                map.erase(toBeDeleted->key);
            }
            ListNode *node = new ListNode(key, value);
            insertToTail(node);
            map[key] = node;
        }
    }

    void LRUCache::moveToTail(ListNode * node, int newValue) {
        deleteNode(node);
        node->value = newValue;
        insertToTail(node);
    }

    void LRUCache::deleteNode(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void LRUCache::insertToTail(ListNode* node){
        tail->prev->next = node;
        node->prev = tail->prev;
        node->next = tail;
        tail->prev = node;
    }
    LRUCache::~LRUCache()
    {
        head = nullptr;
        delete head;
        tail = nullptr;
        delete tail;
    }
    
};