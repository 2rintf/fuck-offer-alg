# 字符串替换空格  
**请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。**  
给出的函数`void replaceSpace(char *str, int length)`  
  
---  

思考:  
1. 理解题目中的length。此处假设，函数输入的length指的是str所指字符数组的length，不是指字符个数。
2. str的边界问题。塞入`%20`，其他字符必然要后移。
3. 遍历问题。遍历时怎么移字符更高效?--> 从后面开始遍历，这样遇到空格往后移动字符时，总次数少于从前面遍历时的情况。  
4. 使用标准库`<string>`应该如何实现？

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
②使用标准库`<string>`的特性。[[代码参考]：free2ing的回复](https://www.nowcoder.com/questionTerminal/4060ac7e3e404ad1a894ef3e17650423)  
- `std::basic_string::find`  
四个重载。第一个input一般是指搜索的字符或字符串，第二个input指的是指针偏移量pos，即`find`从pos位置开始搜索字符。output是第一个搜索到的字符的位置，若无匹配，则返回`string::basic_string::npos`（此值强制转换为`int`后为**-1**）。


	|  类型   |     |
	| --- | --- |
	|  string   |  size_type find (const basic_string& str, size_type pos = 0) const noexcept;   |
	|  c-string   |  size_type find (const charT* s, size_type pos = 0) const;   |
	|  buffer   |  size_type find (const charT* s, size_type pos, size_type n) const;   |
	|  char   |  size_type find (charT c, size_type pos = 0) const noexcept;   |  
- `std::basic_string::erase`  
第一个input是位置pos，第二个input是删除字符个数len。或者是直接给开头first和结尾last，在`[first,last)`  此范围内删除。

	|  类型   |     |
	| --- | --- |
	|  sequence   |  basic_string& erase (size_type pos = 0, size_type len = npos);   |
	|  char   |  iterator erase (const_iterator p);   |
	|  range   | iterator erase (const_iterator first, const_iterator last);   |
	
- `std::basic_string::insert`   
对于string，第一个input是插入位置pos，第二个input是插入的字符or字符串。还有一个substring的重载可以指定某字符串的其中一部分插入到欲插入字符串。  

	|  类型   |     |
	| --- | --- |
	|  string   |  basic_string& insert (size_type pos, const basic_string& str);  |
	|  substring   |  basic_string& insert (size_type pos, const basic_string& str,size_type subpos, size_type sublen);   |

```C
class Solution2 {
public:
	void replaceSpace(char *str, int length) {
		string s(str);// char数组指针转string
		int i = 0;
		while ((i = s.find(' ', i)) > -1) {
			s.erase(i, 1);
			s.insert(i, "%20");
		}
		auto ret = s.c_str();
		strcpy(str, ret);
	}
};
```