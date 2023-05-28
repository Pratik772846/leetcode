/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    void bfs(vector<vector<int>>&ans,TreeNode* root){
        if(root==NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                if(it->left!=NULL){
                    q.push(it->left);
                }
                if(it->right!=NULL){
                    q.push(it->right);
                }
                temp.push_back(it->val);
            }
            ans.push_back(temp);
        }
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        bfs(ans,root);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};