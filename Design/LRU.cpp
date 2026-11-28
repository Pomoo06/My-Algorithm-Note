/*
实现 LRUCache 类：
LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
*/

#include<bits/stdc++.h>

using namespace std;

struct Node{
    int val;
    int key;
    Node *prev;
    Node *next;
    Node(int key, int val){
        this->key = key;
        this->val = val;
    }
};

class LRUCache{
    private:
        int capacity;
        int cur_cap;
        unordered_map<int, Node*> mp;
        Node *head;
        Node *tail;
    public:
        LRUCache(int capacity){
            cur_cap = 0;
            this->capacity = capacity;
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->prev = head;
        }

        void remove(Node *node){
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        void add(Node *node){
            node->prev = head;
            node->next = head->next;
            head->next->prev = node;
            head->next = node;
        }

        int get(int key){
            if(mp.find(key) != mp.end()){
                Node *p = mp[key];
                remove(p);
                add(p);
                return p->val;
            }
            return -1;
        }

        void put(int key, int val){
            if(mp.find(key) != mp.end()){
                Node *p = mp[key];
                p->val = val;
                remove(p);
                add(p);
            }else{
                if(cur_cap == capacity){
                    Node *p = tail->prev;
                    remove(p);
                    mp.erase(p->key);
                    delete p;
                    p = new Node(key, val);
                    add(p);
                    mp[key] = p;
                }else{
                    Node *p = new Node(key, val);
                    add(p);
                    mp[key] = p;
                    cur_cap++;
                }
            }
        }
};