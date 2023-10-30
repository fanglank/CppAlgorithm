namespace chapter8
{
    class TreeNode
    {
    private:

    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x);
        ~TreeNode();
    };
    
    TreeNode::TreeNode(int x)
    {
        val = x;
    }
    
    TreeNode::~TreeNode()
    {
        delete left;
        delete right;
    }
    
    
} // namespace chapter8
