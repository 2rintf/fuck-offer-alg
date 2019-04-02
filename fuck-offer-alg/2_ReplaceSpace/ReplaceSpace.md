# �ַ����滻�ո�  
**��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20�������磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��**  
�����ĺ���`void replaceSpace(char *str, int length)`  
  
---  

˼��:  
1. �����Ŀ�е�length���˴����裬���������lengthָ����str��ָ�ַ������length������ָ�ַ�������
2. str�ı߽����⡣����`%20`�������ַ���ȻҪ���ơ�
3. �������⡣����ʱ��ô���ַ�����Ч?--> �Ӻ��濪ʼ���������������ո������ƶ��ַ�ʱ���ܴ������ڴ�ǰ�����ʱ�������  
4. ʹ�ñ�׼��`<string>`Ӧ�����ʵ�֣�

---
���룺  
���������  
```C
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int spaceNum = 0;
		int charNum = 0;
		int newLength;
		int moveSteps;

		// �ȱ���������ո������ַ���
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

		newLength = charNum + 2 * spaceNum;// �滻�ַ�����ַ�������
		moveSteps = 2 * spaceNum;// ��ʼ�ַ��ƶ�λ��

		// ��ֹ����ԭ�ַ�����С�����
		if (newLength>length)
		{
			cout << "over" << endl;
			return;
		}

		for (int i = length-1; i > -1; i-- )
		{
			// �滻�ַ�
			if (str[i]==' ')
			{
				str[i + moveSteps - 2] = '%';
				str[i + moveSteps - 1] = '2';
				str[i + moveSteps] = '0';
				
				moveSteps -= 2;
			}
			// ������\0�����Է�ֹ���
			else if (str[i] == '\0') 
			{
				continue;
			}
			// �ƶ��ǿո��ַ�
			else
			{
				str[i + moveSteps] = str[i];
			}
		}

	}
};
```
��ʹ�ñ�׼��`<string>`�����ԡ�[[����ο�]��free2ing�Ļظ�](https://www.nowcoder.com/questionTerminal/4060ac7e3e404ad1a894ef3e17650423)  
- `std::basic_string::find`  
�ĸ����ء���һ��inputһ����ָ�������ַ����ַ������ڶ���inputָ����ָ��ƫ����pos����`find`��posλ�ÿ�ʼ�����ַ���output�ǵ�һ�����������ַ���λ�ã�����ƥ�䣬�򷵻�`string::basic_string::npos`����ֵǿ��ת��Ϊ`int`��Ϊ**-1**����


	|  ����   |     |
	| --- | --- |
	|  string   |  size_type find (const basic_string& str, size_type pos = 0) const noexcept;   |
	|  c-string   |  size_type find (const charT* s, size_type pos = 0) const;   |
	|  buffer   |  size_type find (const charT* s, size_type pos, size_type n) const;   |
	|  char   |  size_type find (charT c, size_type pos = 0) const noexcept;   |  
- `std::basic_string::erase`  
��һ��input��λ��pos���ڶ���input��ɾ���ַ�����len��������ֱ�Ӹ���ͷfirst�ͽ�βlast����`[first,last)`  �˷�Χ��ɾ����

	|  ����   |     |
	| --- | --- |
	|  sequence   |  basic_string& erase (size_type pos = 0, size_type len = npos);   |
	|  char   |  iterator erase (const_iterator p);   |
	|  range   | iterator erase (const_iterator first, const_iterator last);   |
	
- `std::basic_string::insert`   
����string����һ��input�ǲ���λ��pos���ڶ���input�ǲ�����ַ�or�ַ���������һ��substring�����ؿ���ָ��ĳ�ַ���������һ���ֲ��뵽�������ַ�����  

	|  ����   |     |
	| --- | --- |
	|  string   |  basic_string& insert (size_type pos, const basic_string& str);  |
	|  substring   |  basic_string& insert (size_type pos, const basic_string& str,size_type subpos, size_type sublen);   |

```C
class Solution2 {
public:
	void replaceSpace(char *str, int length) {
		string s(str);// char����ָ��תstring
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