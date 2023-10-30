#pragma onece
#include <queue>
// #include "bfs.cpp"
using namespace std;
namespace chapter7{
    int findBottomLeftValue(TreeNode* root) {
    queue<TreeNode*> qu1;
    queue<TreeNode*> qu2;
    qu1.push(root);
    int bottomLeft = root->val;
    while(!qu1.empty()){
        TreeNode* node = qu1.front();
        qu1.pop();
        if(node->left!=nullptr){
            qu2.push(node->left);
        }
        if(node->right!=nullptr){
            qu2.push(node->right);
        }

        if(qu1.empty()) {
            qu1 = qu2;
            queue<TreeNode*> emptyQ;
            swap(emptyQ, qu2);
            if(qu1.empty()) {
                bottomLeft = qu1.front()->val;
            }
        }
    }

    return bottomLeft;
}
};
