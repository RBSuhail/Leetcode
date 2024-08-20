class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head; 

      
        ListNode* temp = head;
        int cnt = 1; 
        while (temp->next) {
            temp = temp->next;
            cnt++;
        }
        temp->next = head;

  
        k = k % cnt; 
        int l = cnt - k;
        temp = head;
        for (int i = 0; i < l - 1; i++) {
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;

        return newHead;
    }
};
