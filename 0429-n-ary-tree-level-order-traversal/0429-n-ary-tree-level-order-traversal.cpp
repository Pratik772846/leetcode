/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    private:
    void bfs(Node* root,vector<vector<int>> &ans){
        if(root==NULL) return ;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            while(size--){
                auto it = q.front();
                q.pop();
                for(auto p:it->children){
                    q.push(p);
                }
                temp.push_back(it->val);
            }
            ans.push_back(temp);
        }
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        bfs(root,ans);
        return ans;
    }
};