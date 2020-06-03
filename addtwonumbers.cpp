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

auto speedUp=[](){
    std::ios::sync_with_stdio(nullptr);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL) 
            return l2;
        if(l2==NULL)
            return l1;
        int sum=l1->val+l2->val;
        ListNode* l3;
        l3=new ListNode(0);
        
        l3->next=addTwoNumbers(l1->next,l2->next);
        if(sum<=9)l3->val=sum;
        else{
            l3->val=sum-10;
            ListNode* dummy;
            dummy=new ListNode(1);
            l3->next=addTwoNumbers(dummy,l3->next);
            
            
            
        }
        return l3;
        
    }
};