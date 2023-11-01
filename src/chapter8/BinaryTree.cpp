#include "TreeNode.cpp"
#include <vector>
#include <stack>
#include <map>
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
        TreeNode* pruneTree(TreeNode* root);
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
    TreeNode* pruneTree(TreeNode* root){
        if(root == nullptr){
            return root;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->left==nullptr&& root->right==nullptr&&root->val==0){
            return nullptr;
        }
        return root;
    }

    string serializeTree(TreeNode* root) {
        if(root == nullptr) {
            return "#";
        }
        string leftStr = serializeTree(root->left);
        string rightStr = serializeTree(root->right);

        return  std::to_string(root->val) +","+leftStr+","+rightStr;
    }

    void split(const std::string &str, std::vector<std::string> &tokens, const char delim)
    {
        tokens.clear();
        int p = -1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == delim)
            {
                tokens.emplace_back(str.substr(p + 1, i - p - 1)); //(p,i)
                p = i;
            }
        }
        tokens.emplace_back(str.substr(p + 1));
    }

        TreeNode* dfs(vector<string> strs, vector<int> i){
        string str = strs[i[0]];
        i[0]++;
        if(str=="#") {
            return nullptr;
        }
        
        TreeNode* node = new TreeNode(stoi(str));
        node->left = dfs(strs, i);
        node->right = dfs(strs, i);

        return node;
    }

    TreeNode* deserializeTree(string data) {
        vector<string> strs;
        vector<string> nodeStrs;
        split(data,strs,'#');
        vector<int> i={0};
        return dfs(nodeStrs, i);
    }

    int sumDfs(TreeNode* root, int path) {
        if(root == nullptr){
            return 0;
        }
        path = path*10 + root->val;
        if(root->left == nullptr && root->right == nullptr){
            return path;
        }
        return sumDfs(root->left, path)+sumDfs(root->right, path);
    }

    int pathSumDfs(TreeNode* root, int targetSum){
        if(root == nullptr) {
            return 0;
        }
        int ret =0;
        if(targetSum - root->val == 0){
            ret++;
        }

        ret+=pathSumDfs(root->left, targetSum - root->val);
        ret+=pathSumDfs(root->right, targetSum - root->val);
        return ret;
    }

    int pathSum(TreeNode* root, int targetSum) {
        return pathSumDfs(root, targetSum) + pathSumDfs(root->left, targetSum)+pathSumDfs(root->right, targetSum);
    }

    int pathSumDfs1(TreeNode* root ,int sum, map<int,int> map, int path) {
        if(root == nullptr){
            return 0;
        }

        path+=root->val;
        int count = 0;
        if(map.count(path-sum)){
            count = map[path-sum];
        }
        map[path]++;
        count +=pathSumDfs1(root->left, sum,map,path);
        count +=pathSumDfs1(root->right, sum,map,path);
        map[path]--;
        return count;
    }

    int maxSumPath(TreeNode* root, int* maxSum){
        if(root == nullptr){
            return 0;
        }
        int l = max(0, maxSumPath(root->left, maxSum));
        int r =  max(0, maxSumPath(root->right, maxSum));
        *maxSum = max(*maxSum, l+r+root->val);
        return max(l+root->val, r+root->val);
    }
    
    int maxPathSum(TreeNode* node){
        int i = INT_MIN;
        int* maxSum = &i;
        maxSumPath(node, maxSum);
    }


    int sumNumbers(TreeNode* root){
        return sumDfs(root, 0);
    }

    BinaryTree::~BinaryTree()
    {
    }
    
};