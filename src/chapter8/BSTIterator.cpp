#include "TreeNode.cpp"
#include <vector>
#include <stack>
#include <map>
using namespace std;
namespace chapter8
{
    class BSTIterator
    {
    private:
        /* data */
    public:
        TreeNode* cur;
        stack<TreeNode*> sta;
        BSTIterator(TreeNode *root);
        bool hasNext();
        int next();
        ~BSTIterator();
    };

    BSTIterator::BSTIterator(TreeNode *root)
    {
    }
    bool BSTIterator::hasNext()
    {
        return cur!=nullptr || !sta.empty();
    }

    int BSTIterator::next() {
        while(cur!=nullptr) {
            sta.push(cur);

        }
    }

    BSTIterator::~BSTIterator()
    {
    }
}
