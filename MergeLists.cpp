
//Á¦¿ÛËã·¨Ìâ



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    struct ListNode* p1 = list1;
    struct ListNode* p2 = list2;
    struct ListNode* pc = (struct ListNode*)malloc(sizeof(struct ListNode));
    pc->next = NULL;
    struct ListNode* final = pc;

    if (p1 == NULL)
    {
        return p2;
    }
    if (p2 == NULL)
    {
        return p1;
    }
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->val < p2->val)
        {
            pc->next = p1;
            pc = pc->next;
            p1 = p1->next;
        }
        else
        {
            pc->next = p2;
            pc = pc->next;
            p2 = p2->next;
        }
    }
    pc->next = p1 == NULL ? p2 : p1;
    //if(pc->next==p1)
    //{
    //    pc->next=p2;
    //}
    //else 
    //{
    //    pc->next=p1;
    //}
    return final->next;
}