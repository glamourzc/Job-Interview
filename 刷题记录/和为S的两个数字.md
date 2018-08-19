## 题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数字，使得他们的和正好是S,吐过有多对数字的和等于S，输出两个数的乘积最小的。

输出描述
> 对应每个测试案例，输出两个数，小的先输出

## Solution
> 从两端开始找，找到的第一组一定是成绩最小的。因为和相同的情况下，差越答的两个数的乘积越小。

```c++
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		vector<int> res;
		if (array.size() <= 2)return res;
		int low = 0, high = array.size() - 1;
		while (high > low){
			while (high > low && array[high] + array[low] > sum){
				high--;
			}
			while (high > low && array[high] + array[low] < sum){
				low++;
			}
			if (array[high] + array[low] == sum)break;
		}
		if (low == high)return res;
		res.push_back(array[low]);
		res.push_back(array[high]);
		return res;
	}
};
```
