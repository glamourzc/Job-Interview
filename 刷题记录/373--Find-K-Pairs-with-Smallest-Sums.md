### [373\. Find K Pairs with Smallest Sums](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/)

Difficulty: **Medium**
**主要体会了一下c++中sort的用法，该解法速度很慢**



You are given two integer arrays **nums1** and **nums2** sorted in ascending order and an integer **k**.

Define a pair **(u,v)** which consists of one element from the first array and one element from the second array.

Find the k pairs **(u<sub style="display: inline;">1</sub>,v<sub style="display: inline;">1</sub>),(u<sub style="display: inline;">2</sub>,v<sub style="display: inline;">2</sub>) ...(u<sub style="display: inline;">k</sub>,v<sub style="display: inline;">k</sub>)** with the smallest sums.

**Example 1:**  

```
Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3

Return: [1,2],[1,4],[1,6]

The first 3 pairs are returned from the sequence:
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
```

**Example 2:**  

```
Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2

Return: [1,1],[1,1]

The first 2 pairs are returned from the sequence:
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
```

**Example 3:**  

```
Given nums1 = [1,2], nums2 = [3],  k = 3 

Return: [1,3],[2,3]

All possible pairs are returned from the sequence:
[1,3],[2,3]
```



#### Solution
```
typedef pair<int, int> p;
bool com(p p1, p p2){
    return (p1.first + p1.second < p2.first + p2.second);
}
​
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<p> res;
        for (auto i : nums1){
            for (auto j : nums2){
                res.push_back({i,j});
            }
        }
        sort(res.begin(), res.end(),com);
        if (res.size() > k) res.erase(res.begin() + k, res.end());
        return res;
    }
};
```
