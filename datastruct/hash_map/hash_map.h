#include <iostream>
#include <string>

// HashNode
template<typename K, typename V>
struct HashNode {
    K key;
    V value;
    HashNode * next;
    // 构造函数，初始化，：后面c++新特性，成员初始化列表（和ts返回值类型区分开）
    HashNode(K k, V v): key(k), value(v), next(nullptr) {}
};

// HashMap
template<typename K,typename V>
class HashMap {
    private :
        // hash函数
        int hash(K key){
            // c++标准库中的hash函数，返回一个无符号整数
            return std::hash<K>()(key) % m_capacity;
        }
        int m_capacity;
        // m_table指向一个一维指针数组，数组中存储链表的头节点，
        // 该节点又是一个指向HashNode的指针
        HashNode<K, V>** m_table;
    public:
        // 构造函数，初始化指定容量的指针数组
        HashMap(int capacity):m_capacity(capacity){
            m_table =new HashNode<K,V>*[capacity];
            for (int i=0;i<capacity;i++){
                m_table[i] =nullptr;
            }
        }
        ~HashMap(){
            // 回收内存，防止内存泄漏
            for(int i=0;i<m_capacity;i++){
                // 链表头节点
                HashNode<K,V>* node =m_table[i];
                while(node){
                    // 回收链表内存
                    HashNode<K,V>* temp =node->next;
                    delete node;
                    node =temp;
                }
            }
            // 回收指针数组
            delete[] m_table;
        }
        void put(K k, V v){
            int index =hash(k);
            HashNode<K,V> * node =m_table[index];
            // 判断现有hash节点中是否存在
            while(node){
                if (node->key == k){
                    node->value =v;
                    return;
                }
                node =node->next;
            }
            // 不存在则链表前插？
            HashNode<K,V>* newNode =new HashNode(k,v);
            newNode->next = m_table[index];
            m_table[index] =newNode;
        }
        V get(K k){
            int index =hash(k);
            HashNode<K,V> * node =m_table[index];
            while(node){
                if (node->key == k){
                    return node->value;
                }
                node =node->next;
            }
            return V();
        }
        void remove(K k){
            int index =hash(k);
            HashNode<K,V> * node =m_table[index];
            HashNode<K,V> * prev =nullptr;
            while(node){
                if (node->key == k){
                    // 删除该node
                    HashNode<K,V> * temp = node->next;
                    if (prev){
                        delete node;
                        prev->next =temp;
                    }else{
                        // 头节点即匹配
                        delete node;
                        m_table[index] =temp;
                    }
                    return;
                }
                prev =node;
                node =node->next;
            }
        }
};  

