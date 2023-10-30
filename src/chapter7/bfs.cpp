#pragma onece
#include <queue>

using namespace std;
// using namespace chapter8;
namespace chapter7{
    class TreeNode
{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v){
        val = v;
    }
};

queue<int> bfs(TreeNode* root)
{
    queue<TreeNode*> qu;
    if(root == nullptr) {
        qu.push(root);
    }

    queue<int> result;
    while(qu.front()!=0){
        TreeNode* node = qu.front();
        qu.pop();
        result.push(node->val);
        if(node->left!=nullptr){
            qu.push(node->left);
        }
        if(node->right!=nullptr) {
            qu.push(node->right);
        }
    }
    return result;
}
};


