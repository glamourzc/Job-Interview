### [301\. Remove Invalid Parentheses](https://leetcode.com/problems/remove-invalid-parentheses/description/)

Difficulty: **Hard**

**思路：DFS方法（python 实现）或者BFS（CPP）**
**如果存在m个invalid，那么肯定删除m个**

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses `(` and `)`.

**Examples:**  

```
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
```



#### Python Solution：深度优先搜索
```
class Solution:
    def removeInvalidParentheses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        def dfs(s,visited):
            m = cal(s) #删除的最多是m个，不会多于m个
            if m == 0:
                res.append(s)
            else:
                for i in range(len(s)):
                    if s[i] in '()':
                        new_str = s[:i] +s[i+1:]
                        if new_str not in visited and cal(new_str) < m:
                            visited.append(new_str)
                            dfs(new_str,visited)
                            
        def cal(s):
            a = b = 0
            for c in s:
                a += {'(':1,')':-1}.get(c,0) #返回指定键的值，如果值不在字典中返回default值
                b += a < 0
                a = max(a,0)
            return a+b
        
        res = []
        dfs(s,[])
        return res
```

## CPP Solution:可能实现的有点问题，运行")((())((())(((f)()("的时候很慢。BFS不是特别好。有一个判断是如果长度为m的时候是valid，那个m-1的时候一定不valid。
```
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		vector<string> queue;
		queue.push_back(s);
		bool done = false;
		while (!queue.empty()){
			string temp = queue[0];
			queue.erase(queue.begin());
			if (isValid(temp)){
				done = true;
				res.push_back(temp);
			}
			if (done) continue;
			for (int i = 0; i<temp.size(); i++){
				if (temp[i] != ')' && temp[i] != '(') continue;
				string temp2 = temp;
				string temp3 = temp2.erase(i, 1);
				if (find(queue.begin(), queue.end(), temp3) == queue.end())
					queue.push_back(temp3);//string.erase(pos,len)
			}
		}
		return res;
	}
	bool isValid(string s){
		int tag = 0;
		for (auto c : s){
			if (tag < 0)return false;
			if (c == '(')tag++;
			if (c == ')')tag--;
		}
		return tag == 0;
	}
};
```
