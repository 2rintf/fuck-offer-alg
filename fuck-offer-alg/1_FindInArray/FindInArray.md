# 二维数组查找
**在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。**  

---

思考：
1. 左下角开始，若target大于数组值，右移；若小于，上移。呈Z字寻找。

---  
代码：  
```C
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int rows = array.size();
		int cols = array[0].size();

		for (int r = rows-1; r > -1; r--) {
			for (int c = 0; c < cols; c++) {
				int help = array[r][c];
				if (target > help) {
					continue;
				}
				else if (target < help) {
					break;
				}
				else if (target == help) {
					return true;
				}
				
			}
		}
		return false;
	}
};
```  
如果遍历每一行，使用二分法，复杂度为`nlogn`。