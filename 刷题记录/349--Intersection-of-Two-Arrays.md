### [349\. Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/description/)

Difficulty: **Easy**



Given two arrays, write a function to compute their intersection.

**Example:**  
Given _nums1_ = `[1, 2, 2, 1]`, _nums2_ = `[2, 2]`, return `[2]`.

**Note:**  

*   Each element in the result must be unique.
*   The result can be in any order.



#### Solution
##### c++1:常规做法。
```
class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res{};
        auto i = nums1.begin();
        auto j = nums2.begin();
        while (i != nums1.end() && j != nums2.end()){
            if (*i == *j && (res.empty() || res.back() != *i))res.push_back(*i);
            if (*i < *j){++i; continue;}
            if (*i > *j){++j; continue;}
            ++i; ++j;
        }
        return res;
    }
};
```
##### c++2:直接转换成set做。使用set_intersection
```
class Solution{
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> set1(nums1.begin(), nums1.end());
		set<int> set2(nums2.begin(), nums2.end());
		vector<int> res(nums1.size() + nums2.size());
		auto it = set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), res.begin());
		res.resize(it - res.begin());
		return res;
	}
};
```
##### python:一句话
```
class Solution:
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        return list(set(nums1) & set(nums2))
```  
