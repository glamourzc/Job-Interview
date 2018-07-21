### [451\. Sort Characters By Frequency](https://leetcode.com/problems/sort-characters-by-frequency/description/)

Difficulty: **Medium**



Given a string, sort it in decreasing order based on the frequency of characters.

**Example 1:**

```
**Input:**
"tree"

**Output:**
"eert"

**Explanation:**
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
```

**Example 2:**

```
**Input:**
"cccaaa"

**Output:**
"cccaaa"

**Explanation:**
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
```

**Example 3:**

```
**Input:**
"Aabb"

**Output:**
"bbAa"

**Explanation:**
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
```



#### Solution
##### c++1：
```
class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int, char>> p;
        unordered_map<char, int> m;
        for (auto c : s)++m[c];
        string res = "";
        for (auto e : m){
            p.push(make_pair(e.second, e.first));
        }
        while (!p.empty()){
            for (int i = 0; i < p.top().first; i++){
                res+=p.top().second;
            }
            //可以直接使用append函数
            //res.append(p.top().first, p.top().second);
            p.pop();
        }
        return res;
    }
};
```
##### c++2：使用匿名函数实现sort函数的比较方法。
```
class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> m;
		for (auto c : s)++m[c];
		sort(s.begin(), s.end(), [&](char a,char b){
			return m[a] > m[b] || (m[a] == m[b] && a < b);
		});
		return s;
	}
};
```

##### python：python简直是太方便了
```python
class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        t = collections.Counter(s).most_common()
        res = ''
        for c,n in t:
            res += c * n
        return res
```
##### python2:
```
class Solution:
    def frequencySort(self, s):
        """
        :type s: str
        :rtype: str
        """
        dic = {}
        for c in s:
            if c in dic:
                dic[c]+=1
            else:
                dic[c]=1
        #下面这两种都是可以的
        #newdic = sorted(zip(dic.values(),dic.keys()),reverse=True)
        newdic = sorted(dic.items(),key = lambda x:x[1],reverse=True)
        res = ''
        for c,n in newdic:
            res += c * n
        return res
```
