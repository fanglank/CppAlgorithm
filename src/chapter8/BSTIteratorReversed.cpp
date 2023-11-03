#include "TreeNode.cpp"
#include <vector>
#include <stack>
#include <map>
using namespace std;
namespace chapter8{
    class BSTIteratorReversed
    {
    private:
        /* data */
    public:
        TreeNode * cur;
        stack<TreeNode*> sta;
        BSTIteratorReversed(TreeNode* root);
        bool hasPrev();
        int prev();
        ~BSTIteratorReversed();
    };
    
    BSTIteratorReversed::BSTIteratorReversed(TreeNode* root)
    {
        cur = root;
    }

    bool BSTIteratorReversed::hasPrev() {
        return cur!=nullptr || !sta.empty();
    }
    int BSTIteratorReversed::prev(){
        while(cur!=nullptr) {
            sta.push(cur);
            cur = cur->right;
            
        }
        cur = sta.top();
        sta.pop();
        int val = cur->val;
        cur = cur->left;
        return val;
    }
    BSTIteratorReversed::~BSTIteratorReversed()
    {

    }
    
}