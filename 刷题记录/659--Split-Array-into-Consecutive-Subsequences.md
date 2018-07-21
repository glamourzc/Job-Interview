### [659\. Split Array into Consecutive Subsequences](https://leetcode.com/problems/split-array-into-consecutive-subsequences/description/)

Difficulty: **Medium**



You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.

**Example 1:**  

```
**Input:** [1,2,3,3,4,5]
**Output:** True
**Explanation:**
You can split them into two consecutive subsequences : 
1, 2, 3
3, 4, 5
```

**Example 2:**  

```
**Input:** [1,2,3,3,4,4,5,5]
**Output:** True
**Explanation:**
You can split them into two consecutive subsequences : 
1, 2, 3, 4, 5
3, 4, 5
```

**Example 3:**  

```
**Input:** [1,2,3,4,4,5]
**Output:** False
```

**Note:**  

1.  The length of the input is in range of [1, 10000]



#### Solution

Language: **C++**

```c++
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        if (nums.size() <3)return false;
        unordered_map<int, int> times;
        for (int k : nums){
            if (times[k] == 0){
                times[k] = 1;
            }
            else{
                times[k]++;
            }
        }
        vector<vector<int> > queues;
        int cur = nums[0];
        for (int k : nums){
            if (times[k] > 0){
                int n = times[k];
                times[k] = 0;
                
                for (int i = queues.size() - 1; i >= 0; i--){
                    if (queues[i].back() == k - 1 && n>0){
                        queues[i].push_back(k);
                        n--;
                    }
                    else{ break; }
                }
                while (n--){
                    vector<int>temp = { k };
                    queues.push_back(temp);
                }
            }
        }
        for (auto k : queues){
            if (k.size()<3)return false;
        }
        return true;
    }
};
```

Language:**Python**
```python
class Solution:
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 3:
            return False
        
        times = {}
        for i in nums:
            if times.__contains__(i):#现在没有has_key了，用的是__contains__
                times[i] +=1
            else:
                times[i] =1
        
        '''
        times = collections.defaultdict(int)
        #这里的defaultdict(function_factory)构建的是一个类似dictionary的对象，其中keys的值，自行确定赋值，但是values的类型，是function_factory的类实例，而且具有默认值。比如default(int)则创建一个类似dictionary对象，里面任何的values都是int的实例，而且就算是一个不存在的key, d[key] 也有一个默认值，这个默认值是int()的默认值0.
        for i in nums:
            times[i]+=1
        '''
        queues = []
        for j in nums:
            if times[j]>0:
                n = times[j]
                times[j] = 0
                for k in range(len(queues),0,-1):
                    if(queues[k-1][-1] == j-1 and n>0):
                        queues[k-1].append(j)
                        n = n-1
                    else:
                        break
                for m in range(n):
                    queues.append([j])
        for i in queues:
            if len(i) <3:
                return False
        return True
```
