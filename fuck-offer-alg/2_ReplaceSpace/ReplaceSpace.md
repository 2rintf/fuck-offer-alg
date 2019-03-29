# 字符串替换空格  
**请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。**  
给出的函数`void replaceSpace(char *str, int length) `  
  
---  

思考:  
1. 理解题目中的length。此处假设，函数输入的length指的是str所指字符数组的length，不是指字符个数。
2. str的边界问题。塞入`%20`，其他字符必然要后移。
3. 遍历问题。