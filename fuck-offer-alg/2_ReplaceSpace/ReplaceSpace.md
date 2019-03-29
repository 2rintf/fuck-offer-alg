# 字符串替换空格  
**请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。**  
给出的函数`void replaceSpace(char *str, int length)`  
  
---  

思考:  
1. 理解题目中的length。此处假设，函数输入的length指的是str所指字符数组的length，不是指字符个数。
2. str的边界问题。塞入`%20`，其他字符必然要后移。
3. 遍历问题。遍历时怎么移字符更高效?--> 从后面开始遍历，这样遇到空格往后移动字符时，总次数少于从前面遍历时的情况。

---
代码：  
①正常解答  
```C
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int spaceNum = 0;
		int charNum = 0;
		int newLength;
		int moveSteps;

		// 先遍历，计算空格数和字符数
		for (int i = 0; i < length; i++)
		{
			if (*(str+i)==' ')
			{
				spaceNum++;
			}
			if (*(str + i) == '\0')
			{
				continue;
			}

			charNum++;
		}

		newLength = charNum + 2 * spaceNum;// 替换字符后的字符串长度
		moveSteps = 2 * spaceNum;// 初始字符移动位数

		// 防止超出原字符串大小，溢出
		if (newLength>length)
		{
			cout << "over" << endl;
			return;
		}

		for (int i = length-1; i > -1; i-- )
		{
			// 替换字符
			if (str[i]==' ')
			{
				str[i + moveSteps - 2] = '%';
				str[i + moveSteps - 1] = '2';
				str[i + moveSteps] = '0';
				
				moveSteps -= 2;
			}
			// 不动’\0‘可以防止溢出
			else if (str[i] == '\0') 
			{
				continue;
			}
			// 移动非空格字符
			else
			{
				str[i + moveSteps] = str[i];
			}
		}

	}
};
```
②使用标准库`std::string`的特性  
```C

```