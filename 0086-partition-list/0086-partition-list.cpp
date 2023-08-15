/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void append(ListNode** head_ref, int new_data)
{
    ListNode* new_node = new ListNode();
    new_node->val = new_data;

    ListNode* last = *head_ref;
 
    new_node->next = NULL;
 
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
 
    while (last->next != NULL) {
        last = last->next;
    }
 
    last->next = new_node;
}
    ListNode* partition(ListNode* head, int x) {
        vector<int> arr;
        vector<int> arr1;
        while(head!=NULL){
            auto it = head->val;
            if(it<x){
                arr.push_back(it);
            }
            else{
                arr1.push_back(it);
            }
            head = head->next;
        }
        ListNode* ans = NULL;
        for(auto it:arr){
            append(&ans,it);
        }
        for(auto it:arr1){
            append(&ans,it);
        }
        return ans;
        
    }
};