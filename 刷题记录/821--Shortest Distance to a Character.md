### [821\. Shortest Distance to a Character](https://leetcode.com/problems/shortest-distance-to-a-character/description/)

Difficulty: **Easy**



Given a string `S` and a character `C`, return an array of integers representing the shortest distance from the character `C` in the string.

**Example 1:**

```
**Input:** S = "loveleetcode", C = 'e'
**Output:** [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
```

**Note:**

1.  `S` string length is in `[1, 10000].`
2.  `C` is a single character, and guaranteed to be in string `S`.
3.  All letters in `S` and `C` are lowercase.

**思路：**
只需要一个循环，设置tag记录不为`C`的字母的数量，直到遇到`C`。对于头和尾特殊处理，对于两个`C`之间，需要类似回文的输出。

#### Solution

Language: **C++**

```c++
class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		vector<int> res;
		int tag = 0;
		for (int i = 0; i<S.size(); i++){
			if (S[i] != C){
				tag++;
			}
			else{
				if (tag > 0){
					if (res.empty()){
						while (tag)res.push_back(tag--);
					}
					else{
						int mid = ceil(tag / 2.0);
						for (int i = 1; i <= tag; i++)res.push_back(i <= mid ? i : tag - i + 1);
					}
					tag = 0;
				}
				res.push_back(0);
			}
		}
		for (int i = 1; i <= tag; i++)res.push_back(i);
		return res;
	}
};
```

网上更多的一种做法，通过来回两趟，更新距离。
```c++
class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		vector<int> res;
		int pos = -(int)S.size();
		for (int i = 0; i < S.size(); i++){
			if (S[i] == C)pos = i;
			res.push_back(abs(i - pos));
		}
		for (int i = S.size()-1; i >= 0; i--){
			if (S[i] == C)pos = i;
			res[i] = min(res[i],abs(i - pos));
		}
		return res;
	}
};
```

Lauguage:**Python**
```python
class Solution:
    def shortestToChar(self, S, C):
        """
        :type S: str
        :type C: str
        :rtype: List[int]
        """
        res=[]
        tag = 0
        for i in range(len(S)):
            if S[i] != C:
                tag+=1
            else:
                if tag>0:
                    if len(res)==0:
                        res+=range(tag,0,-1)
                    else:
                        mid = math.ceil(tag/2)
                        res+=[(i<=mid and i or tag-i+1) for i in range(1,tag+1)]
                    tag = 0
                res.append(0)
        if(tag):
            res+=range(1,tag+1)
        return res
```