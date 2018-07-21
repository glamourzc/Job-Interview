**题目描述**
定义栈的数据结构，请在该类型中实现一个能够得到栈最小元素的min函数
**Solution**
用容器很好实现。但是min函数觉得每次都遍历还是比较傻的。
```c++
// vector
class Solution {
public:
    vector<int> myStack;
    void push(int value) {
        myStack.insert(myStack.begin(),value);
    }
    void pop() {
        if(!myStack.empty())
        {
            myStack.erase(myStack.begin(),myStack.begin()+1);
        }
    }
    int top() {
        return myStack[0];
    }
    int min() {
        int res=myStack[0];
        for(auto i:myStack){
            res = res < i ? res : i;
        }
        return res;
    }
};
```

```c++
// deque
class Solution {
public:
    deque<int> myStack;
    void push(int value) {
        myStack.push_front(value);
    }
    void pop() {
        myStack.pop_front();
    }
    int top() {
        return myStack[0];
    }
    int min() {
        int res=myStack[0];
        for(auto i:myStack){
            res = res < i ? res : i;
        }
        return res;
    }
};
```
