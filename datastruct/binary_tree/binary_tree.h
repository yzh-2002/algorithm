#include <iostream>

using namespace std;

// 二叉树节点定义
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : value(x), left(nullptr), right(nullptr) {}
};

class BinaryTree {
    private:
        TreeNode * root; //根节点
    public:
        BinaryTree(): root(nullptr){}
        /**
         * 插入节点（也可以递归）
        */
        void insert(int v){
            TreeNode * node =root;
            // TreeNode * prev =nullptr;
            while(node){
                if (node->value > v){
                    // prev =node;
                    node =node->left;
                }else{
                    // prev =node;
                    node =node->right;
                }
            }
            node =new TreeNode(v);
        }
        // 先序遍历（序值得是根节点在何时被访问）
        void preOrderTraversal(){
            
        }

        // 中序遍历

        // 后序遍历
};
