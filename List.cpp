
//Á¦¿ÛËã·¨




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {

    int count = 0;
    int i = 0;
    struct ListNode* p = head;
    for (i = 0; p != NULL; i++)
    {
        p = p->next;
    }
    count = i;
    int pre = count - n;
    if (pre == 0)
    {
        return head->next;
    }
    p = head;
    for (i = 0; i < pre - 1; i++)
    {
        p = p->next;
    }

    p->next = p->next->next;

    return head;

}