void inorder(TreeNode * root,vector<int>&temp)
{
    if(!root) return;
    inorder(root->left,temp);
    temp.push_back(root->val);
    inorder(root->right,temp);
}

TreeNode * cons( vector<int>&temp ,int l ,int h)
{
    if(l>h) return nullptr;
    int mid = (l+h)/2;
    TreeNode * root = new TreeNode(temp[mid]);
    root->left = cons(temp,l,mid-1);
    root->right = cons(temp,mid+1,h);
    return root;
}
class Solution {
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>temp;
        inorder(root,temp);
        return cons(temp,0,temp.size()-1);
    }
};