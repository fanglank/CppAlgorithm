#pragma onece
#include <queue>
// #include "bfs.cpp"
#include <limits>
using namespace std;
namespace chapter7{
    vector<int> largestValues(TreeNode* root){
    int current = 0;
    int next =0;
    queue<TreeNode*> qu;
    if(root !=nullptr){
        qu.push(root);
        current =1;
    }
    vector<int> result;
    int maxValue = INT_MIN;
    while(!qu.empty()){
        TreeNode* node = qu.front();
        qu.pop();
        current--;
        maxValue = max(maxValue, node->val);
        if(node -> left!=nullptr){
            qu.push(node->left);
            next++;
        }
        if(node->right !=nullptr){
            qu.push(node->right);
            next++;
        }
        if(current ==0){
            result.push_back(maxValue);
            maxValue = INT_MIN;
            current = next;
            next = 0;
        }
    }

    return result;
}

vector<int> largestValues1(TreeNode* root){
    queue<TreeNode*> qu1;
    queue<TreeNode*> qu2;
    if(root !=nullptr) {
        qu1.push(root);
    }
    vector<int> result;
    int maxValue = INT_MIN;
    while(!qu1.empty()){
        TreeNode* node = qu1.front();
        qu1.pop();
        maxValue = max(maxValue, node->val);
        if(node->left!=nullptr){
            qu2.push(node->left);
        }
        if(node->right!=nullptr){
            qu2.push(node->right);
        }

        if(qu1.empty()){
            result.push_back(maxValue);
            maxValue = INT_MIN;
            qu1 = qu2;
            queue<TreeNode*> emptyQ;
            swap(emptyQ, qu2);

        }
    }

}
}
