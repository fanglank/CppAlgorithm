// #include "TreeNode.cpp"
#include <vector>
#include <stack>
using namespace std;

namespace chapter8{

    class BinaryTree
    {
    private:
        /* data */
    public:
        BinaryTree(/* args */);
        vector<int> dfsInorder(TreeNode* root);
        vector<int> dfsPreInorder(TreeNode* root);
        vector<int> dfsPostInorder(TreeNode* root);
        ~BinaryTree();
    };
    
    BinaryTree::BinaryTree(/* args */)
    {
    }
    //中序遍历
    vector<int> BinaryTree::dfsInorder(TreeNode* root){
        vector<int> nodes;
        if(root!=nullptr){
            dfsInorder(root->left);
            nodes.push_back(root->val);
            dfsInorder(root->right);
        }
        return nodes;
    }
    //使用栈中序遍历二叉树
    vector<int> inorderTraversal(TreeNode* root){
        vector<int> nodes;
        stack<TreeNode*> stack;
        TreeNode* cur =root;
        while(cur!=nullptr || !stack.empty()){
            while (cur!=nullptr)
            {
                stack.push(cur);
                cur = cur -> left;
            }

            cur = stack.top();
            stack.pop();
            nodes.push_back(cur->val);
            cur = cur->right;
            
        }
    }
    //前序遍历二叉树
    vector<int> dfsPreInorder(TreeNode* root){
        vector<int> nodes;
        if(root!=nullptr) {
            nodes.push_back(root->val);
            dfsPreInorder(root->left);
             dfsPreInorder(root->right);
        }
        return nodes;
    }

    vector<int> preorderTraversal(TreeNode* root){
        vector<int> nodes;
        stack<TreeNode*> stack;
        TreeNode* cur =root;
         while(cur!=nullptr || !stack.empty()){
            while (cur!=nullptr)
            {
                nodes.push_back(cur->val);
                stack.push(cur);
                cur = cur->left;
            }
            cur = stack.top();
            stack.pop();
            cur = cur->right;
        }
        return nodes;
    }
    //后序遍历
    vector<int> dfsPostInorder(TreeNode* root){
        vector<int> nodes;
        if(root!=nullptr){
            dfsPostInorder(root->left);
            dfsPostInorder(root->right);
            nodes.push_back(root->val);
        }
    }
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> nodes;
        stack<TreeNode*> stack;
        TreeNode* cur =root;
        TreeNode* pre =nullptr;
        while(cur!=nullptr || !stack.empty()){
            while(cur!=nullptr){
                stack.push(cur);
                cur =cur->left;
            }

            cur = stack.top();
            stack.pop();
            if(cur->right!=nullptr && cur->right!=pre){
                cur = cur->left;
            }else {
                stack.pop();
                nodes.push_back(cur->val);
                pre = cur;
                cur = nullptr;
            }
        }
        return nodes;
    }
    BinaryTree::~BinaryTree()
    {
    }
    
};