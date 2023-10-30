#pragma onece
#include <queue>
// #include "bfs.cpp"
using namespace std;
namespace chapter7
{
    class CBTInserter
    {
    private:
        queue<TreeNode *> qu;
        TreeNode *root;

    public:
        CBTInserter(TreeNode *rt);
        TreeNode get_root();
        int insert(int v);
        ~CBTInserter();
    };

    CBTInserter::CBTInserter(TreeNode *rt)
    {
        root = rt;
        qu.push(root);
        while (qu.front()->left != nullptr && qu.front()->right != nullptr)
        {
            TreeNode *node = qu.front();
            qu.pop();
            qu.push(node->left);
            qu.push(node->right);
        }
    }
    int CBTInserter::insert(int v)
    {
        TreeNode *parent = qu.front();
        qu.pop();
        TreeNode *node = new TreeNode(v);
        if (parent->left == nullptr)
        {
            parent->left = node;
        }
        if (parent->right == nullptr)
        {
            parent->right = node;
            qu.pop();
            qu.push(parent->left);
            qu.push(parent->right);
        }
        return parent->val;
    }
    TreeNode CBTInserter::get_root()
    {
        return *root;
    }
    CBTInserter::~CBTInserter()
    {
    }

}
