/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


#include<stdlib.h>
#include<stdio.h>


void ShowList(struct ListNode* L);

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {

    int s[5000] = { 0 };
    int i = 0;
    struct ListNode* p = head;
    if (p == NULL)
    {
        return head;
    }

    while (p != NULL)
    {
        s[i++] = p->val;
        p = p->next;
    }

    p = head;
   /* printf("i=%d\n", i);
    printf("s=");
    for (int j = 6;j > 0;)
    {
        printf("%d ", s[--j]);
    }*/
    ShowList(head);

    while (i > 0)
    {
        p->val = s[--i];
        p = p->next;
    }
    ShowList(head);
    return head;
    
}

struct ListNode* CreateList(struct ListNode* L)
{
    int i = 0;
    struct ListNode* p = L;
    struct ListNode* t = L;
    for (i = 0; i < 5; i++)
    {
        p = (struct ListNode*)malloc(sizeof(struct ListNode));
        p->val = i + 1;
        p->next = NULL;
        t->next = p;
        t = t->next;
    }
    return L;
}

void ShowList(struct ListNode* L)
{
    int i = 0;
    struct ListNode* p = L;
    while (p != NULL)
    {
        printf("%d ", p->val);
        p = p->next;
    }
    printf("\n");
}
struct ListNode* Test(struct ListNode* L)
{
    struct ListNode* p = L;
    p->val = 1000;
    return L;
}

int main()
{
    struct ListNode a = {0};
    struct ListNode* L = &a;
    L = CreateList(L);
    struct ListNode* ret=reverseList(L);
    struct ListNode* temp = Test(L);
    ShowList(L);
    ShowList(ret);
    return 0;
}