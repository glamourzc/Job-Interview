### [2\. Add Two Numbers](https://leetcode.com/problems/add-two-numbers/description/)



Difficulty: **Medium**



You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.



You may assume the two numbers do not contain any leading zero, except the number 0 itself.



**Input:** (2 -> 4 -> 3) + (5 -> 6 -> 4)  

**Output:** 7 -> 0 -> 8



#### My Solution

```

/**

 * Definition for singly-linked list.

 * struct ListNode {

 *     int val;

 *     ListNode *next;

 *     ListNode(int x) : val(x), next(NULL) {}

 * };

 */

class Solution {

public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* HEAD;

        ListNode* p=new ListNode(0);

        HEAD=p;

        int tag=0,rem;

        while(l1!=NULL&&l2!=NULL){

            rem=(l1->val+l2->val+tag)%10;

            tag=(l1->val+l2->val+tag)/10;

            ListNode* temp=new ListNode(rem);

            l1=l1->next;

            l2=l2->next;

            p->next=temp;

            p=p->next;

            

        }

        while(l1!=NULL){

            rem=(l1->val+tag)%10;

            tag=(l1->val+tag)/10;

            ListNode* temp=new ListNode(rem);

            l1=l1->next;

            p->next=temp;

            p=p->next;

        }

        while(l2!=NULL){

            rem=(l2->val+tag)%10;

            tag=(l2->val+tag)/10;

            ListNode* temp=new ListNode(rem);

            l2=l2->next;

            p->next=temp;

            p=p->next;

        }

        if(tag==1){

            ListNode* temp=new ListNode(1);

            p->next=temp;

        }

        return HEAD->next;

    }

};

```
