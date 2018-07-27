## 题目描述
输入一个链表，输出该链表中倒数第k个结点。

## Solution
> 遍历一次找出节点个数，然后将倒数转换为正数

```c++
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead == NULL || k < 1)
          return NULL;
        ListNode* p = pListHead;
        int num = 0;
        while(p!=NULL){
            num++;
            p = p->next;
        }
        if(k > num)return NULL;
        num = num - k;
        p = pListHead;
        while(num --){
            p = p->next;
        }
        return p;
    }
};
```
> python还是比较方便的，直接放在list中

```python
class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        l = []
        while head != None:
            l.append(head)
            head = head.next
        if len(l) < k or k <=0:
            return
        return l[-k]
```
