### [347\. Top K Frequent Elements](https://leetcode.com/problems/top-k-frequent-elements/description/)

Difficulty: **Medium**



Given a non-empty array of integers, return the **_k_** most frequent elements.

For example,  
Given `[1,1,1,2,2,3]` and k = 2, return `[1,2]`.

**Note:**  

*   You may assume _k_ is always valid, 1 ≤ _k_ ≤ number of unique elements.
*   Your algorithm's time complexity **must be** better than O(_n_ log _n_), where _n_ is the array's size.

**思路：**排了个序

#### Solution

Language: **C++**

```c++
class Solution {
public:
	static bool compare(pair<int, int> a, pair<int, int> b){
		return b.second < a.second;
	}
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> res;
		unordered_map<int, int> t;
		for (int i : nums){
			if (t[i] == 0){
				t[i] = 1;
			}
			else{
				t[i]++;
			}
		}
		vector<pair<int, int>> temp(t.begin(), t.end());
		sort(temp.begin(), temp.end(), compare);
		for (int i = 0; i < k; i++){
			res.push_back(temp[i].first);
		}
		/*
		make_heap(temp.begin(), temp.end(), compare);
		while (k--){
			pop_heap(temp.begin(), temp.end(),compare);
			res.push_back(temp.back().first);
			temp.pop_back();
		}*/
		return res;
	}
};
```

Language:**Python**
```python
class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        times = {}
        for i in nums:
            if times.__contains__(i):
                times[i] += 1
            else:
                times[i] = 1
        res = []
        #下面这样写有点傻
        for i in range(k):
            k = max(times,key = times.get)
            res.append(k)
            times[k] = 0
        return res
```
```python
class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        times = collections.defaultdict(int)
        for i in nums:
            times[i] += 1
        res  = [x[0] for x in sorted(times.items(),key=lambda x:x[1],reverse =True)]
        return res[0:k]
```
