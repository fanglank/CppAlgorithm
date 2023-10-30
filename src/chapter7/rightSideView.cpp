#pragma onece
#include <queue>
// #include "bfs.cpp"
#include <limits>
namespace chapter7 {
    vector<int> rightSideView(TreeNode* root) {
    vector<int> view;
    if(root == nullptr) {
        return view;
    }
    queue<TreeNode*> qu1;
    queue<TreeNode*> qu2;
    qu1.push(root);
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
            view.push_back(node->val);
            qu1 = qu2;
            queue<TreeNode*> emptyQ;
            swap(emptyQ, qu2);
        }
        
    }

}
}
