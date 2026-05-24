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
private:
ListNode* rever(ListNode* head){
    ListNode *prev = NULL, *next = head ;
    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
public:
    void reorderList(ListNode* head) {
        ListNode* oldhead = head;
        ListNode* ansnode = oldhead;
        if(!head or !head->next or !head->next->next){
            return ;
        }
        ListNode* fast = head , *slow =head , *prev;
        while(fast and fast->next and slow){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;
            
        }
        ListNode* half = prev->next;
        if(fast == NULL){
            half = prev->next;
            prev->next = NULL;
        }else{
            half = slow->next;
            slow->next= NULL;
        }
        ListNode* midhead = rever(half);

        while(midhead && oldhead ){
            ListNode* midnext = midhead->next;
            ListNode* oldnext = oldhead->next;
            oldhead->next = midhead;
            midhead->next = oldnext;
            oldhead = oldnext;
            midhead = midnext;
        }
    }
};

//         f
// 2,4,6,8
//     s
//   p



//         f
// 2,4,6,8,1
//     s
//   p